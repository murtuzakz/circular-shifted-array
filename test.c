
//Program to take a Circular Sorted Array as input, and return index of search element in the Array.

#include<stdio.h>
int main()
{
	int size,low,mid,high,i;
	//printf("Enter the size of the input array  :  ");
	scanf("%d",&size);
	int a[size];
	for(i=0;i<size;i++)
	{
		//printf("Enter element at position %d :  ",i);
		scanf("%d",&a[i]);
	}
	low = 0;
	high = size - 1;
	int ele;
	/* 
	 This is different form normal binary search because our 'mid' is not going to be the normal middle element.
	 Usually in a sorted array, when we split the element into 2 at the middle position, we get 2 sorted sub arrays.
	 Thats not true for a Circularly Sorted Array. A circularly sorted Array can still be split into 2 sorted sub arrays,
	 if it is split at its break point
	 If i took the index of the array on the X axis, and the value at that index on Y axis,
	 Break point is the X coordinate of the point on the graph, where the plot breaks continuity.
	 */
	mid = break_point(a,size);
	//printf("Enter element you want to search\n");
	scanf("%d",&ele);
	while(low <= high)
	{
		if (a[mid] == ele)
		{
			printf("ELEMENT FOUND AT POSITION %d\n",mid);
			return mid;
		}
		else if(ele > a[mid] && ele <= a[high])
			low = mid +1;
		else
			high = mid-1;
		mid = (high + low)/2;	
	}
	printf("ELEMENT NOT FOUND\n");
	return 0;
}
/* 
   This function takes as input the circular sorted array, and finds out the break point.
   Break point is where the ordering of the array fails
   For example : 4,5,6,-3,-2,-1,0,1,2,3 Break point is at index 3, breakpoint element is -3
   The resaon we find the break point element is, if we split the array at the break point element, the 2 resulting arrays we 
   get are sorted array, and hence Bindary search can be applied to them.
*/
int break_point(int *a, int size)
{
	int high = size -1;
	int low = 0;
	int mid;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(mid>1 && a[mid-1] > a[mid] && a[mid+1] >a[mid])
			break;
		if(a[mid] < a[high])
			high = mid -1;
		else
			low = mid + 1;
	}
	return mid;
}