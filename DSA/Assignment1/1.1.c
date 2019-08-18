#include<stdio.h>
#include<time.h>
#define long long long
long count=0;
long facto(int n){
	if(n==0)return 1;
	if(n==1)return 1;
	count++;
	return(n*facto(n-1));
	count=0;
}
int main(){
	int n,i;
	FILE *f=fopen("factorial_results.txt","w");
	double time_i=0.0,time_f=0.0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	time_i=clock();
	fprintf(f,"%d %ld ",i,facto(i));
	time_f=clock();
	fprintf(f,"%ld %3.6f\n",count,(time_f-time_i)/1000.0);
	count=0;
	}
	fclose(f);
	return 0;
}
