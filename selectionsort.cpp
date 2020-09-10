#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);
void arrayinput(int[], int);
void selectionsort(int[], int);
void printarray(int[], int);

int main(){
	int arr[10], n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	arrayinput(arr, n);
	selectionsort(arr, n);
	printf("The sorted array is: \n");
	printarray(arr, n);
	return 0;
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void arrayinput(int *arr, int n){
	int i;
	printf("Enter the elements of the array: \n");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
}

void selectionsort(int arr[], int n){
	int i, j, min;
	for(i=0; i<n-1; i++){
		min=i;
		for(j=i+1; j<n; j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		swap(&arr[i], &arr[min]);
		
	}
}

void printarray(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
}
