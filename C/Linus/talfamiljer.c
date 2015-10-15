#include <stdio.h>

int main() {
  int N,i,j,k,p[10],n[100];
  int mask[1000000];

  scanf("%d", &N);
  for(i=0;i<N;i++) scanf("%d", &n[i]);
  for(i=1;i<1000000;i++) mask[i]=0;
  for(i=1;i<1000000;i++) {
    k=i;
    for(j=0;j<10;j++) p[j]=0;
    while (k>0) {p[k%10]++; k/=10;}

    for(j=1;j<10;j++) if(p[j]>0) {k=j; p[j]--; break;}
    for(j=0;j<10;j++) while (p[j]>0) {k=10*k+j; p[j]--;}
    for(j=0;j<N;j++) if(i%n[j]==0) mask[k]|=(1<<j);
  }
  for(i=1;i<1000000;i++) if(mask[i]==(1<<N)-1) break;
  fprintf(stdout, "%d\n", i);
}
