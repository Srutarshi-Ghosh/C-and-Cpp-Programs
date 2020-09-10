#include<iostream>
#include<stdlib.h>

int* inputarray(int);
int binarysearch(int *arr, int n, int ser);

int main(){
	int i, n, *arr, ser, pos;
	printf("Enter the number of elements of the array: ");
	scanf("%d", &n);
	arr=inputarray(n);
	printf("Enter the element to search: ");
	scanf("%d", &ser);
	pos=binarysearch(arr, n, ser);
	if(pos>0)
		printf("The element %d is at position %d", ser, pos);
	else
		printf("The element is not present in the array");
	return 0;
}

int* inputarray(int n){
	int *arr, i;
	arr=(int*) malloc(n*sizeof(int));
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	return arr;
}

int binarysearch(int *arr, int n, int ser){
	int i, mid, l, r;
	l=0;
	r=n-1;
	mid=r+l/2;  
	while(l<=r){
		if(arr[mid]==ser)
			return mid+1;
		if(arr[mid]<ser){
			l=mid+1;
		}
		else
			r=mid-1;
		mid=(l+r)/2;
		
	}
	return -1;
}

