#include<stdio.h>
/*long fibo(int n){
	
}
*/
int main(){
	int n,i;
	long a=0,b=1,temp=0;
	scanf("%d",&n);
	for(i=2;i<n;i++){
		temp=b;
		b=a+b;
		a=temp;
	}
	printf("%ld",b);
	return 0;
}
