#include<stdio.h>

void arrayinput(int[], int);
void insertionsort(int[], int);
void printarray(int[], int);

int main(){
	int arr[10], n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	arrayinput(arr, n);
	insertionsort(arr, n);
	printf("The sorted array is: \n");
	printarray(arr, n);
	return 0;
}


void arrayinput(int arr[], int n){
	int i;
	printf("Enter the elements of the array: \n");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
}

void insertionsort(int arr[], int n){
	int i, temp, j;
	for(i=1; i<n; i++){
		temp=arr[i];
		j=i-1;
			while(arr[j]>temp && j>=0){
				arr[j+1]=arr[j];
				j--;
		}
		arr[j+1]=temp;
	}
}

void printarray(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
}
