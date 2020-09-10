#include<stdio.h>

void swap(int*, int*);
void arrayinput(int[], int);
int bubblesort(int[], int);
void printarray(int[], int);

int main(){
	int arr[10], n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	arrayinput(arr, n);
	printf("%d",bubblesort(arr, n));
	printf("The sorted array is: \n");
	printarray(arr, n);
	return 0;
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void arrayinput(int arr[], int n){
	int i;
	printf("Enter the elements of the array: \n");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
}

void bubblesort(int arr[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1])
				swap(&arr[j], &arr[j+1]);
			
		}
	}
}

void printarray(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
}


