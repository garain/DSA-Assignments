#include<stdio.h>
#include<time.h>
#include<math.h>
int main(){
	long long L[5],rem[3][5],q[3][5],x;
	int p[]={1013,1019,1097},i=0,j;
	srand(time(0));
	for(i=0;i<5;i++){
		L[i]=(rand()%32267)*99+100000;
	}
	for(j=0;j<3;j++){
	for(i=0;i<5;i++){
		q[j][i]=L[i]/p[j];
	}
}
for(j=0;j<3;j++){
	for(i=0;i<5;i++){
		rem[j][i]=L[i]%p[j];
	}
}
FILE *fp;
fp=fopen("Ass6_results.txt","w");
for(j=0;j<3;j++){
	fprintf(fp,"Divisor=%ld\n",p[j]);
	fprintf(fp,"Sl.No.\tNumber\tQuotient  Remainder\n");
	for(i=0;i<5;i++){
		fprintf(fp,"%d\t%ld\t  %ld\t  %ld\n",i,L[i],q[j][i],rem[j][i]);
	}
	fprintf(fp,"\n");
}
	return 0;
}
