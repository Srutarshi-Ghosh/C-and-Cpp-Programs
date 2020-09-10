#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct Node{
	int vertex;
	int edge;
	struct Node *next;
}node;


typedef struct Vertex{
	int dist;
	node *edge_list;
}vertex;

void djikstra(int **, int, int);
void print_graph(int **, int);
void printlist(node *);
void insert_vertex(node **, int, int);
void updateAllConnections(vertex *, int *, int);
int GetMinVertex(vertex *, int *, int);



int main(){
	int **adj, i, j, ver, edges, a, b, wt, src;
	
	printf("Enter Number of vertices: ");
	scanf("%d", &ver);
	
	adj = (int**)malloc(sizeof(int*) * ver);
	for(i = 0; i < ver; i++)
		adj[i] = (int*)calloc(ver, sizeof(int));
		
	
	printf("Enter Number of edges: ");
	scanf("%d", &edges);
	
	for(i = 0; i < edges; i++){
		printf("Enter Edge and weight: ");
		scanf("%d %d %d", &a, &b, &wt);
		if(a < 0 || a > ver || b < 0 || b > ver){
			i--;
			continue;
		}
		adj[a-1][b-1] = wt;
		adj[b-1][a-1] = wt;
	}
	print_graph(adj, ver);
	
	printf("Enter Starting Vertex: ");
	scanf("%d", &src);
	djikstra(adj, ver, src);
}


void print_graph(int **gr, int ver){
	int i, j;
	for(i = 0; i < ver; i++){
		for(j = 0; j < ver; j++){
			printf("%d ", gr[i][j]);
		}
		printf("\n");
	}
}



void insert_vertex(node **head, int vertex, int edge){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->vertex = vertex;
	newnode->edge = edge;
	if(*head == NULL){
		*head = newnode;
		newnode->next = NULL;
	}
	else{
		newnode->next = *head;
		*head = newnode;
	}
}

int getMinVertex(vertex *V, int *visited, int ver){
	int i, min = INT_MAX, v = -1;
	
	for(i = 0; i < ver; i++){
		if(!visited[i] && V[i].dist < min){
			min = V[i].dist;	
			v = i;
		}
	}
	return v;
}

void updateAllConnections(vertex *V, int *visited, int ind){
	int i, val;
	node *trav = V[ind].edge_list;
	
	while(trav != NULL){
		val = trav->vertex-1;
		if(!visited[val] && V[ind].dist + trav->edge < V[val].dist)
			V[val].dist = V[ind].dist + trav->edge;
				
		trav = trav->next;
	}
}




void djikstra(int **adj, int ver, int src){
	vertex *V;
	int i, j, v, *visited, cost = 0;
	
	
	V = (vertex*)malloc(ver * sizeof(vertex));
	for(i = 0; i < ver; i++){
		V[i].dist = INT_MAX;
		V[i].edge_list = NULL;
	}
	V[src-1].dist = 0;
	
	for(i = 1; i < ver; i++){
		for(j = 0; j <= i; j++){
			if(adj[i][j] > 0){
				insert_vertex(&V[i].edge_list, j+1, adj[i][j]);
				insert_vertex(&V[j].edge_list, i+1, adj[i][j]);
			}
		}
	}
	
	visited = (int*)calloc(ver, sizeof(int));
	visited[src-1] = 1;

	for(i = 0; i < ver; i++)
		printlist(V[i].edge_list);
	
	updateAllConnections(V, visited, src-1);
	for(i = 1; i < ver; i++){
		v = getMinVertex(V, visited, ver);
		//printf("Ver: %d\n", v);
		visited[v] = 1;
		cost += V[v].dist;
		updateAllConnections(V, visited, v);
	}
	
	for(i = 0; i < ver; i++){
		printf("%d: %d\n", i+1, V[i].dist);
	}
	printf("\n");
	
}




void printlist(node *head){
	node *temp = head;
	if(temp==NULL)
		printf("The list is empty\n");
	else{
		while(temp!=NULL){
			printf("Vertex: %d Edge: %d\n", temp->vertex, temp->edge);
			temp = temp->next;
		}
		printf("\n");
	}
}



