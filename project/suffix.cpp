#include "suffix.h"

#include <stack>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#ifdef DEBUG
#define dprintf(fmt, ...) fprintf(stdout, "[%s:%d] " fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__)
#else
#define dprintf(fmt, ...)
#endif

SuffixTree::SuffixTree(char *str)
  : root_(NULL),
    str_(str) {

  }

SuffixTree::~SuffixTree() {

}

int SuffixTree::Child(Node *n, char c) {
  int x;
  Node *child;

  for (x = 0; x < n->children.size(); ++x) {
    child = n->children[x];

    if (str_[child->start] == c) {
      return x;
    }
  }

  return -1;
}

void SuffixTree::PrintTree() {
  /**int i;
  Node *u;
  std::stack<Node*> stack;

  stack.push(root_);

  while (!stack.empty()) {
    u = stack.top();

    stack.pop();

    if (u != root_) {
      fprintf(stdout, "%s %d\n", str_.substr(u->start, u->depth).c_str(), u->children.size());
    }

    for (i = u->children.size() - 1; i >= 0; --i) {
      stack.push(u->children[i]);
    }
  }**/

  int i;
  int indent;
  Node *n, *c;
  std::queue<Node*> queue;

  indent = 0;

  queue.push(root_);

  while (!queue.empty()) {
    n = queue.front();

    queue.pop();

    if (n->children.size() == 0) {
      fprintf(stdout, "%s\n", str_.substr(n->start, n->depth).c_str());
    }

    for (i = 0; i < n->children.size(); ++i) {
      c = n->children[i];

      queue.push(c);
    }

    indent += 2;
  }
}

void SuffixTree::BuildTree() {
  int i, x, d, cindex, len;
  Node *u, *n, *p;

  len = str_.length();

  root_ = new Node();
  root_->start = 0;
  root_->depth = 0;

  for (i = 0; i < len; ++i) {
    u = root_;
    d = 0;

    dprintf("Suffix %s", str_.substr(i, len - i).c_str());

    while (true) {
      cindex = Child(u, str_[i + d]);

      if (cindex == -1) {
        break;
      }

      u = u->children[cindex];

      for (x = 0; x < u->depth; ++x, ++d) {
        if (str_[u->start+x] != str_[i+d]) {
          break;
        }
      } 

      if (d < u->depth) {
        break;
      }
    }

    if (d < u->depth) {
      p = u->parent;

      dprintf("Breaking path %s", str_.substr(u->start, u->depth).c_str());

      n = new Node();
      n->start = u->start;
      n->depth = d - p->depth;
      n->parent = p;
      n->children.push_back(u);

      std::swap(p->children[cindex], p->children.back());
      p->children.pop_back();
      p->children.push_back(n);

      u->parent = n;
      u->start += d - p->depth;
      u->depth = len - u->start;

      dprintf("first path %s start %d depth %d", str_.substr(n->start, n->depth).c_str(), n->start, n->depth);
      dprintf("second path %s start %d depth %d", str_.substr(u->start, u->depth).c_str(), u->start, u->depth);

      u = n;
    }

    n = new Node();
    n->start = i + d;
    n->depth = len - i - d;
    n->parent = u;
    u->children.push_back(n);

    dprintf("Adding leaf %s", str_.substr(n->start, n->depth).c_str());
  }
}
