#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

void insertatbegin(node**, int);
void printlist(node*);


int main(){
	
	node *head = NULL;
	insertatbegin(&head, 10);
	insertatbegin(&head, 20);
	printlist(head);
}

void insertatbegin(node **list, int val){
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = val;
	if(*list==NULL){
		temp->next = NULL;
	}
	else{
		temp->next = *list;
	}
	*list = temp;
}

void printlist(node *list){
	node *temp = list;
	if(temp==NULL)
		printf("The list is empty");
	else{
		while(temp!=NULL){
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
}
