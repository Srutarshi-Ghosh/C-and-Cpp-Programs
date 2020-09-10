#include<iostream>
#include<stdlib.h>

int linearsearch(int*, int, int);
int* inputarr(int);

int main(){
	int n, *arr, pos, search;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	arr=inputarr(n);
	printf("Enter the element to search: ");
	scanf("%d", &search);
	pos=linearsearch(arr, n, search);
	if(pos>0)
		printf("The number %d found at position %d", search, pos);
	else
		printf("The number %d not found in array", search);
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

int linearsearch(int *arr, int n, int search){
	int i;
	for(i=0; i<n; i++){
		if(arr[i]==search)
			return i+1;
	}
	return -1;
	
}
