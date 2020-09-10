#include<stdio.h>
#include<stdlib.h>
#define CAP 10

typedef struct Heap{
	int *arr;
	int size;
	int capacity;
}heap;


void insert(heap*, int);
int deleteMin(heap*);
int deleteIndex(heap*, int);
void printHeap(heap*);
void swap(int*, int*);
void heapify(heap*);

int main(){
	int elem, ind, ch, flag = 1;
	heap *h = (heap*)malloc(sizeof(heap));
	h->capacity = CAP;
	h->arr = (int*)malloc(sizeof(int)*CAP);
	h->size = 0;
	
	for(h->size = 0; h->size < 5; h->size++){
		//scanf("%d", &h->arr[h->size]);
		h->arr[h->size] = 5 - h->size;
		
	}
	printHeap(h);
	heapify(h);
	printHeap(h); 
	
	
	printf("1. Insert\n2. Delte Index\n3. Delete Minimum\n4. Print Heap\n5. Exit\n");
	
	while(flag){

		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch){
			
			case 1: printf("Enter Element to Insert: ");
					scanf("%d", &elem);
					insert(h, elem);
					break;
						
			case 2: printf("Enter Index to Delete: ");
					scanf("%d", &ind);
					elem = deleteIndex(h, ind);
					if(elem != INT_MAX)
						printf("The Deleted Element is %d\n", elem);
					else
						printf("Invalid Index!!\n");
					break;
					
			case 3: if(h->size == 0)
						printf("Heap is Empty!!\n");
					else
						printf("The Minimum Element is %d\n", deleteMin(h));
					break;
				
			case 4: printf("The Heap is ");
					printHeap(h);
					break;
					
			case 5: flag = 0;
					break;
			
			default: printf("Invalid Input!!\n");
			
		}
		
	}	
	
	return 0;
}


void insert(heap *h, int elem){
	if(h->size == h->capacity)
		printf("Heap is full!!\n");
	
	else{
		int i = h->size++;
		h->arr[i] = elem;
		
		while(i > 0 && h->arr[(i-1)/2] > h->arr[i]){
			swap(&(h->arr[i]), &(h->arr[(i-1)/2]));
			i = (i-1)/2;
		}
	}
}


int deleteIndex(heap *h, int ind){
	if(ind > h->size - 1)
		return INT_MAX;
		
	int i, child, elem = h->arr[ind], last = h->arr[--h->size];
	
	for(i = ind; (i*2)+1 < h->size; i = child){
		
		child = (i*2) + 1;
		if(child != h->size && h->arr[child+1] < h->arr[child])
			child++;
			
		if(last > h->arr[child])
			h->arr[i] = h->arr[child];
		else{
			break;
		}
	}

	h->arr[i] = last;
	return elem;
}


int deleteMin(heap *h){
	return deleteIndex(h, 0);
}


void printHeap(heap *h){
	if(h->size == 0)
		printf("Empty\n");
		
	else{
		int i;
		for(i = 0; i < h->size; i++){
			printf("%d ", h->arr[i]);
		}		
		printf("\n");
	}
}


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


//void heapify(heap *h, int ind){
//	int smallest = ind;
//	int parent = (ind-1)/2;
//	
//	if(parent < h->size && h->arr[smallest] < h->arr[parent])
//		smallest = parent;
//
//	if(smallest != ind){
//		swap(&h->arr[smallest], &h->arr[ind]);
//		heapify(h, parent);
//	}
//}

void heapify(heap *h){
	int sm, l, r, i, k;
	
	for(i = h->size-1; i >= 0; i--){
		k = i;
		do{
			l = (2 * k) + 1;
			if(l < h->size)
				sm = l;
			else
				break;
			
			r = l + 1;
			if(r < h->size && h->arr[r] < h->arr[l]){
				sm = r;
			}
			
			if(h->arr[sm] < h->arr[k]){
				swap(&h->arr[k], &h->arr[sm]);
				printf("%d\n", sm);	
				k = sm;		
			}
			else
				break;
			//printf("%d ", i);
			
		}while(k < h->size);
		//printHeap(h);
	}
}




