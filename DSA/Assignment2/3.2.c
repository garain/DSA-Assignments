#include <stdio.h>
int SIZE=50;
int size;
//List operation with sentinal
void checkempty(int *a[])//checking for empty array
{
	if(a[0]==999999)
		printf("\nEmpty List.");
	else 
		printf("\nList is not empty.");
}
void arraylength(int *a[],int n)//finding array length
{
	int count=0;
	for(int i=0;i<SIZE;i++)
	{
		if(a[i]!=999999)//checking for sentinal
			count++;
		else 
			break;
	}
	if(n==1)
	printf("\nNo. of elements in the list= %d",count);
	size=count;
}
void arrayread(int *a[])//reading an element from the list
{
	int pos;
	printf("\nEnter the position to read: ");
	scanf("%d",&pos);
	if(pos<size && pos>=0)
	printf("\nThe %d element in the list is %d",pos,a[pos]);
	else
	printf("Wrong Input");
}
void arraywrite(int *a[])//writing an element to the list
{	
	int pos,num;
	printf("\nEnter the position to write: ");
	scanf("%d",&pos);
	if(pos<size && pos>=0)
	{
		printf("\nThe previous %d element in the list was %d",pos,a[pos]);
		printf("\nEnter the new elememt: ");
		scanf("%d",&num);
		a[pos]=num;
		printf("\nThe new %d element in the list is %d",pos,a[pos]);
	}
	else
	printf("Wrong Input");
	
}
void arraydelete(int *a[])//deleleting an element from the list
{
	int pos;
	printf("\nEnter the position to delete: ");
	scanf("%d",&pos);
	if(pos<size && pos>=0)
	{
		printf("\nThe previous %d element in the list was %d",pos,a[pos]);
		for(int i=pos;i<size-1;i++)
		{
			a[i]=a[i+1];
		}
		//a[size]=999999;
		size--;
		a[size]=999999;
	}
	else
	printf("Wrong Input");
}
void arrayinsert(int *a[])//inserting an element in the list
{
	int pos,num;
	printf("\nEnter the position to insert: ");
	scanf("%d",&pos);
	if(pos<size && pos >=0)
	{
		printf("\nEnter the new elememt: ");
		scanf("%d",&num);
		//printf("\nThe previous %d th element in the list was %d",pos,a[pos]);
		for(int i=size;i>pos;i--)
		{
			a[i]=a[i-1];
		}
		a[pos]=num;
		size++;
		a[size]=999999;
	}
	else
	printf("Wrong Input");
}
void arrayinput(int *a[])//taking input
{
	printf("\nEnter the 0 element of the array ");
	int i=0;
	/*do
	{
		printf("\nEnter the %d element of the array ",i);
		scanf("%d", a[i]);
		//size++;
		i++;
	}while(1);*/
	while(scanf("%d",&a[i]))
	{
		i++;
		printf("\nEnter the %d element of the array ",i);
		//if(scanf("%d",a[i])=='X')
			//break;
		//i++;
		
	}
	a[i]=999999;
	//size=i;
}
void arrayprint(int *a[])//printing array
{
	for(int i=0;i<size;i++)
		printf("\nThe %d element in the list : %d",i,a[i]);
}
/*void arraysort(int *a[])
{
	int temp;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}*/
void arraysort(int a[size])//sorting array
{
	//for(int i=0;i<size;i++)
	//printf("%d",a[i]);
   int i, key, j;
   for (i = 1; i < size; i++)
   {
       key = a[i];
       j = i-1;
       while (j >= 0 && a[j] > key)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = key;
   }
}
void arraysearch(int *a[])//searching for an element in list
{
	int num,flag=0;
	printf("\nEnter the element to search : ");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		if(a[i]==num)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("\nThe element is present.");
	else
		printf("\nThe element is not present.");
}

int main()
{
	int arr[SIZE];
	//for(int i=0;i<SIZE;i++)
	//	arr[i]=999999;
	arr[0]=999999;//999999 acts as sentinal value
	arrayinput(&arr);
	int choice;
	while(getchar()!='\n');
	printf("\nYour choices: \n1>To find out whether the list is empty or not \n2>To find out the length of the list \n3>To read/write data of n th element in the list \n4>To insert/delete an element at n th position in the list \n5>To search for a key in the list \n6>To sort the list \n7>Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&choice);//taking choice
		arraylength(&arr,0);//getting length but not printing
		//printf("\n  %d ",choice );
		if(choice==1)
		{
			checkempty(&arr);
		}
		else if(choice==2)
		{
			arraylength(&arr,1);
		}
		else if(choice==3)
		{
			arrayread(&arr);
			arraywrite(&arr);
			arrayprint(&arr);
		}
		else if(choice==4)
		{
			arrayinsert(&arr);
			arrayprint(&arr);
			arraydelete(&arr);
			arrayprint(&arr);
		}
		else if(choice==5)
		{
			arraysearch(&arr);
		}
		else if(choice==6)
		{
			arraysort(arr);
			arrayprint(&arr);
		}
		else if(choice==7)
			break;
		else
			printf("Wrong Input");
	}
	while(getchar()!='\n');
	//arrayprint(&arr);
	return 0;
}