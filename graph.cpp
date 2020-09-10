#include<stdio.h>
#include<stdlib.h>


typedef struct Edge{
	int e;
	struct Edge *next_edge;
}edge;

typedef struct Node{
	int ver;
	struct Node *next_vertice;
	edge *next_edge;
}node;

typedef struct Stack{
	int *arr;
	int top;
	int size;
}stack;


node *createNode(int);
void insertVertice(node**, int);
void insertEdge(node**, int, int, int);
void addEdge(node**, int);
void displayGraph(node*);
int NofVertices(node*);
void push(stack, int);
int pop(stack);
void DFS(node*);
int checkVisited(int[][2], int, int);


int main(){
	node *graph = NULL;
	int ver, e, ch, flag = 1;
	
	printf("1. Insert Vertice\n2. Insert Undirected Edge\n3. Insert Directed Edge\n4. Show Graph\n5. Deapth First Search\n7. Exit\n\n");
	
	while(flag){
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: printf("Enter Vertice to insert in Graph: ");
					scanf("%d", &ver);
					insertVertice(&graph, ver);
					break;
					
			case 2: printf("Enter first vertice: ");
					scanf("%d", &ver);
					printf("Enter second vertice: ");
					scanf("%d", &e);
					insertEdge(&graph, ver, e, 0);
					break;
					
			case 3: printf("Enter first vertice: ");
					scanf("%d", &ver);
					printf("Enter second vertice: ");
					scanf("%d", &e);
					insertEdge(&graph, ver, e, 1);
					break;
					
			case 4: printf("Graph: \n");
					displayGraph(graph);
					break;
					
			case 5: printf("Deapth First Search: ");
					DFS(graph);
					printf("\n");
					break;
					
			case 7: flag = 0;
					break;
					
			default: printf("Invalid Input!!\n");
		}
		
	}

	
}


node* createNode(int vertice){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->ver = vertice;
	newnode->next_edge = NULL, newnode->next_vertice = NULL;
	return newnode;
}



void insertVertice(node **graph, int vertice){
	
	node *newnode = createNode(vertice), *temp = *graph;
	
	if(*graph == NULL)
		*graph = newnode;
	else{
	
		int flag = 1;
		
		while(temp->next_vertice){
			if(temp->ver == vertice){
				flag = 0;
				break;
			}
			temp = temp->next_vertice;
		}
		
		if(temp->ver == vertice)
			flag = 0;
		
		if(flag){
			temp->next_vertice = newnode;
		}
	}
	
}


void addEdge(node **vert, int e){
	
	edge *newedge = (edge*)malloc(sizeof(edge));
	newedge->e = e;
	newedge->next_edge = NULL;
	
	edge *temp = (*vert)->next_edge;
	if(temp == NULL){
		(*vert)->next_edge = newedge;
	}
	else{
		
		int flag = 0;
		while(temp->next_edge){
			if(temp->e == e){
				flag = 1;
				break;
			}
			temp = temp->next_edge;
		}
		
		if(temp->e == e)
			flag = 1;
		
		if(!flag){
			temp->next_edge = newedge;
		}
	}
}


void insertEdge(node **graph, int vertice, int e, int directed){
	
	node *temp = *graph;
	int flag = 0;
	
	if(temp == NULL){
		insertVertice(graph, vertice);
		addEdge(graph, e);
	}
	else{
	
		while(temp->next_vertice){
			if(temp->ver == vertice){
				addEdge(&temp, e);
				flag = 1;
				break;
			}
			temp = temp->next_vertice;
		}
		if(temp->ver == vertice){
			addEdge(&temp, e);
			flag = 1;
		}
		
		if(!flag){
			insertVertice(&temp, vertice);
			temp = temp->next_vertice;
			addEdge(&temp, e);
		}
	}
	
	if(!directed){
		insertEdge(graph, e, vertice, 1);
	}
	else{
		insertVertice(graph, e);
	}
	
}


void displayGraph(node *graph){
	node *temp = graph;
	edge *trav;
	while(temp){
		trav = temp->next_edge;
		
		if(trav)
			printf("%d->", temp->ver);
		else
			printf("%d", temp->ver);
			
		while(trav){
			printf("%d ", trav->e);
			trav = trav->next_edge;
		}
		printf("\n");
		temp = temp->next_vertice;
	}
	printf("\n");
}

int NofVertices(node *graph){
	int len = 0;
	while(graph != NULL){
		len++;
		graph = graph->next_vertice;
	}
	return len;
}


void push(stack **s, int data){
	
	if((*s)->top != (*s)->size-1)
		(*s)->arr[++(*s)->top] = data;
		
}

int pop(stack **s){
	
	if((*s)->top == -1)
		return -99999;
	
	return (*s)->arr[(*s)->top--];

}

void DFS(node *graph){
	
	if(graph){
		
		int i, flag, lenOfGraph = NofVertices(graph);
		int visited[lenOfGraph][2];
		stack *s = (stack*)malloc(sizeof(int));
		s->arr = (int*)malloc(lenOfGraph*sizeof(int));
		s->size = lenOfGraph;
		
		
		node *temp = graph; 
		s->top = 0;
		s->arr[s->top] = temp->ver;
		
		for(i = 0; i < lenOfGraph; i++){
			visited[i][0] = temp->ver;
			visited[i][1] = 0;
			temp = temp->next_vertice; 
		}
		
		edge *trav = graph->next_edge;
		
		
		while(s->top != -1){
			temp = graph;
			while(temp->ver != s->arr[s->top]){
				temp = temp->next_vertice;
			} 
			trav = temp->next_edge;
			//printf("%d ", s->arr[s->top]);
			flag = 0;
			while(trav){
				if(checkVisited(visited, lenOfGraph, trav->e)){
					trav = trav->next_edge;
				}
				else{
					for(i = 0; i < lenOfGraph; i++){
						if(visited[i][0] == trav->e){
							visited[i][1] = 1;
							printf("%d ", visited[i][0]);
							//printf("%d ", trav->e);
							push(&s, trav->e);
							flag = 1;
							break;
						}
					}
				}
				if(flag)
					break;
			}
			if(trav == NULL){
				pop(&s);
				
			}		
			
		}
	
	}
	else{
		printf("The graph is empty!\n");
	}
	
	
}

int checkVisited(int visited[][2], int n, int ver){
	int i;
	for(i = 0; i < n; i++){
		if(visited[i][0] == ver){
			//printf("\n%d ", visited[i][1]);
			if(visited[i][1] == 1)
				return 1;
			else
				return 0;
		}
	}
}

