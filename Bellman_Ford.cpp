#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct Edge{
	int start;
	int end;
	int weight;
	struct Edge *next;
}Edge;



void bellman_ford(int **, int, int);
void print_graph(int **, int);
void printEdges(Edge *);
void insert_edge(Edge **, int, int, int);
int relaxation(int *, Edge);


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
	}
	print_graph(adj, ver);
	
	printf("Enter Starting Vertex: ");
	scanf("%d", &src);
	bellman_ford(adj, ver, src);
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



void insert_edge(Edge **edge_list, int start, int end, int weight){
	Edge *newedge = (Edge*)malloc(sizeof(Edge));
	newedge->start = start;
	newedge->end = end;
	newedge->weight = weight;
	if(*edge_list == NULL){
		*edge_list = newedge;
		newedge->next = NULL;
	}
	else{
		newedge->next = *edge_list;
		*edge_list = newedge;
	}
}



int relaxation(int *distance, Edge e){
	int start = e.start - 1, end = e.end - 1, weight = e.weight;
	if(distance[start] + weight < distance[end]){
		distance[end] = distance[start] + weight;
		return 1;
	}
	return 0;	
}



void bellman_ford(int **adj, int ver, int src){
	Edge *edge_list = NULL, *trav;
	int i, j, flag = 1, loop_count = 0, *distance;
	
	for(i = 0; i < ver; i++){
		for(j = 0; j < ver; j++){
			if(adj[i][j] != 0)
				insert_edge(&edge_list, i + 1, j + 1, adj[i][j]);
		}
	}
	printEdges(edge_list);
		
	distance = (int*)malloc(ver * sizeof(int));
	for(i = 0; i < ver; i++)
		distance[i] = 999999;
	distance[src-1] = 0;
	
	while(loop_count < ver - 1 && flag){
		flag = 0;
		trav = edge_list;
		while(trav != NULL){
			flag = relaxation(distance, *trav);
			trav = trav->next;
		}
		loop_count++;
	}
	
	for(i = 0; i < ver; i++){
		printf("%d: %d\n", i+1, distance[i]);
	}
	printf("\n");
	
}


void printEdges(Edge *edge_list){
	Edge *temp = edge_list;
	while(temp!=NULL){
		printf("Start: %d End: %d Weight %d\n", temp->start, temp->end, temp->weight);
		temp = temp->next;
	}
	printf("\n");
}



