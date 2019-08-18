#include<stdio.h>
#include<time.h>
#define long long long
long count=0;

int main(){
	int n,i,result=1,j;
	FILE *f=fopen("factorial_results1.txt","w");
	double time_i=0.0,time_f=0.0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		if(i==0)result=1;
		else{
		for(j=1;j<i;j++){
		result=result*j;
		}
		
	}
	time_i=clock();
	fprintf(f,"%d %ld ",i,result);
	time_f=clock();
	fprintf(f,"%ld %3.6f\n",count,(time_f-time_i)/1000.0);
	count=0;
	}
	fclose(f);
	return 0;
}
