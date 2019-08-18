#include<stdio.h>
#include<string.h>

int main(){
	
	char Name[]={'A','V','I','S','H','E','K'},Surname[]={'G','A','R','A','I','N'};
	int p[]={1013,1019,1097};
	long juxta_name,juxta_surname,name_1,name_2,sum,quotient,remainder;
	int i,j;
	for(i=0;i<7;i++)
	juxta_name=juxta_name*100+Name[i];
	for(i=0;i<6;i++)
	juxta_surname=juxta_surname*100+Surname[i];
	name_1=juxta_name/10000000;
	name_2=juxta_surname%10000000;
	sum=name_1+name_2;

	FILE *fp;
	fp=fopen("Ass7_results.txt","w");
	for(j=0;j<3;j++){
	quotient=sum/p[j];
	remainder=sum%p[j];
	fprintf(fp,"Divisor=%ld\n",sum);
	fprintf(fp,"Sl.No.\tNumber\tQuotient  Remainder\n");
	fprintf(fp,"%d\t%ld\t  %ld\t  %ld\n",i,sum,quotient,remainder);
}
return 0;	
	
}
