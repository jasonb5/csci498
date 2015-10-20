#include <stack>
#include <stdio.h>

#include "huffman.h"

void Huffman::generate_tree(std::vector<int> *samples) {
    for (int i = 0; i < samples->size(); ++i) {
        if ((*samples)[i] == 0) continue;

        Node *node = new Node();

        node->code = new std::string();

        node->value = i;

        node->weight = (*samples)[i];

        queue_.push(node);
    }

    Node *n1, *n2, *temp;

    while (queue_.size() > 1) {
        n1 = queue_.top();

        queue_.pop();

        n2 = queue_.top();

        queue_.pop();

        temp = new Node();

        temp->weight = n1->weight + n2->weight;

        if (n1->weight > n2->weight) {
            temp->left = n2;
            temp->right = n1;
        } else {
            temp->left = n1;
            temp->right = n2;
        }

        temp->code = new std::string();

        queue_.push(temp);
    }
}

void Huffman::print_codes() {
    Node *node;
    std::stack<Node*> rstack;
    std::vector<std::string*> result(26, NULL);

    node = queue_.top();

    rstack.push(node);

    while (!rstack.empty()) {
        node = rstack.top();

        rstack.pop();

        if (node->left == 0 and node->right == 0) {
            result[node->value] = node->code;
        } else {
            (*node->left->code) += (*node->code) + '0';

            rstack.push(node->left);

            (*node->right->code) += (*node->code) + '1';

            rstack.push(node->right);
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (result[i] == NULL) continue;

        printf("%c\t%s\n", 'A'+i, result[i]->c_str());
    }
}
