#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1024

int main(int argc, char **argv) {
  FILE *fp;
  int size;
  int x, y, z;
  char idata[MAX_INPUT];
  int matrix[MAX_INPUT][MAX_INPUT];

  fp = fopen(argv[1], "r");

  if (!fp) {
    fprintf(stderr, "Error opening file %s\n", argv[1]);

    exit(1);
  } 
  
  size = 0;

  while (!feof(fp)) {
    idata[size] = getc(fp);

    if (idata[size] == 0xa) {
      break;
    } 

    size++;
  } 

  fclose(fp); 

  fprintf(stdout, "Read %d characters\n", size);

  for (x = 0; x < size; ++x) {
    fprintf(stdout, "%c\t", idata[x]);

    matrix[x][x] = 1;

    if (x > 0) {
      matrix[x][x-1] = 1;
    }
  }

  fprintf(stdout, "\n");

  for (x = 1; x < size; ++x) {
    for (y = x; y < size; ++y) {
      if (matrix[y-x+1][y-1] == 1) {
        if (idata[y-x] == idata[y]) {
          matrix[y-x][y] = 1;
        }
      }
    }
  }
  
  fprintf(stdout, "\n");

  for (x = 0; x < size; ++x) {
    for (y = 0; y < size; ++y) {
      fprintf(stdout, "%d\t", matrix[x][y]);
    }
    fprintf(stdout, "\n");
  }

  return 0;
}
