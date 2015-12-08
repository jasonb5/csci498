#include "suffix.h"

int main(int argc, char **argv) {
  SuffixTree suffix((char *)"ababaaabbba");

  suffix.BuildTree();

  return 1;
}
