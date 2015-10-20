#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000000

void permute(unsigned int **result, char *a, int l, int r, int *len);

int main() {
  int i, k, j, len;
  int p[10] = {0};
  char str[10];
  unsigned int *family;

  family = calloc(10, sizeof(family));
  for(i=1;i<MAX;i++) {
    k=i;
    snprintf(str, 10, "%d", i);
    while (k>0) {p[k%10]++; k/=10;}

    for(j=1;j<10;j++) if(p[j]>0) {k=j; p[j]--; break;}
    for(j=0;j<10;j++) while (p[j]>0) {k=10*k+j; p[j]--;}
    if(k==i) {
      fprintf(stdout, "-%d,", i);
      if(i>=10) {
        permute(&family, str, 0, strlen(str)-1, &len);
      }
    }
  }
  fprintf(stdout, "-%d", MAX);
  free(family);
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
  if(l == 0) {
    *len = 0;
    (*result)[(*len)++] = atoi(a);
  }
  if(l == r) {
    if(a[0] == '0') return;
    aint = atoi(a);
    if(!icontains(*result, *len, aint)) {
      if(*len >= buflen) {
        buflen = (int)(((float)*len)*1.5f);
        new_result = realloc(*result, buflen * sizeof(*result));
        if(new_result != NULL) {
          *result = new_result;
        }
      }
      fprintf(stdout, "%d,", aint);
      (*result)[(*len)++] = aint;
    }
  }else {
    for(i=l;i<=r;i++) {
      swap((a+l), (a+i));
      permute(result, a, l+1, r, len);
      swap((a+l), (a+i)); //backtrack
    }
  }
}
