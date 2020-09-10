#include<stdio.h>

int arraysum(int[], int);

int main(){
	int n, sum, arr[100], i;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements of the array: \n");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	sum = arraysum(arr, n);
	printf("The sum of the elements of the array is %d", sum);
	return 0;
}

int arraysum(int arr[], int n){
	int i, sum=0;
	for(i=0; i<n; i++){
		sum+=arr[i];
	}
	return sum;
}
