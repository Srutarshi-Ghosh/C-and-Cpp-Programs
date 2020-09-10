#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct Node{
	int data;
	struct Node *next;
}node;

typedef struct Stack{
	int top;
	node *head;
}stk;

void push(stk *, int);
int pop(stk *);
int peek(stk *);
void printstack(stk *);

int main(){
	int ch, flag = 1, elem;
	stk* s = (stk*)malloc(sizeof(stk));
	s->top = -1;
	s->head = NULL;
	printf("1. Insert Element\n2. Delete Element\n3. Peek\n4. Print Stack\n5. Exit\n");
	while(flag == 1){
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: if(s->top == MAX - 1)
						printf("Stack is full!!\n");
					else{
						printf("Enter Element to Insert: ");
						scanf("%d", &elem);
						push(s, elem);
					}
					break;
					
			case 2: elem = pop(s);
					if(elem != -99999)
						printf("The Deleted Element is %d\n", elem);
					break;
					
			case 3: elem = peek(s);
					if(elem != -99999)
						printf("The element at the top of the stack is %d\n", elem);
					break;
						
			case 4: printstack(s);
					break;
					
			case 5: flag = 0;
					break;
			
			default: printf("Invalid Input!!\n");
		}
	}

	return 0;
}

void push(stk *s, int item){

	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	
	if(s->top == -1){
		s->head = newnode;
		(s->head)->next = NULL;
	}
	else{
		newnode->next = s->head;
		s->head = newnode;
	}
	s->top++;
	
}

int pop(stk *s){
	if(s->top == -1){
		printf("Stack is empty!!\n");
		return -99999;
	}
	
	else{
		int item = (s->head)->data;
		node *temp = s->head;
		if(s->top == 0)
			s->head = NULL; 
			
		else{
			s->head = (s->head)->next;
		}
		free(temp);
		s->top--;
		return item;
	}
}

int peek(stk *s){
	if(s->top == -1){
		printf("Stack is empty!!\n");
		return -99999;
	}
	return (s->head)->data;
}

void printstack(stk *s){
	if(s->top == -1)
		printf("Queue is Empty!!\n");
	else{
		printf("The Stack is: ");
		node *temp = s->head;
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

