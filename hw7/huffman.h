#ifndef HW7__HUFFMAN_H_
#define HW7__HUFFMAN_H_

#include <queue>
#include <string>
#include <vector>

#include "node.h"

class NodeComp {
 public:
    bool operator() (const Node *lhs, const Node *rhs) const {
        return lhs->weight > rhs->weight;
    }
};

class Huffman {
 public:
    void generate_tree(std::vector<int> *samples);
    void print_codes();

 private:
    std::priority_queue<Node*, std::vector<Node*>, NodeComp> queue_;
};

#endif // HW7__HUFFMAN_H_
