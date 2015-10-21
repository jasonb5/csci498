#ifndef HW7__NODE_H_
#define HW7__NODE_H_

#include <string>

// Node for huffman tree
struct Node {
    // Weight of node, frequency
    int weight;
    // Frequency index
    char value;
    // Codeword
    std::string *code;
    // Left child
    struct Node *left;
    // Right child
    struct Node *right;
};

#endif // HW7__NODE_H_
