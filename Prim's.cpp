#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void print_graph(int**, int);
void printMST(int**, int**, int);
int prims(int**, int, int);



//print_stack(stack *stk){
//	for(int i = 0; i <= stk->top; i++){
//		printf("The stack is %d ", stk->arr[i]);
//	}
//	printf("\n");
//}



int main(){
	int ver, edges, a, b, i, start, wt, min_cost, **adj;
	printf("Enter Number of vertices: ");
	scanf("%d", &ver);
	
	adj = (int**)malloc(sizeof(int*) * ver);
	for(i = 0; i < ver; i++){
		adj[i] = (int*)calloc(ver, sizeof(int));
	}
	
	printf("Enter Number of edges: ");
	scanf("%d", &edges);
	
	for(i = 0; i < edges; i++){
		printf("Enter Start, End and Weight of the Edge: ");
		scanf("%d %d %d", &a, &b, &wt);
		
		
		if(a < 0 || a > ver || b < 0 || b > ver){
			i--;
			continue;
		}
		adj[a-1][b-1] = wt;
		adj[b-1][a-1] = wt;
	}
	print_graph(adj, ver);
	printf("Enter Starting vertex: ");
	scanf("%d", &start);
	min_cost = prims(adj, ver, start);
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



int min_key(int **adj, int *visited, int n, int vertice){
	int i, j, min = INT_MAX, ind = -1;
	for(i = 0; i < n; i++){
		if(adj[vertice][i] > 0 && adj[vertice][i] < min && !visited[i]){
			min = adj[vertice][i];
			ind = i;
		}
	}
	return ind;
	
}



int prims(int **adj, int v, int start){
	int k = 0, i, j, key, min, min_cost = 0;
	int *visited = (int*)calloc(v, sizeof(int));
	int **mst = (int**)malloc((v - 1) * sizeof(int*));
	for(i = 0; i < v; i++)
		mst[i] = (int*)calloc(2, sizeof(int));

	visited[start-1] = 1;
	
	while(k < v - 1){
		min = -1;
		for(i = 0; i < v; i++){
			if(visited[i]){
				//printf("i: %d\n", i);
				key = min_key(adj, visited, v, i);
				//printf("val: %d %d\n", adj[i][key], min);
				if(min == -1 || (key != -1 && adj[i][key] <= min)){
					mst[k][0] = i;
					mst[k][1] = key;
					min = adj[i][key];
					//printf("%d\n", key);
				}
			}
		}
		//printf("edge: %d %d\n", mst[k][0] + 1, mst[k][1] + 1);
		visited[mst[k][1]] = 1;
		min_cost += adj[mst[k][0]][mst[k][1]];
		k++;
	}
	
	printMST(mst, adj, v - 1);  
	return min_cost;
}


	
void printMST(int **mst, int **adj, int n) { 
	int i;
    printf("Edge \tWeight\n"); 
    for (i = 0; i < n; i++) 
        printf("%d - %d \t%d \n", mst[i][0] + 1, mst[i][1] + 1, adj[mst[i][0]][mst[i][1]]); 
        
}





