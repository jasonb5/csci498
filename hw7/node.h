#ifndef HW7__NODE_H_
#define HW7__NODE_H_

#include <string>

struct Node {
    int weight;
    char value;
    std::string *code;
    struct Node *left;
    struct Node *right;
};

#endif // HW7__NODE_H_
