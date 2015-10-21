#ifndef HW7__HUFFMAN_H_
#define HW7__HUFFMAN_H_

#include <queue>
#include <string>
#include <vector>

#include "node.h"

// Compares the weights of two nodes.
//
// Should be used with a std::priority_queue during declaration.
// std::priority_queue<Node*, std::vector<Node*>, NodeComp>
class NodeComp {
 public:
    bool operator() (const Node *lhs, const Node *rhs) const {
        return lhs->weight > rhs->weight;
    }
};

// Implements simple huffman coding for string containing letters
// between A-Z.
//
// https://en.wikipedia.org/wiki/Huffman_coding
class Huffman {
 public:
    // Generates a huffman tree from a frequency map.
    //
    // samples should be an array of frequencies.
    void generate_tree(std::vector<int> *samples);
    // Prints the codewords from the huffman tree.
    void print_codes();

 private:
    // Priority queue used to generate huffman tree
    std::priority_queue<Node*, std::vector<Node*>, NodeComp> queue_;
};

#endif // HW7__HUFFMAN_H_
