#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next = NULL;
	struct Node *prev = NULL;
}node;

void insertAtEnd(node**, node **, int);
void insertAtBegin(node**, node **, int);
void insertAtPosition(node **, node **, int, int);
int deleteFromBegin(node **, node **);
int deleteFromEnd(node **, node **);
int deleteFromPosition(node **, node **, int);
int listlen(node *, node *);
int searchlist(node *, node *, int);
void printlist(node*, node *);


int main(){
	
	node *head = NULL, *tail = NULL;
	int ch, elem, pos, flag = 1;
	printf("1. Insert at Begin\n2. Insert at End\n3. Insert at Position\n4. Delete from Begin\n5. Delete from End\n6. Delete from Position\n7. Search Element\n8. Length of List\n9. Print List\n10. Exit\n");
	
	while(flag){
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: printf("Enter Element to Insert at Begin: ");
					scanf("%d", &elem);
					insertAtBegin(&head, &tail, elem);
					break;
					
			case 2: printf("Enter Element to Insert at End: ");
					scanf("%d", &elem);
					insertAtEnd(&head, &tail, elem);
					break;
					
			case 3: printf("Enter Element to Insert at Position: ");
					scanf("%d", &elem);
					printf("Enter Position: ");
					scanf("%d", &pos);
					insertAtPosition(&head, &tail, pos, elem);
					break;
					
			case 4: elem = deleteFromBegin(&head, &tail);
					if(elem != -99999)
						printf("The Deleted Element is %d\n", elem);
					break;
						
			case 5: elem = deleteFromEnd(&head, &tail);
					if(elem != -99999)
						printf("The Deleted Element is %d\n", elem);
					break;
						
			case 6: printf("Enter Position to Delete from: ");
					scanf("%d", &pos);
					elem = deleteFromPosition(&head, &tail, pos);
					if(elem != -99999)
						printf("The Deleted Element is %d\n", elem);
					break;
						
			case 7: printf("Enter Element to search: ");
					scanf("%d", &elem);
					pos = searchlist(head, tail, elem);
					if(pos == -1)
						printf("Element not present in the List!!\n");
					else
						printf("The position of the element is %d\n", pos);
					break;
						
			case 8: printf("The Length of the List is %d\n", listlen(head, tail));
					break;
			
			case 9: printf("The List is ");
					printlist(head, tail);
					break;
			
			case 10: flag = 0;
					 break;
					 
			default: printf("Invalid Input!!\n");
		}
	}
	return 0;
}

void insertAtBegin(node **head, node **tail, int item){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	
	if(*head == NULL){
		*head = *tail = newnode->next = newnode->prev = newnode;
	}
	else{
		(*head)->prev = (*tail)->next = newnode;
		newnode->next = *head;
		newnode->prev = *tail;
		*head = newnode;
	}
}

void insertAtEnd(node **head, node **tail, int item){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	if(*head==NULL){
		*head = *tail = newnode->next = newnode->prev = newnode;
	}
	else{
		newnode->next = *head;
		newnode->prev = *tail;
		(*tail)->next = (*head)->prev = newnode;
		*tail = newnode;
	}
}

void insertAtPosition(node **head, node **tail, int pos, int item){
	int len = listlen(*head, *tail);
	if(pos > len + 1 || pos < 1)
		printf("Invalid Position!!\n");
		
	else if(pos == 1)
		insertAtBegin(head, tail, item);
		
	else if(pos == len + 1)
		insertAtEnd(head, tail, item);
	
	else{
		node *newnode = (node*)malloc(sizeof(node)), *temp = *head;
		newnode->data = item;
		while(pos != 2){
			pos--;
			temp = temp->next;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		(temp->next)->prev = newnode;
		temp->next = newnode;
	}
}

int deleteFromBegin(node **head, node **tail){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return -99999;
	}
	node *temp = *head;
	int item = temp->data; 
	
	if(*head == *tail){
		*head = *tail = NULL;
		free(temp);
	}
	
	else{
		*head = (*head)->next;
		(*head)->prev = *tail;
		(*tail)->next = *head;
		free(temp);
	}
	return item;
	
}

int deleteFromEnd(node **head, node **tail){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return -99999;
	}
	
	node *temp = *tail;
	int item = (*tail)->data;
	
	if(*head == *tail){
		*head = *tail = NULL;
		free(temp);
	}
	
	else{
		(*tail) = (*tail)->prev;
		(*tail)->next = *head;
		(*head)->prev = *tail;
		free(temp);
	}
	return item;
	
}

int deleteFromPosition(node **head, node **tail, int pos){
	int len = listlen(*head, *tail);
	if(pos > len || pos < 0){
		printf("Invalid Position!!\n");
		return -99999;
	}
	int item;
	if(pos == 1)
		item = deleteFromBegin(head, tail);
		
	else if(pos == len)
		item = deleteFromEnd(head, tail);
	
	else{
		node *temp = *head;
		while(pos != 2){
			pos--;
			temp = temp->next; 
		}
		node *t = temp->next;
		item = (temp->next)->data;
		temp->next = t->next;
		(t->next)->prev = temp;
		free(t);
	}
	return item;
	
}

int listlen(node *head, node *tail){
	if(head == NULL)
		return 0;
		
	int count = 1;
	node *temp = head;
	while(temp != tail){
		count++;
		temp = temp->next;
	}
	return count;
}

int searchlist(node *head, node *tail, int item){
	int pos = 1;
	node *temp = head;
	while(temp != tail){
		if(item == temp->data)
			return pos;
		pos++;
		temp = temp->next;
	}
	if(temp->data == item)
		return pos;
	return -1;
	
}

void printlist(node *head, node *tail){
	node *temp = head;
	if(temp==NULL)
		printf("empty\n");
	else{
		while(temp != tail){
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("%d\n", temp->data);
	}
}

