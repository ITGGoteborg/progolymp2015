#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void swap(char *x, char *y) {
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int contains(char **array, int len, char *a) {
  int i;
  for(i=0;i<len;++i) {
    if(!array[i] || !strcmp(array[i], a)) {
      return 1;
    }
  }
  return 0;
}

void permute(char **result, char *a, int l, int r, int *len) {
  int i;
  if(l==0) *len = 0;
  if(l == r) {
    if(a[0] == '0') return;
    if(!contains(result, *len, a)) {
      result[*len] = malloc(strlen(a)+1);
      strcpy(result[(*len)++], a);
    }
  }else {
    for(i=l;i<=r;i++) {
      swap((a+l), (a+i));
      permute(result, a, l+1, r, len);
      swap((a+l), (a+i)); //backtrack
    }
  }
}

unsigned int factorial(unsigned int n) {
  if(n==0)
    return 1;
  else
    return(n*factorial(n-1));
}

int main(int argc, char **argv) {
  if(argc != 2) {
    fprintf(stdout, "Usage: %s <number>\n", argv[0]);
    return 0;
  }

  int i, n = strlen(argv[1]);
  int len = factorial(n);
  char **family;
  family = calloc(len,sizeof(char*));
  permute(family, argv[1], 0, n-1, &len);
  for(i=0;i<len;i++) {
    printf("%s\n", family[i]);
  }
  for(i=0;i<len;i++) {
    free(family[i]);
  }
  free(family);
  return 0;
}
