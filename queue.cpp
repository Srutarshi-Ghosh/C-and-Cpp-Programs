#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct Queue{
	int front;
	int rear;
	int data[MAX];
}queue;

void enqueue(queue *, int);
int dequeue(queue *);
void printqueue(queue *);

int main(){
	int ch, flag = 1, elem;
	queue* q = (queue*)malloc(sizeof(queue));
	q->front = q->rear = -1;
	printf("1. Insert Element\n2. Delete Element\n3. Print Queue\n4. Exit\n");
	while(flag == 1){
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: if(q->rear - q->front == MAX - 1)
						printf("Queue is full!!\n");
					else{
						printf("Enter Element to Insert: ");
						scanf("%d", &elem);
						enqueue(q, elem);
					}
					break;
					
			case 2: elem = dequeue(q);
					if(elem != -99999)
						printf("The Deleted Element is %d\n", elem);
					break;
					
			case 3: printqueue(q);
					break;
					
			case 4: flag = 0;
					break;
			
			default: printf("Invalid Input!!\n");
		}
	}

	return 0;
}

void enqueue(queue *q, int item){

	if(q->front == -1){
		q->front = q->rear = 0;
		
	}
	else if(q->rear != MAX - 1){
		q->rear++;
	}
	else{
		int i;
		for(i = q->front; i <= q->rear; i++){
			q->data[i - q->front] = q->data[i];
		}
		q->rear -= q->front - 1;
		q->front = 0;
	}
	q->data[q->rear] = item;
}

int dequeue(queue *q){
	if(q->front == -1){
		printf("Queue is empty!!\n");
		return -99999;
	}
	
	else{
		int item = q->data[q->front];
		
		if(q->front == q->rear)
			q->front = q->rear = -1; 
			
		else{
			q->front++;
		}
		return item;
	}
}

void printqueue(queue *q){
	if(q->front == -1)
		printf("Queue is Empty!!\n");
		
	else{
		int count = q->front;
		printf("The Queue is: ");
		while(count != q->rear + 1){
			printf("%d ", q->data[count]);
			count++;
		}
		printf("\n");
	}
}

