#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void swap(char *, char *);
int icontains(int *, int, int);
int contains(char **, int, char *);
void permute(char **, char *, int, int, int *);
unsigned int factorial(unsigned int);

int main() {
  unsigned int i, j, k, l, m, n, len;
  char num_ints[10];
  char input[128];
  char str[7];
  char **family;
  char **ints;
  char *pch;
  unsigned int *flags;
  fgets(num_ints, 10, stdin);
  fgets(input, 128, stdin);
  len = strlen(input);
  pch = strtok(input," ");
  ints = calloc(atoi(num_ints), sizeof(char*));
  flags = calloc(atoi(num_ints), sizeof(char*));
  for(i=0;i<atoi(num_ints);i++) {
    ints[i] = malloc(strlen(pch)+1);
    strcpy(ints[i], pch);
    pch = strtok(NULL, " ");
  }
  for(k=1;;k++) {
    snprintf(str, 6, "%d", k);
    l = 0;
    n = strlen(str);
    len = factorial(n);
    family = calloc(len, sizeof(char*));
    if(n>=2) {
      permute(family, str, 0, n-1, &len);
    }else {
      family[0] = malloc(n+1);
      strcpy(family[0], str);
    }
    for(i=0;i<len;i++) {
      for(j=0;j<atoi(num_ints);j++) {
        if(atoi(family[i]) % atoi(ints[j]) == 0) {
          if(!icontains(flags, l+1, atoi(ints[j]))) {
            flags[l++] = atoi(ints[j]);
            if(l>=atoi(num_ints)) goto done;
          }
          continue;
        }
      }
    }
    for(i=0;i<len;i++) {
      free(family[i]);
    }
    free(family);
  }
  done:
  fprintf(stdout,"%d\n",k);
  for(i=0;i<len;i++) {
    free(family[i]);
  }
  free(family);
  for(i=0;i<atoi(num_ints);i++) {
    free(ints[i]);
  }
  free(ints);
}

void swap(char *x, char *y) {
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int icontains(int *array, int len, int a) {
  int i;
  for(i=0;i<len;i++) {
    if(array[i]==a) {
      return 1;
    }
  }
  return 0;
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
