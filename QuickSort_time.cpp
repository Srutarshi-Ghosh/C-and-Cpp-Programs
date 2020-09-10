#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quicksort(long long int*, long long int, long long int);
long long int partition(long long int*, long long int, long long int);
void swap(long long int*, long long int*);
void Random(long long int, long long int*);
long long int random_choice(long long int*, long long int);


int main(){

        long long int max_size = 10000000, *random_numbers;
        random_numbers = (long long int*) malloc(max_size * sizeof(long long int));
        long long int i, j, n;
        long long int time[] = {2000000, 4000000, 5000000, 6000000, 8000000, 10000000};

        FILE *fgraph;
        clock_t start, end;
        double func_time;
        fgraph = fopen("QuickSort_Graph.txt", "w");
        for(i = 0; i < 6; i++){
                Random(time[i], random_numbers);
                
                start = clock();
                quicksort(random_numbers, 0, time[i]);
                end = clock();

                func_time = ((double)(end - start)) / CLOCKS_PER_SEC;

                printf("%lld %f\n", time[i], func_time);
                fprintf(fgraph, "%lld %f\n", time[i], func_time);

        }
        fclose(fgraph);
        return 0;

}



void quicksort(long long int arr[], long long int l, long long int r){
	long long int q;
    if(l<r){
		q = partition(arr, l, r);
		quicksort(arr, l, q-1);
		quicksort(arr, q+1, r);
	}
}

long long int partition(long long int arr[], long long int l, long long int h){
	long long int i = l-1, piv = arr[h], j;
	for(j=l; j<h; j++){
		if(arr[j]<=piv){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[h]);
	return i+1;
}


void swap(long long int *a, long long int *b){
        long long int temp = *a;
        *a = *b;
        *b = temp;
}

void Random(long long int n, long long int *arr){
        long long int i;
        for(i = 0; i < n; i++){
                arr[i] = (long long int)rand() % 100000;
        }

}


