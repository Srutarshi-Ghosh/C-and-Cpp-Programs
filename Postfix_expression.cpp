#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct C_Node{
	char data;
	struct C_Node *next;
}c_node;

typedef struct F_Node{
	float data;
	struct F_Node *next;
}f_node;

typedef struct C_Stack{
	int top;
	c_node *head;
}c_stk;

typedef struct F_Stack{
	int top;
	f_node *head;
}f_stk;

void c_push(c_stk *, char);
void f_push(f_stk *, int);
float f_pop(f_stk *);
char c_pop(c_stk *);
float calc_exp(char[]);
void printstack(c_stk *);

int main(){
	int ch, flag = 1;
	float ans;
	char str[100];
	printf("Enter the expression: ");
	scanf("%s", str);
	ans = calc_exp(str);
	printf("The answer to the expression %s is %f", str, ans);

	return 0;
}

void c_push(c_stk *s, char item){
	
	c_node* newnode = (c_node*)malloc(sizeof(c_node));
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

void f_push(f_stk *s, float item){
	
	f_node* newnode = (f_node*)malloc(sizeof(f_node));
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

char c_pop(c_stk *s){
	if(s->top == -1){
		return '_';
	}
	
	else{
		char item = (s->head)->data;
		c_node *temp = s->head;
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

float f_pop(f_stk *s){
	if(s->top == -1){
		return -99999;
	}
	
	else{
		float item = (s->head)->data;
		f_node *temp = s->head;
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


float calc_exp(char str[]){
	int i, len = strlen(str);
	float val, x;
	char c;
	c_stk *exp = (c_stk*)malloc(sizeof(c_stk));
	f_stk *res = (f_stk*)malloc(sizeof(f_stk));
	exp->top = res->top = -1;
	exp->head = NULL; 
	res->head = NULL;
	
	if(str[0] != '(' && str[len-1] != ')'){
		printf("Non ambiguous Expression!!\n");
		return -99999;
	}
	
	for(i = 0; i < strlen(str); i++){
		if(str[i] == '('){
			c_push(exp, str[i]);
		}
		
		else if(str[i] >= '0' && str[i] <= '9'){
			val = 0;
			while(str[i] >= '0' && str[i] <= '9'){
				x = (int)str[i] - (int)'0';
				val += x;
				val *= 10;
				i++;
			}
			val /= 10;
			i--;
			f_push(res, val);
		}
		else if(str[i] == ')'){
			c = c_pop(exp);
			if(c == '+'){
				x = f_pop(res);
				val = f_pop(res);
				val += x;
			}
			else if(c == '-'){
				x = f_pop(res);
				val = f_pop(res);
				val -= x;
			}
			else if(c == '*'){
				x = f_pop(res);
				val = f_pop(res);
				val *= x;
			}
			else if(c == '/'){
				x = f_pop(res);
				val = f_pop(res);
				val /= x;
			}
			else{
				printf("Error!! Invalid Expression!!\n");
				return -99999;
			}
			f_push(res, val);
			c = c_pop(exp);
		}
		else{
			c_push(exp, str[i]);
		}
	
	//	printstack(exp);
	}
	if(exp->top != -1 && res->top != 0){
		printf("Error!! Invalid Expression!!\n");
		return -99999;
	}
	
	return (res->head)->data;
}

/*void printstack(c_stk *s){
	if(s->top == -1)
		printf("Queue is Empty!!\n");
	else{
		printf("The Stack is: ");
		c_node *temp = s->head;
		while(temp != NULL){
			printf("%c ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
*/

