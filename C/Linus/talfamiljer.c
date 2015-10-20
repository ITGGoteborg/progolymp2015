#include <stdio.h>

int lookup[] = {
#include "table.h"
};

#define MAX 1000000

int main(void) {
  int N, n[100];
  int j;
  register int i, m, k;

  scanf("%d", &N);
  for(i=0;i<N;i++) scanf("%d", &n[i]);
  for(i=0;i<MAX;i++) {
    while(lookup[i] >= 0)
        ++i;
    lookup[i] = -lookup[i];
    for(j=0;j<N;j++) {
      m = i;
      while((k = lookup[m++]) > 0) {
        if(k%n[j]==0)break;
      }
      if(k<0) goto outer;
    }
    break;
    outer:
    continue;
  }
  fprintf(stdout, "%d\n", lookup[i]);
}
