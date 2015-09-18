#include <stdio.h>
#include <stdlib.h>

/*
 * Uncomment to print debug information. See following sample:
 *
 * Input: aaba
 *
 * i1 = 0 i2 = 0 a    the start/end index of the input and the palidrone
 * i1 = 0 i2 = 1 aa
 * aaba               subset we considered
 * 1100               result of the subset
 * i1 = 1 i2 = 1 a
 * i1 = 1 i2 = 3 aba
 *  aba
 *  101
 * i1 = 2 i2 = 2 b
 *   ba
 *   10
 * i1 = 3 i2 = 3 a
 *    a
 *    1
 */ 
//#define DEBUG

// Only need to change if the input file has more than 1024 characters
#define MAX_INPUT 1024

int main(int argc, char **argv) {
  FILE *fp;
  int size;
  int x, y, z;
  int pal_count;
  char idata[MAX_INPUT];
  int matrix[MAX_INPUT][MAX_INPUT];

  fp = fopen(argv[1], "r");

  if (!fp) {
    fprintf(stderr, "Error opening file %s\n", argv[1]);

    exit(1);
  } 
  
  size = 0;

  // Read in file until we get EOF or a newline
  while (!feof(fp)) {
    idata[size] = getc(fp);

    if (idata[size] == 0xa) {
      break;
    } 

    size++;
  } 

  fclose(fp); 

  // Initialize array to zeros, except for the principal diagonal and its
  // preceeding diagnol
  for (x = 0; x < size; ++x) {
    for (y = 0; y < size; ++y) {
      if (x == y || x == y+1) {
        matrix[x][y] = 1;
      } else {
        matrix[x][y] = 0;
      }
    }
  }

  // Uses dp to find all substrings containing a palindrone
  // Let M contain a sequence of characters of length n
  // Let T be a table of size n x n
  // Set principal and previous diagnol to 1
  // Recurence relation:
  // T[j-i][j] = 1 if T[j-i+1][j-1] == 1 and M[j-i] == M[y]
  //  1 <= i < n and i <= j < n
  // Otherwise
  // T[j-i][j] = 0
  for (x = 1; x < size; ++x) {
    for (y = x; y < size; ++y) {
      if (matrix[y-x+1][y-1] == 1) {
        if (idata[y-x] == idata[y]) {
          matrix[y-x][y] = 1;
        }
      }
    }
  }

  pal_count = 0;

  // Count how many palindrons were found.
  for (x = 0; x < size; ++x) {
    for (y = x; y < size; ++y) {
      if (matrix[x][y]  == 1) {
        pal_count++;
      } 
    }
  }

  fprintf(stdout, "Found %d palidrones\n", pal_count);

#ifdef DEBUG
  for (x = 0; x < size; ++x) {
    for (y = x; y < size; ++y) {
      if (matrix[x][y] == 1) {
        fprintf(stdout, "i1 = %d i2 = %d ", x, y);

        for (z = x; z <= y; ++z) fprintf(stdout, "%c", idata[z]);

        fprintf(stdout, "\n");
      }
    }

    for (y = 0; y < x; ++y) fprintf(stdout, " ");

    for (y = x; y < size; ++y) {
      fprintf(stdout, "%c", idata[y]);
    }

    fprintf(stdout, "\n");

    for (y = 0; y < x; ++y) fprintf(stdout, " ");

    for (y = x; y < size; ++y) {
      fprintf(stdout, "%d", matrix[x][y]);
    }

    fprintf(stdout, "\n");
  }
#endif

  return 0;
}
