#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct Node{
	int data;
	struct Node *next;
}node;

typedef struct Queue{
	node *head;
	node *tail;
	int size;
}queue;

void enqueue(queue *, int);
int dequeue(queue *);
void printqueue(queue *);

int main(){
	int ch, flag = 1, elem;
	queue* q = (queue*)malloc(sizeof(queue));
	q->size = 0;
	q->head = q->tail = NULL;
	printf("1. Insert Element\n2. Delete Element\n3. Print Queue\n4. Exit\n");
	while(flag == 1){
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: if(q->size == MAX)
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

	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	newnode->next = NULL;
	if(q->size == 0){
		q->head = q->tail = newnode;
	}
	else{
		(q->head)->next = newnode;
		q->head = newnode;
	}
	q->size++;
	
}

int dequeue(queue *q){
	if(q->size == 0){
		printf("Queue is empty!!\n");
		return -99999;
	}
	
	else{
		int item = (q->tail)->data;
		node *temp = q->tail;
		if(q->size == 1)
			q->head = q->tail = NULL; 
			
		else{
			q->tail = (q->tail)->next;
		}
		free(temp);
		q->size--;
		return item;
	}
}

void printqueue(queue *q){
	if(q->size == 0)
		printf("Queue is Empty!!\n");
	else{
		printf("The Queue is: ");
		node *temp = q->tail;
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}




