#include <vector>
#include <fstream>

#include "huffman.h"

int main(int argc, char **argv) {
    char c;
    std::ifstream ifs(argv[1], std::ifstream::in);
    std::vector<int> *samples = new std::vector<int>(26, 0);

    while (ifs.good()) {
        c = ifs.get();

        (*samples)[c-'A']++;
    }

    ifs.close();

    Huffman huff;

    huff.generate_tree(samples);

    huff.print_codes();

    return 0;
}
