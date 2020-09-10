#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct Edges{
	int vertex;
	int edge_length;
}Edge;

typedef struct Heap{
	int size;
	int capacity;
	Edge *e;
}heap;


typedef struct Vertex{
	int dist;
	heap *edge_list;
}vertex;


void djikstra(int **, int, int);
void print_graph(int **, int);
void printHeap(heap *);
void insert_vertex(heap *, int, int);
void swap(Edge*, Edge*);


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



void insert_vertex(heap *h, int vertex, int edge){	
	int i = h->size++;
	
	h->e[i].vertex = vertex;
	h->e[i].edge_length = edge;
	
	while(i > 0 && h->e[(i-1)/2].edge_length > h->e[i].edge_length){
		swap(&(h->e[i]), &(h->e[(i-1)/2]));
		i = (i-1)/2;
	}
	
}

Edge get_minimum(heap *h){

	Edge min = h->e[0], last = h->e[--h->size];	
	int i, child;
	
	for(i = 0; (i*2)+1 < h->size; i = child){
		
		child = (i*2) + 1;
		if(child != h->size && h->e[child+1].edge_length < h->e[child].edge_length)
			child++;
			
		if(last.edge_length > h->e[child].edge_length)
			h->e[i] = h->e[child];
		else{
			break;
		}
	}

	h->e[i] = last;
	return min;
}

void printHeap(heap *h){
	if(h->size == 0)
		printf("Empty\n");
		
	else{
		int i;
		for(i = 0; i < h->size; i++)
			printf("Vertex %d Edge Length %d\n", h->e[i].vertex, h->e[i].edge_length);
		
		printf("\n");
	}
}


void swap(Edge* a, Edge* b){
	Edge temp = *a;
	*a = *b;
	*b = temp;
}



void djikstra(int **adj, int ver, int src){
	vertex *V;
	int i, j, *visited, cost = 0;
	Edge curr_min;
	
	V = (vertex*)malloc(ver * sizeof(vertex));
	for(i = 0; i < ver; i++){
		V[i].dist = INT_MAX;
		V[i].edge_list = (heap*)malloc(sizeof(heap));
		V[i].edge_list->capacity = ver - 1;
		V[i].edge_list->e = (Edge*)malloc((ver - 1) * sizeof(Edge));
		V[i].edge_list->size = 0;
	}
	V[src-1].dist = 0;
	
	for(i = 1; i < ver; i++){
		for(j = 0; j <= i; j++){
			if(adj[i][j] > 0){
				//printf("x %d %d\n", i, j);
				insert_vertex(V[i].edge_list, j+1, adj[i][j]);
				insert_vertex(V[j].edge_list, i+1, adj[i][j]);
			}
		}
	}
	
	visited = (int*)calloc(ver, sizeof(int));
	visited[src-1] = 1;

	for(i = 0; i < ver; i++)
		printHeap(V[i].edge_list);
	

}


//void printlist(node *head){
//	node *temp = head;
//	if(temp==NULL)
//		printf("The list is empty\n");
//	else{
//		while(temp!=NULL){
//			printf("Vertex: %d Edge: %d\n", temp->vertex, temp->edge);
//			temp = temp->next;
//		}
//		printf("\n");
//	}
//}



