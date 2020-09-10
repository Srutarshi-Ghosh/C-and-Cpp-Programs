#include<stdio.h>
#include<stdlib.h>


typedef struct Queue{
	int *arr;
	int front;
	int rear;
	int size;
}queue;

void print_graph(int**, int);
void enqueue(queue *, int);
int dequeue(queue *);
void BFS(int**, int, int);


//print_stack(stack *stk){
//	for(int i = 0; i <= stk->top; i++){
//		printf("The stack is %d ", stk->arr[i]);
//	}
//	printf("\n");
//}



int main(){
	int ver, edges, a, b, i, start, **adj;
	printf("Enter Number of vertices: ");
	scanf("%d", &ver);
	
	adj = (int**)malloc(sizeof(int*) * ver);
	for(i = 0; i < ver; i++){
		adj[i] = (int*)calloc(ver, sizeof(int));
	}
	
	printf("Enter Number of edges: ");
	scanf("%d", &edges);
	
	for(i = 0; i < edges; i++){
		printf("Enter Edges: ");
		scanf("%d %d", &a, &b);
		if(a < 0 || a > ver || b < 0 || b > ver){
			i--;
			continue;
		}
		adj[a-1][b-1] = 1;
		adj[b-1][a-1] = 1;
	}
	print_graph(adj, ver);
	printf("Enter Starting vertex: ");
	scanf("%d", &start);
	BFS(adj, ver, start);
	
}


void print_graph(int** adj, int ver){
	int i, j;
	
	for(i = 0; i < ver; i++){
		for(j = 0; j < ver; j++){
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}	
}


void enqueue(queue *q, int item){

	if(q->front == -1){
		q->front = q->rear = 0;
		
	}
	else if(q->rear != q->size - 1){
		q->rear++;
	}
	else{
		int i;
		for(i = q->front; i <= q->rear; i++){
			q->arr[i - q->front] = q->arr[i];
		}
		q->rear -= q->front - 1;
		q->front = 0;
	}
	q->arr[q->rear] = item;
}

int dequeue(queue *q){
	if(q->front == -1){
		printf("Queue is empty!!\n");
		return -99999;
	}
	
	else{
		int item = q->arr[q->front];
		
		if(q->front == q->rear)
			q->front = q->rear = -1; 
			
		else{
			q->front++;
		}
		return item;
	}
}

void BFS(int** adj, int ver, int start){
	int n = ver, st, i, flag;
	int *visited = (int*)calloc(n, sizeof(int));
	
	queue *q = (queue*)malloc(sizeof(queue));
	q->arr = (int*)malloc(sizeof(int) * n);
	q->front = q->rear = 0;
	q->size = n;
	q->arr[q->front] = start - 1;
	
	visited[start -1] = 1;
	printf("%d\n", start);
	
	while(q->front != -1){
		st = q->arr[q->front];
		flag = 0;
		for(i = 0; i < n; i++){
			if(adj[st][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				enqueue(q, i);
				printf("%d\n", i+1);
			}
		}
		
		dequeue(q);
		
	}
	
}




