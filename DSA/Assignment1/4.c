#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void randomize(int arr[],int n){
	srand(time(0));
	int i,j;
	for(i=n-1;i>0;i--){
		j=rand()%i;
		swap(&arr[i],&arr[j]);
	}
}
int main(){
	int n=60000;
	FILE*fp=fopen("rand_ints.txt","w");
	int arr[n];
	int loop;
	for(loop=0;loop<n;loop++)
		arr[loop]=loop+1;
	randomize(arr,n);
	for(loop=0;loop<n;loop++)
		fprintf(fp,"%d\n",arr[loop]);	
	fclose(fp);
}

