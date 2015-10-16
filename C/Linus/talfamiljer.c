#include <stdio.h>
#define MAX 1000000

int main() {
  int N,n[100];
  int p[10] = {0};
  int mask[MAX] = {0};
  register int i, j, k;

  scanf("%d", &N);
  for(i=0;i<N;i++) scanf("%d", &n[i]);
  i = MAX+1;
  while(--i) {
    int maskBits = 0;
    for(j=0;j<N;j++) {
        if(i%n[j]==0)
            maskBits |= (1 << j);
    }
    if (maskBits == 0)
        continue;
    k=i;
    while (k>0) {p[k%10]++; k/=10;}

    for(j=1;j<10;j++) if(p[j]>0) {k=j; p[j]--; break;}
    for(j=0;j<10;j++) while (p[j]>0) {k=10*k+j; p[j]--;}
    mask[k] |= maskBits;
  }
  for(i=1;i<MAX;i++) if(mask[i]==(1<<N)-1) break;
  fprintf(stdout, "%d\n", i);
}
