#include <stdbool.h>
#include<stdio.h>
int main()
{
	int arr[10]={1,3,4,5,8,9,10,15,26,30};
	int val=20;
	int left=0;
	bool flag=1;
	int mid;
	int right=sizeof(arr)/sizeof(arr[0])-1;
	while(left<right)
	{
		mid=(left+right)/2;
		if(arr[mid]==val)
	 	{
 			printf("%d",mid);
 			flag=0;
 			break;
 		}
	 	else if(arr[mid]>val)
	 		right=mid;
 		else
 			left=mid+1; 	
			 	
	}
	if(flag)
		printf("%s","-1");
}

