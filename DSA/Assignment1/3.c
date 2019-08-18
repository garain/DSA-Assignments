#include<stdio.h>
#include<string.h>
int LinearIntSearch(int *a,int val){
int i;
for(i=0;i<10;i++)
{
	if(a[i]==val)
		return i;
}
return -1;
}
void sort(int *arr){
int i,j;
for(i=0;i<10;i++){
	for(j=i+1;j<10;j++){
		if(arr[j]<arr[i]){
			arr[j]=arr[j]+arr[i];
			arr[i]=arr[j]-arr[i];
			arr[j]=arr[j]-arr[i];	
		}
	}
	}
}
int BinaryIntSearch(int *arr,int val){
int lb=0,ub=9,mid;
while(ub>=lb){
	mid=(ub+lb)/2;
	if(arr[mid]==val)
		{		
		return mid;
		break;
		}
	else if(arr[mid]>val){
		ub=mid-1;	
		}
	else lb=mid+1;
}
return -1;
}
int LinearFloatSearch(float *a,float val){
int i;
for(i=0;i<10;i++)
{
	if(a[i]==val)
		return i;
}

}
void Floatsort(float *arr){
int i,j;
float temp;
for(i=0;i<10;i++){
	for(j=i+1;j<10;j++){
		if(arr[j]<arr[i]){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;	
		}
	}
	}
}
int BinaryFloatSearch(float *arr,float val){
int lb=0,ub=9,mid;
while(ub>=lb){
	mid=(ub+lb)/2;
	if(arr[mid]==val)
		{		
		return mid;
		break;
		}
	else if(arr[mid]>val){
		ub=mid-1;	
		}
	else lb=mid+1;
}
}

int LinearWordSearch(char w_arr[][10],char val[20]){
int i;
for(i=0;i<10;i++)
{
	if(!(strcmp(w_arr[i],val))){
		return i;
		break;}
}
return -1;
}

void Wordsort(char w_arr[][10]){
int i,j;
char temp[10];
for(i=0;i<10;i++){
	for(j=i+1;j<10;j++){
		if(strcmp(w_arr[i],w_arr[j])>0){
			strcpy(temp,w_arr[i]);
			strcpy(w_arr[i],w_arr[j]);
			strcpy(w_arr[j],temp);	
		}
	}
	}
}

int BinaryWordSearch(char w_arr[][10],char val[20]){
int lb=0,ub=9,mid;
while(ub>=lb){
	mid=(ub+lb)/2;
	if(!(strcmp(w_arr[mid],val)))
		{		
		return mid;
		break;
		}
	else if(strcmp(w_arr[mid],val)>0){
		ub=mid-1;	
		}
	else lb=mid+1;
}
return -1;
}

int main(){
	int arr[]={65,43,1,76,32,23,59,0,8,73},num,i;
	printf("Enter number to be searched.\n");
	scanf("%d",&num);
	
	//for(i=0;i<10;i++)
	//printf("%d,",arr[i]);
	printf("Position after linear search=%d\n",LinearIntSearch(arr,num));
	sort(arr);
	printf("Position after binary search=%d\n",BinaryIntSearch(arr,num));

	float arr1[]={0.065,4.3,.01,7.65,32.765,2.453,59,0,8.9,7.32},num1;
	printf("Enter float number to be searched.");
	scanf("%f",&num1);
	
	//for(i=0;i<10;i++)
	//printf("%d,",arr[i]);
	printf("Position after linear search=%d\n",LinearFloatSearch(arr1,num1));
	Floatsort(arr1);
	printf("Position after binary search=%d\n",BinaryFloatSearch(arr1,num1));
	
	char w_arr[][10]={"rat","cat","network","pattern","bat","chat","fat","tiger","peacock","day"},word[20];
	printf("Enter word to be searched.\n");
	scanf("%s",word);
	printf("Position after linear search=%d\n",LinearWordSearch(w_arr,word));
	Wordsort(w_arr);
	printf("Position after binary search=%d\n",BinaryWordSearch(w_arr,word));
	
return 0;
}
