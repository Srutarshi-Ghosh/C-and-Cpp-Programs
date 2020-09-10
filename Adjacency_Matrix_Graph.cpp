#include<stdio.h>
#include<stdlib.h>

int** createGraph(int **, int);
void add_node(int **, int, int, int);
void showGraph(int **, int);


int main(){
	int n, **graph, flag = 1, v1, v2, ch;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	graph = createGraph(graph, n);
	printf("1. Add Edge\n5. Display Graph\n6. Exit\n");
	
	while(flag){
		printf("Enter Choice ");
		scanf("%d", &ch);
		switch(ch){
			case 1:	printf("Enter the first vertex of the edge: ");
					scanf("%d", &v1);
					printf("Enter the second vertex of the edge: ");
					scanf("%d", &v2);
					if(v1 < 1 || v1 > n || v2 < 1 || v2 > n){
						printf("Invalid Input!!\n");
					}
					else
						add_node(graph, n, v1-1, v2-1);
					break;
				
			case 5: showGraph(graph, n);
					
			case 6: flag = 0;
					break;
		
			default: printf("Invalid Input!!\n");
		}
	}
}


void add_node(int **graph, int n, int v1, int v2){
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;
}

void createGraph(int **graph, int n){
	int i;
	graph = (int**)malloc(n * sizeof(int*));
	for(i = 0; i < n; i++){
		graph[i] = (int*)calloc(n, sizeof(int));		
	}
	return graph;
}

void showGraph(int **graph, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}	
}


