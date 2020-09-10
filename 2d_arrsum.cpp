#include<stdio.h>

int arraysum(int[100][100], int, int);

int main(){
	int n, sum, arr[100][100], i, j, m;
	printf("Enter the no of rows: ");
	scanf("%d", &n);
	printf("Enter the no of columns: ");
	scanf("%d", &m);
	printf("Enter the elements of the array: \n");
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	sum = arraysum(arr, n, m);
	printf("The sum of the elements of the array is %d", sum);
	return 0;
}

int arraysum(int arr[100][100], int n, int m){
	int i, sum=0, j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			sum+=arr[i][j];
		}
	}
	return sum;
}
