
#include<stdio.h>
#define size 4
int main()
{
	
	int Arr1[size],Arr2[size];
	printf("Enter the sorted array of integers of size=%d\n",size);
	
	
	for(int i=0;i<size;i++)
	{
		printf("Enter (%d)th element of 1st array\n",i+1);
		scanf("%d",&Arr1[i]);
		printf("Enter (%d)th element of 2nd array\n",i+1);
		scanf("%d",&Arr2[i]);
	}
	
	
	//Arr1 = initArray();
	//Arr2 = initArray();
	int sortOrder=2;//0 for Ascending ,1 for Descending ad 2 if all the elements are equal.
	int temp;
	int mergeArray[2*size];//creating the merged array.
	//Checking if the array is sorted in ascending order.
	for (int i=0;i<size-1;i++)
	{
		if(Arr1[i]<Arr1[i+1])
		{	
			sortOrder = 0;
			break;
		}
	}
	
	if(sortOrder!=0)
		sortOrder=1;//If array is sorted in descending order.
	
	
		
	
	
	for(int i=0;i<size;i++)
	{
		mergeArray[i]=Arr1[i];
		mergeArray[i+size]=Arr2[i];
		//printf("%d,",mergeArray[i]);
		//printf("%d,",Arr1[i]);
	}
	/*for(int i=0;i<2*size;i++)
	{
		printf("%d,",mergeArray[i]);
	}*/
	//Bubble Sorting the array for ascending order.
	if(sortOrder==0)
	{
		for(int i=0;i<2*size;i++)
		{
			for(int j=0;j<2*size-1;j++)
			{
				if(mergeArray[j]>mergeArray[j+1])
				{
					temp=mergeArray[j];
					mergeArray[j]=mergeArray[j+1];
					mergeArray[j+1]=temp;
				}
			}
		}
	}
	//sorting for descending order.
	else if(sortOrder==1)
	{
		
		for(int i=0;i<2*size;i++)
			{
				for(int j=0;j<2*size-1;j++)
				{
					if(mergeArray[j]<mergeArray[j+1])
					{
						temp=mergeArray[j];
						mergeArray[j]=mergeArray[j+1];
						mergeArray[j+1]=temp;
					}
				}
			}
	}
	//sorting if all elements are equal.	
	else if(sortOrder==2)
	{
		
		for(int i=0;i<size;i++)
		{
			if(Arr1[i]<Arr2[i])
			{
				mergeArray[i]=Arr1[i];
				mergeArray[i+size]=Arr2[i];
			}
		}
	}
	
	/*MergeArray = mergeArray(Arr1,Arr2);
	printf("The Merged array\n");*/
	
	for(int i=0;i<(2*size);i++)
	{
		
		printf("%d,",mergeArray[i]);
	}
	
	return 0;
}
