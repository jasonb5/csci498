#include "suffix.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "First argument needs to be a string\n");
  
    exit(0);
  }

  SuffixTree suffix(argv[1]);

  suffix.BuildTree();

  suffix.PrintTree();

  return 1;
}
