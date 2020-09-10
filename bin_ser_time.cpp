#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mergesort(long long int*, long long int, long long int);
void merge(long long int*, long long int, long long int, long long int);
void bubblesort(long long int[], long long int);
long long int binarysearch(long long int*, long long int, long long int);
void swap(long long int*, long long int*);
void Random(long long int, long long int*);
long long int random_choice(long long int*, long long int);


int main(){

        long long int max_size = 10000000, *random_numbers;
        //arr1 = (long long int*) malloc(max_size * sizeof(long long int));
        //arr2 = (long long int*) malloc(max_size * sizeof(long long int));
        random_numbers = (long long int*) malloc(max_size * sizeof(long long int));
        long long int i, j, n, ser, ind;
        long long int time[] = {2000000, 4000000, 5000000, 6000000, 8000000, 10000000};

        FILE *fgraph;
        clock_t start, end;
        long double func_time;
        fgraph = fopen("Binary_Search_Graph.txt", "w");
        for(i = 0; i < 6; i++){
                Random(time[i], random_numbers);

                mergesort(random_numbers, 0, time[i]);
                ser = random_choice(random_numbers, time[i]);

                start = clock();
                ind = binarysearch(random_numbers, time[i], ser);
                end = clock();

                printf("%d\n", ind);
                func_time = ((long double)(end - start))/CLOCKS_PER_SEC;

                printf("%lld %llf\n", time[i], func_time);
                fprintf(fgraph, "%lld %llf\n", time[i], func_time);

        }
        fclose(fgraph);
        return 0;

}



void mergesort(long long int *arr, long long int l, long long int r){
        if(l < r){
              long long int m = (l + r)/2;
              mergesort(arr, l, m);
              mergesort(arr, m+1, r);
              merge(arr, m, l, r);
        }

}

void merge(long long int *arr, long long int m, long long int l, long long int r){
        long long int i, j, k;
        long long int n1 = m - l + 1;
        long long int n2 = r - m;
        long long int *left, *right;
        left = (long long int*) malloc(n1 * sizeof(long long int));
        right = (long long int*) malloc(n2 * sizeof(long long int));


        for(i = 0; i < n1; i++)
                left[i] = arr[l+i];

        for(j = 0; j < n2; j++)
                right[j] = arr[m+1+j];

        i = 0;
        j = 0;
        k = l;
        while(i < n1 && j < n2){
                if(left[i] <= right[j]){
                        arr[k] = left[i];
                        i++;
                }
                else{
                        arr[k] = right[j];
                        j++;
                }
                k++;
        }

        while(i < n1){
                arr[k] = left[i];
                k++;
                i++;
        }

        while(j < n2){
                arr[k] = right[j];
                k++;
                j++;
        }

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


long long int binarysearch(long long int *arr, long long int n, long long int ser){
        long long int l = 0, mid, r = n - 1;
        mid = (l + r) / 2;
        while(l < r){
                if(arr[mid] == ser)
                        return mid+1;
                else if(arr[mid] > ser)
                        r = mid - 1;
                else
                        l = mid + 1;
                mid = (l + r) / 2;
        }
        return -1;
}


long long int random_choice(long long int *arr, long long int n){
        int no;
        no = rand() % n;
        return arr[no];
}
