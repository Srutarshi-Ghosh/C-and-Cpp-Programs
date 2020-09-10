#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void hamiltonian_cycle(int **, int, int);
void print_graph(int **, int);
void insert_edge(Edge **, int, int, int);


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
		scanf("%d %d %d", &a, &b);
		if(a < 0 || a > ver || b < 0 || b > ver){
			i--;
			continue;
		}
		adj[a-1][b-1] = 1;
		adj[b-1][a-1] = 1;
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



void hamiltonian_cycle(int **adj, int ver, int src){
	int i, j, k, flag = 1, pos = 1, *cycle, *visited;
	cycle = (int*)calloc(ver, sizeof(int));
	visited = (int*)calloc(ver, sizeof(int));
	
	cycle[0] = src;
	visited[src-1] = 1;
	
	while(1){
		if(pos == ver){
			printCycle(cycle, ver);
			pos--;
			visited[pos] = 0;
			cycle[pos] = 0;
			
		}
		else{
			k = (cycle[pos-1] + 1) % (ver + 1);
			if(k == 0){
				pos--;
			}
			
			do{
				flag = 1;
				if(!visited[k-1] && adj[cycle[pos-1]][k-1]){
					cycle[pos] = k;
					visited[k-1] = 1;
					flag = 0;
				}
				else{
					k = (k + 1) % (ver + 1);
					if(k == 0){
						pos--;
						break;
					}
				}
			}while(flag);
			pos++;
		}
	}
}


void printCycle(int *cycle, int n){
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", cycle[i]);
		
	printf("\n");
}



