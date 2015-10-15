#include <stdio.h>
#define MAX 1000000

int main() {
  int N,p[10],n[100];
  int mask[MAX] = {0};
  register int i, j, k;

  scanf("%d", &N);
  for(i=0;i<N;i++) scanf("%d", &n[i]);
  i = MAX+1;
  while(--i) {
    k=i;
    p[0]=0;
    p[1]=0;
    p[2]=0;
    p[3]=0;
    p[4]=0;
    p[5]=0;
    p[6]=0;
    p[7]=0;
    p[8]=0;
    p[9]=0;
    while (k>0) {p[k%10]++; k/=10;}

    for(j=1;j<10;j++) if(p[j]>0) {k=j; p[j]--; break;}
    for(j=0;j<10;j++) while (p[j]>0) {k=10*k+j; p[j]--;}
    for(j=0;j<N;j++) if(i%n[j]==0) mask[k]|=(1<<j);
  }
  for(i=1;i<MAX;i++) if(mask[i]==(1<<N)-1) break;
  fprintf(stdout, "%d\n", i);
}
