#ifndef PROJECT_SUFFIX_H_
#define PROJECT_SUFFIX_H_

#include <string>
#include <vector>

struct Node {
  int start;
  int depth;
  Node *parent;
  std::vector<Node*> children;
};

class SuffixTree {
 public:
  SuffixTree(char *str);
  ~SuffixTree();

  int Child(Node *n, char c);

  void PrintTree();
  void BuildTree();

 private:
  Node *root_;
  std::string str_;
};

#endif // PROJECT_SUFFIX_H_
