#include<stdio.h>
#include<stdlib.h>

void subsets(int[], int, int);

int main(){
	int i, sum=0, size, no, *arr;
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	arr = (int*)malloc(sizeof(int)*size);
	printf("Enter the elements of the array: ");
	for(i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the number: ");
	scanf("%d", &no);
	subsets(arr, size, no);
	return 0;
}
	
void subsets(int arr[], int n, int no){
	
	int i, j, k=0, *a, temp;
	a = (int*)malloc(sizeof(int)*n);

	for(i = 1; i < (1<<n); i++){
		temp = no;
		for(j=0; j<n; j++){
			if((i&(1<<j)) > 0){
				a[k] = arr[j];
				temp -= arr[j];
				k++;
			}
			if(temp < 0)
				break;
		}
		if(temp == 0){
			for(j = 0; j < k; j++){
				printf("%d ", a[j]);
			}
			printf("\n");
		}
		k = 0;
	}
}
