#include <stdio.h>

#define ARRAYSIZE 10

int populate_array(int [],int *);
int sort_array(int [],int *);
int binary_search(int [],int *);

void main()
{
	int arr[ARRAYSIZE],arraysize,index;
	populate_array(arr,&arraysize);
	sort_array(arr, &arraysize);
	if (index = binary_search(arr, &arraysize))
		printf("\n\n Element found at index %d ",index);
	else
		printf("\n Element not found");
}

int populate_array(int arr[],int *n)
{ 
	int index;
	char ch;
	printf("\n Enter your array size (below 11) : ");
	scanf("%d",n);
	printf("\n Enter the elements of the array: ");
	for( index = 0 ; index < *n ; index++ )
	{
		scanf("%d",&arr[index]);
	}
	printf("\n ARRAY: ");
	for( index = 0 ; index < *n ; index++ )
	{
		printf("%d  ",arr[index]);
	}
}

int sort_array(int p[], int *n)
{
	int i,temp,j;
  	for( i=0 ; i<(*n) ; i++ )
  	{
    	for( j=i ; j>0 ; j--)
    	{
      		if( *(p+j) < *(p+j-1) )
      		{
	  			temp=*(p+j);
				*(p+j)=*(p+j-1);
				*(p+j-1)=temp;
      		}
    	}
  	}	
  	printf("\n SORTED ARRAY: ");
  	for( i=0 ; i<*n;i++)
  		printf("%d  ",p[i]);
}

/*int binary_search(int p[],int *n)
{
  int i,item,low,high,mid;
  printf("\n\n Enter the number to be searched: ");
  scanf("%d",&item);
  low = 0;
  high = *n-1;
  while(low <= high) 					//	KnR Example Version
  {
  	mid = (low+high)/2;
  	if(item < *(p+mid))
    	high = mid-1;
  	else if(item > *(p+mid))
    	low = mid+1;
    else
    	return mid;
  }
  return 0;
}*/

int binary_search(int arr[], int *arraysize)
{
	int i,item,low,high,mid, counter = 0;
  	printf("\n\n Enter the number to be searched: ");
  	scanf("%d",&item);
  	low = 0;
  	high = *arraysize-1;
  	while((arr[mid = (low + high)/2] != item ) && low<=high)
  	{
  		if( item < arr[mid])
  			high = mid - 1;
  		else
  			low = mid + 1;
  	}
  	if(high<low || arr[mid] != item)
  		return 0;
  	else
  		return mid;
}