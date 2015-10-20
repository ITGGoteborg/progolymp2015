#include <stdio.h>
#include <stdlib.h>

int lookup[] = {
#include "table.h"
};

#define LENGTH(x)  (sizeof(x) / sizeof((x)[0]))
#define MAX 1000000

int main(int argc, char **argv) {
  register int i, j, p;

  if(argc != 2 || ((i=atoi(argv[1]))<0) || i>MAX) {
    fprintf(stderr, "Usage: %s <number between 0 and %d>\n", argv[0], MAX);
    exit(0);
  }

  fprintf(stdout, "total length is %d\n", LENGTH(lookup));

  j=i-1;
  i*=-1;
  while(j < LENGTH(lookup) && lookup[j] != i) ++j;
  printf("index of %d is %d and it's permutations are:\n", i, j);
  while((p = lookup[++j]) > 0) printf("%d,", p);
  printf("\n");
}
