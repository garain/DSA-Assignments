#include <stdio.h>
int main()
{
		int size;
		printf("Enter the six of array=");
		scanf("%d",&size);
		int arr[size];
		for(int i=0;i<size;i++)
		{
			printf("\n Enter the %d th term= ",i);
			scanf("%d",&arr[i]);
		}
		int flag1=0,flag2=0,flag3=0;
		for(int i=0;i<size-1;i++)//ascending order
		{
			if(arr[i]>arr[i+1])
			{
				flag1=1;
				break;
			}
		}
		for(int i=0;i<size-1;i++)//descending order
		{
			if(arr[i]<arr[i+1])
			{
				flag2=1;
				break;
			}
		}
		for(int i=0;i<size-1;i++)//Same order
		{

			if(arr[i]!=arr[i+1])
			{
				flag3=1;
				break;
			}
		}
		if (flag3==0)
			printf("All array elements are equal");
		else if(flag1==0)
			printf("The array is sorted in ascending order");
		else if(flag2==0)
			printf("The array is sorted in descending order");
		else
			printf("The array is not sorted");
		return 0;
}
