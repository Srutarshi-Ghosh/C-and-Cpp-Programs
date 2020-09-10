#include<stdio.h>
#include<stdlib.h>


typedef struct Stack{
	int *arr;
	int top;
	int size;
}stack;

void print_graph(int**, int);
void push(stack*, int);
int pop(stack*);
void DFS(int**, int, int);



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
		printf("Enter Edge: ");
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
	DFS(adj, ver, start);
	
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

void push(stack *stk, int elem){
	if(stk->top < stk->size)
		stk->arr[++stk->top] = elem;
}

int pop(stack *stk){
	if(stk->top == -1)
		return -99999;
	return stk->arr[stk->top--];
}

void DFS(int **adj, int ver, int start){
	int n = ver, st, i, flag;
	int *visited = (int*)calloc(n, sizeof(int));
	stack *stk = (stack*)malloc(sizeof(stk));
	stk->arr = (int*)malloc(sizeof(int) * n);
	stk->top = 0;
	stk->size = n;
	stk->arr[stk->top] = start - 1;
	visited[start -1] = 1;
	printf("%d\n", start);
	
	while(stk->top != -1){
		st = stk->arr[stk->top];
		flag = 0;
		for(i = 0; i < n; i++){
			if(adj[st][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				push(stk, i);
				flag = 1;
				printf("%d\n", i+1);
				break;
			}
		}
		if(!flag){
			pop(stk);
		}
		
	}
	
}




