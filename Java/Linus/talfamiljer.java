import java.util.Scanner;

public class talfamiljer {

	public static void main(String[] args) {
	  int N,i,j,k,p[],n[];
	  int mask[] = new int[1000000];
	  p = new int[10];
	  n = new int[100];

	  Scanner scan = new Scanner(System.in);
	  N = scan.nextInt();
	  for(i=0;i<N;i++) n[i] = scan.nextInt();
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
	  System.out.printf("%d\n", i);
	  scan.close();
	}
}
