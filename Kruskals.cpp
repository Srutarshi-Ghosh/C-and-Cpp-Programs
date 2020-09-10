#include<stdio.h>
#include<stdlib.h>

typedef struct Edge{
	int start;
	int end;
	int weight;
}edge;

typedef struct Node{
	int data;
	struct Node *next = NULL;
}node;

typedef struct Set{
	int val;
	node *head;
	node *tail;
}set;


void print_graph(int**, int);
void edgeSort(edge*, int);
void swapEdge(edge*, int, int);
int kruskals(int**, int);
void insertAtEnd(set*, int, int);
void set_union(set*, int, int);
int check_cycle(set*s, int , int);


int main(){
	int edges, i, j, v, a, b, wt, min_cost;
	int **adj;
	printf("Enter number of vertices: ");
	scanf("%d", &v);
	printf("Enter Number of edges: ");
	scanf("%d", &edges);
	
	adj = (int**)malloc(v * sizeof(int*));

	for(i = 0; i < v; i++)
		adj[i] = (int*)calloc(v, sizeof(int));
	
	for(i = 0; i < edges; i++){
		printf("Enter Start, End and Weight of the Edge: ");
		scanf("%d %d %d", &a, &b, &wt);
		
		if(a < 0 || a > v || b < 0 || b > v){
			i--;
			continue;
		}
		adj[a-1][b-1] = wt;
		adj[b-1][a-1] = wt;
	}
	print_graph(adj, v);

	min_cost = kruskals(adj, v);
	printf("Minimum Cost of the spanning tree is %d\n", min_cost);
	
	return 0;
	
}


void print_graph(int **adj, int ver){
	int i, j;
	
	for(i = 0; i < ver; i++){
		for(j = 0; j < ver; j++){
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
}

void edgeSort(edge *e, int n){
	int i, j;
	for(i = 0; i < n -1; i++){
		for(j = 0; j < n -i -1; j++){
			if(e[j].weight > e[j+1].weight)
				swapEdge(e, j, j+1);
		}
	}
	
}


void swapEdge(edge *e, int a, int b){
	edge temp = e[a];
	e[a] = e[b];
	e[b] = temp;
}

void insertAtEnd(set *s, int i, int item){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	newnode->next = NULL;
	if(s[i].head == NULL){
		s[i].head = newnode;
		s[i].tail = newnode;
	}
	else{
		(s[i].tail)->next = newnode;
		s[i].tail = newnode;
	}
}

//void printlist(node *head){
//	node *temp = head;
//	if(temp==NULL)
//		printf("The list is empty\n");
//	else{
//		while(temp!=NULL){
//			printf("%d ", temp->data);
//			temp = temp->next;
//		}
//		printf("\n");
//	}
//}


void set_union(set *s, int a, int b){
	int val;
	(s[a].tail)->next = s[b].head;	
	//s[b].head = s[a].head;
	s[a].tail = s[b].tail;
	node *temp = (s[b].head)->next;
	while(temp != NULL){
		val = temp->data;
		s[val - 1].head = s[a].head;
		temp = temp->next;
	}
	s[b].head = s[a].head;
}

int check_cycle(set *s, int a, int b){
//	printf("cycle %d %d\n", s[a].head, s[b].head);
	if((s[a].head) == (s[b].head))
		return 1;
	return 0;
}


int kruskals(int **adj, int v){
	set *s;
	edge *e;
	node *newnode = (node*)malloc(sizeof(node));
	int i, j, cost = 0, edges = 0;
	
	e = (edge*)malloc(sizeof(edge) * (v*(v+1)/2));
	
	for(i = 1; i < v; i++){
		for(j = 0; j < i; j++){
			if(adj[i][j] > 0){
				e[edges].start = j + 1;
				e[edges].end = i + 1;
				e[edges].weight = adj[i][j];
				edges++;
			}
		}
	}	
	
	edgeSort(e, edges);

	s = (set*)malloc(v * sizeof(set));
	for(i = 0; i < v; i++){
		s[i].head = NULL;
		s[i].tail = NULL;
		insertAtEnd(s, i, i+1);	
	}
	
	for(i = 0; i < edges; i++){		
		if(check_cycle(s, e[i].start - 1, e[i].end - 1))
			continue;
			
		printf("Start: %d End: %d Weight: %d\n", e[i].start, e[i].end, e[i].weight);
		cost += e[i].weight;
		set_union(s, e[i].start - 1, e[i].end - 1);
		//printlist(s[e[i].start - 1].head);
	}
	return cost;
}


