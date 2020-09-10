#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int coeff, power;
	struct Node *next = NULL;
}poly;

void insertAtEnd(poly**, int, int);
void insertAtBegin(poly**, int, int);
void insertAtPosition(poly**, int, int, int);
int no_of_terms(poly*);
void printpolynomial(poly*);
void input_polynomial(poly**);
poly* polynomial_add(poly**, poly**);

int main(){
	
	poly *p1 = NULL, *p2 = NULL, *res = NULL;
	int ch, elem, pos, flag = 1;
	
	input_polynomial(&p1);
	printf("First polynomial is: \n");
	printpolynomial(p1);
	
	input_polynomial(&p2);
	printf("Second polynomial is: \n");
	printpolynomial(p2);
	
	res = polynomial_add(&p1, &p2);
	printf("Resulting polynomial is: \n");
	printpolynomial(res);
	
}

void insertAtBegin(poly **p, int coeff, int power){
	poly* newnode = (poly*)malloc(sizeof(poly));
	newnode->coeff = coeff;
	newnode->power = power;
	if(*p == NULL){
		*p = newnode;
		newnode->next = NULL;
	}
	else{
		newnode->next = *p;
		*p = newnode;
	}
}


void insertAtEnd(poly **p, int coeff, int power){
	poly *newnode = (poly*)malloc(sizeof(poly));
	newnode->coeff = coeff;
	newnode->power = power;
	newnode->next = NULL;
	if(*p==NULL){
		*p = newnode;
	}
	else{
		poly *temp = *p;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
	}

}

void insertAtPosition(poly **p, int coeff, int power, int pos){
	int len = no_of_terms(*p);
	if(pos > len + 1 || pos < 1)
		printf("Invalid Position!!\n");
		
	else if(pos == 1)
		insertAtBegin(p, coeff, power);
		
	else if(pos == len + 1)
		insertAtEnd(p, coeff, power);
	
	else{
		poly *newnode = (poly*)malloc(sizeof(poly)), *temp = *p;
		newnode->coeff = coeff;
		newnode->power = power;
		while(pos != 2){
			pos--;
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
}



int no_of_terms(poly *p){
	int count = 0;
	poly *temp = p;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}


void printpolynomial(poly *p){
	poly *temp = p;
	if(temp==NULL)
		printf("0\n");
	else{
		while(temp!=NULL){
			printf("%dx^%d ", temp->coeff, temp->power);
			temp = temp->next;
		}
		printf("\n");
	}
}

void input_polynomial(poly **p){
	
	int coeff, power, flag, pos;
	printf("Enter Polynomial\n");
	do{
		pos = 1;
		printf("Enter coefficient of the term: ");
		scanf("%d", &coeff);
		printf("Enter power of the term: ");
		scanf("%d", &power);
		if(*p == NULL)
			insertAtBegin(p, coeff, power);
		else{
			poly *temp = *p;
			while(temp != NULL && power < temp->power){
				temp = temp->next;
				pos++;
			}
			insertAtPosition(p, coeff, power, pos);
		}
		printf("To stop entering terms press 0: ");
		scanf("%d", &flag);
	}while(flag);
	printf("\n");
}

poly* polynomial_add(poly **p1, poly **p2){
	poly *temp1 = *p1, *temp2 = *p2, *res = NULL;
	while(temp1 != NULL && temp2 != NULL){
		
		if(temp1->power == temp2->power){
			insertAtEnd(&res, temp1->coeff + temp2->coeff, temp1->power);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		
		else if(temp1->power > temp2->power){
			insertAtEnd(&res, temp1->coeff, temp1->power);
			temp1 = temp1->next;
		}
		
		else if(temp2->power > temp1->power){
			insertAtEnd(&res, temp2->coeff, temp2->power);
			temp2 = temp2->next;
		}
	}
	
	while(temp1){
		insertAtEnd(&res, temp1->power, temp1->coeff);
		temp1 = temp1->next;
	}
	
	while(temp2){
		insertAtEnd(&res, temp2->power, temp2->coeff);
		temp2 = temp2->next;
	}
	
	return res;
}





