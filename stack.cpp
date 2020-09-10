#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct Stack{
	int top;
	int data[MAX];
}stk;

void push(stk *, int);
int pop(stk *);
int peek(stk *);
void printstack(stk *);

int main(){
	int ch, flag = 1, elem;
	stk *s = (stk*)malloc(sizeof(stk));
	s->top = -1;
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

	s->top++;
	s->data[s->top] = item;
}

int pop(stk *s){
	if(s->top == -1){
		printf("Stack is empty!!\n");
		return -99999;
	}
	
	else{
		int item = s->data[s->top];
		s->top--;
		return item;
	}
}

int peek(stk *s){
	if(s->top == -1){
		printf("Stack is empty!!\n");
		return -99999;
	}
	return s->data[s->top];
}

void printstack(stk *s){
	if(s->top == -1)
		printf("Stack is Empty!!\n");
	else{
		printf("The Stack is: ");
		int count = s->top;
		while(count >= 0){
			printf("%d ", s->data[count]);
			count--;
		}
		printf("\n");
	}
}
