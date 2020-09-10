#include<stdio.h>

int partition(int[], int, int);
void quicksort(int[], int, int);
void swap(int*, int*);

int main(){
	int arr[100], n, i;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements of the array: ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}	
	quicksort(arr, 0, n-1);
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
}

void quicksort(int arr[], int l, int r){
	int q;
    if(l<r){
		q = partition(arr, l, r);
		quicksort(arr, l, q-1);
		quicksort(arr, q+1, r);
	}
}

int partition(int arr[], int l, int h){
	int i = l-1, piv = arr[h], j;
	for(j=l; j<h; j++){
		if(arr[j]<=piv){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[h]);
	return i+1;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
