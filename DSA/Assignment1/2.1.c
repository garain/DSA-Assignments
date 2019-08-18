#include<stdio.h>
#include<time.h>
#define long long long
long count=0;
long fibo(int n){
	if(n==0)return 0;
	if(n==1)return 1;
	count++;
	return (fibo(n-1)+fibo(n-2));
	count=0;
}
int main(){
	int n,i;
	FILE *f=fopen("C:\\Users\\hp\\Documents\\results.txt","w");
	double time_i=0.0,time_f=0.0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	time_i=clock();
	fprintf(f,"%d %ld ",i,fibo(i));
	time_f=clock();
	fprintf(f,"%ld %3.6f\n",count,(time_f-time_i)/1000.0);
	count=0;
	}
	fclose(f);
	return 0;
}
