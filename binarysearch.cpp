#include<iostream>
#include<stdlib.h>

int binarysearch(int*, int, int);
int* inputarr(int);

int main(){
	int n, *arr, pos, search;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	arr=inputarr(n);
	printf("Enter the element to search: ");
	scanf("%d", &search);
	pos=binarysearch(arr, n, search);
	if(pos>0)
		printf("The number %d found at position %d", search, pos);
	else
		printf("NOT FOUND", search);
	return 0;
	}

int* inputarr(int n){
	int *arr, i;
	arr = (int*) malloc(sizeof(int)*n);
	printf("Enter %d elements: \n", n);
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	return arr;
}

int binarysearch(int *arr, int n, int search){
	int l=0, r=n-1, mid;
	mid=(l+r)/2;
	while(l<=r){
		if(arr[mid]==search)
			return mid+1;
		else if(arr[mid]<search)
			l=mid+1;
		else
			r=mid-l;
		mid=(l+r)/2;
		
	}
	return -1;
	
}
