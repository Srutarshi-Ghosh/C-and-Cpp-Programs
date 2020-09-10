#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next = NULL;
}node;

void insertAtEnd(node**, int);
void insertAtBegin(node**, int);
void insertAtPosition(node **, int, int);
int deleteFromBegin(node **);
int deleteFromEnd(node **);
int deleteFromPosition(node **, int);
int listlen(node *);
int searchlist(node *, int);
void printlist(node*);
void reverselist(node **);


int main(){
	
	node *head = NULL;
	int ch, elem, pos, flag = 1;
	printf("1. Insert at Begin\n2. Insert at End\n3. Insert at Position\n4. Delete from Begin\n5. Delete from End\n6. Delete from Position\n7. Search Element\n8. Length of List\n9. Print List\n10. Reverse List\n11. Exit\n");
	
	while(flag){
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: printf("Enter Element to Insert at Begin: ");
					scanf("%d", &elem);
					insertAtBegin(&head, elem);
					break;
					
			case 2: printf("Enter Element to Insert at End: ");
					scanf("%d", &elem);
					insertAtEnd(&head, elem);
					break;
					
			case 3: printf("Enter Element to Insert at Position: ");
					scanf("%d", &elem);
					printf("Enter Position: ");
					scanf("%d", &pos);
					insertAtPosition(&head, pos, elem);
					break;
					
			case 4: elem = deleteFromBegin(&head);
					if(elem != -99999)
						printf("The Deleted Element is %d\n", elem);
					break;
						
			case 5: elem = deleteFromEnd(&head);
					if(elem != -99999)
						printf("The Deleted Element is %d\n", elem);
					break;
						
			case 6: printf("Enter Position to Delete from: ");
					scanf("%d", &pos);
					elem = deleteFromPosition(&head, pos);
					if(elem != -99999)
						printf("The Deleted Element is %d\n", elem);
					break;
						
			case 7: printf("Enter Element to search: ");
					scanf("%d", &elem);
					pos = searchlist(head, elem);
					if(pos == -1)
						printf("Element not present in the List!!\n");
					else
						printf("The position of the element is %d\n", pos);
					break;
						
			case 8: printf("The Length of the List is %d\n", listlen(head));
					break;
			
			case 9: printf("The List is: ");
					printlist(head);
					break;
			
			case 10: reverselist(&head);
					 printf("The List has been Reversed!\n");
					 break;
			
			case 11: flag = 0;
					 break;
					 
			default: printf("Invalid Input!!\n");
		}
	}
	return 0;
	
}

void insertAtBegin(node **head, int item){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	if(*head == NULL){
		*head = newnode;
		newnode->next = NULL;
	}
	else{
		newnode->next = *head;
		*head = newnode;
	}
}


void insertAtEnd(node **head, int item){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	newnode->next = NULL;
	if(*head==NULL){
		*head = newnode;
	}
	else{
		node *temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
	}

}

void insertAtPosition(node **head, int pos, int item){
	int len = listlen(*head);
	if(pos > len + 1 || pos < 1)
		printf("Invalid Position!!\n");
		
	else if(pos == 1)
		insertAtBegin(head, item);
		
	else if(pos == len + 1)
		insertAtEnd(head, item);
	
	else{
		node *newnode = (node*)malloc(sizeof(node)), *temp = *head;
		newnode->data = item;
		while(pos != 2){
			pos--;
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

int deleteFromBegin(node **head){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return -99999;
	}
	
	node *temp = *head;
	int item = temp->data;
	if(temp->next == NULL){
		*head = NULL;
		free(temp);
	}
	else{
		*head = (*head)->next;
		free(temp);
	}
	return item;
	
}

int deleteFromEnd(node **head){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return -99999;
	}
	
	node *temp = *head;
	int item;
	if(temp->next == NULL){
		item = temp->data;
		*head = NULL;
		free(temp);
	}
	else{
		node *t;
		while((temp->next)->next != NULL){
			temp = temp->next;
		}
		item = (temp->next)->data;
		t = temp->next;
		temp->next = NULL;
		free(t);
	}
	return item;
	
}

int deleteFromPosition(node **head, int pos){
	int len = listlen(*head);
	if(pos > len || pos < 0){
		printf("Invalid Position!!\n");
		return -99999;
	}
	int item;
	if(pos == 1)
		item = deleteFromBegin(head);
		
	else if(pos == len)
		item = deleteFromEnd(head);
	
	else{
		node *temp = *head;
		while(pos != 2){
			pos--;
			temp = temp->next; 
		}
		node *t = temp->next;
		item = t->data;
		temp->next = t->next;
		free(t);
	}
	return item;
	
}

int listlen(node *head){
	int count = 0;
	node *temp = head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

int searchlist(node *head, int item){
	int pos = 1;
	while(head != NULL){
		if(item == head->data)
			return pos;
		pos++;
		head = head->next;
	}
	return -1;
	
}

void printlist(node *head){
	node *temp = head;
	if(temp==NULL)
		printf("The list is empty\n");
	else{
		while(temp!=NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void reverselist(node **head){
	node *prev, *curr = *head, *temp;
	prev = temp = NULL;
	
	while(curr != NULL){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	
	*head = prev;
}

