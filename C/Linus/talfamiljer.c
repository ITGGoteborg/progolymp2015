#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void swap(char *, char *);
int icontains(int *, int, int);
void permute(unsigned int **, char *, int, int, int *);

int main() {
  unsigned int i, j, k, l, m, n, len, nints;
  char num_ints[10];
  char input[128];
  char str[10];
  char *pch;
  unsigned int *flags, *ints, *family;
  fgets(num_ints, 10, stdin);
  fgets(input, 128, stdin);
  nints = atoi(num_ints);
  len = strlen(input);
  pch = strtok(input," ");
  ints = calloc(nints, sizeof(ints));
  flags = calloc(nints, sizeof(flags));
  family = calloc(10, sizeof(family));
  for(i=0;i<nints;i++) {
    ints[i] = atoi(pch);
    pch = strtok(NULL, " ");
  }
  for(k=1;;k++) {
    snprintf(str, 10, "%d", k);
    l = 0;
    n = strlen(str);
    len = 1;
    if(n>=2) {
      permute(&family, str, 0, n-1, &len);
    }else {
      family[0] = k;
    }
    for(i=0;i<len;i++) {
      for(j=0;j<nints;j++) {
        if(family[i] % ints[j] == 0) {
          if(!icontains(flags, l+1, ints[j])) {
            flags[l++] = ints[j];
            if(l>=nints) goto done;
          }
          continue;
        }
      }
    }
  }
  done:
  fprintf(stdout,"%d\n",k);
  free(family);
  free(ints);
  free(flags);
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

void permute(unsigned int **result, char *a, int l, int r, int *len) {
  static int buflen = 10;
  int *new_result;
  int i, aint;
  if(l == 0) *len = 0;
  if(l == r) {
    if(a[0] == '0') return;
    aint = atoi(a);
    if(*len > buflen) {
      buflen = (int)(((float)*len)*1.5f);
      new_result = realloc(*result, buflen * sizeof(*result));
      if(new_result != NULL) {
        *result = new_result;
      }else {
        fprintf(stderr, "Couldn't allocate memory for buffer.");
      }
    }
    (*result)[(*len)++] = aint;
  }else {
    for(i=l;i<=r;i++) {
      swap((a+l), (a+i));
      permute(result, a, l+1, r, len);
      swap((a+l), (a+i)); //backtrack
    }
  }
}
