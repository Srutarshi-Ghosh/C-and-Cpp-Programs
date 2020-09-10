#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);
void arrayinput(int[], int);
void bubblesort(int[], int);
void merge(int[], int, int, int);
void mergesort(int[], int, int);
void selectionsort(int[], int);
void insertionsort(int[], int);
int partition(int[], int, int);
void quicksort(int[], int, int);
void printarray(int[], int);
int comp(void *, void *);



int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
	int arr[10], n, ch, flag = 1;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	arrayinput(arr, n);
	
//	printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n10. Exit\n");
//	
//	while(flag){
//		printf("Enter your choice: ");
//		scanf("%d", &ch);
//		switch(ch){
//			case 1: bubblesort(arr, n);
//					printarray(arr, n);
//					break;
//					
//			case 2: selectionsort(arr, n);
//					printarray(arr, n);
//					break;
//					
//			case 3: insertionsort(arr, n);
//					printarray(arr, n);
//					break;
//					
//			case 4: mergesort(arr, 0, n-1);
//					printarray(arr, n);
//					break;
//						
//			case 5: quicksort(arr, 0, n-1);
//					printarray(arr, n);
//					break;
//					
//			case 8: flag = 0;
//					 break;
//					 
//			default: printf("Invalid Input!!\n");
//					
//		}

		qsort(arr, n, sizeof(int), comp);
		printarray(arr, n);
	//}

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


void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int left[n1], right[n2];
	
	for (i = 0; i < n1; i++) 
        left[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        right[j] = arr[m + j + 1]; 
	i=0;
	j=0; 
	k=l;
	while(i<n1 && j<n2){
		if(left[i] <= right[j]){
			arr[k]=left[i];
			i++;
		}
		else{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		arr[k]=left[i];
		k++;
		i++;
	}
	
	while(j < n2){
		arr[k]=right[j];
		k++;
		j++;
	}
	
}

void mergesort(int arr[], int l, int r){
	if(l<r){
		int m=(l+r)/2;
		mergesort(arr, l, m);
		mergesort(arr, m+1, r);
		merge(arr, l, m, r);
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

void printarray(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int comp(const void *a, const void *b){
	int *x = (int*)a;
	int *y = (int*)b;
	
	if(*x > *y)
		return 1;
	else if(*y < *x)
		return -1;
	else
		return 0;
}





