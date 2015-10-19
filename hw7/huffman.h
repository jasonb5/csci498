#ifndef HW7__HUFFMAN_H_
#define HW7__HUFFMAN_H_

#include <queue>
#include <vector>

#include "node.h"

class Huffman {
 public:
    void generate_tree(std::vector<int> *samples);

 private:
    std::priority_queue<struct Node*> queue_;
};

#endif // HW7__HUFFMAN_H_
