#include <stdio.h>
#include <stdlib.h>

void setval(int arr[10][10],int, int, int, int, int, int);
int isvalid(int arr[10][10], int, int, int, int, int);
int checkpath(int[10][10], int[10][10], int, int, int, int);

int main() {
	char grid[10][10];
	float safety;
	int n, m, i, j, grassland = 0, val = 0, gate1_x, gate1_y, gate2_x, gate2_y, gate3_x, gate3_y, cage_x, cage_y, arr[10][10], gate1[10][10], gate2[10][10], gate3[10][10], cage[10][10], ans = 0;

	
	printf("Enter the dimensions of field: ");
	scanf("%d %d", &n, &m);
	
	printf("Enter position of gate 1: ");
	scanf("%d %d", &gate1_x, &gate1_y);
	printf("Enter position of gate 2: ");
	scanf("%d %d", &gate2_x, &gate2_y);
	printf("Enter position of gate 3: ");
	scanf("%d %d", &gate3_x, &gate3_y);
	
	
	printf("Enter the coordinates of cage: ");
	scanf("%d %d", &cage_x, &cage_y);
	
	gate1_x--, gate1_y--, gate2_x--, gate2_y--, gate3_x--, gate3_y--, cage_x--, cage_y--;
	
	printf("Enter Grid:\n");
	for (i = 0; i < n; i++) {
		for(j = 0; j < m; j++){
			scanf(" %c", &grid[i][j]);
		}
	}
	
//	for (i = 0; i < n; i++) {
//		for(j = 0; j < m; j++){
//			printf("%c", grid[i][j]);
//			printf(" ");
//		}
//		printf("\n");
//	}	
//	printf("\n");
	
	for (i = 0; i < n; i++) {
		for(j = 0; j < m; j++){
			if(grid[i][j] == 'G'){
				arr[i][j] = -1;
				grassland++;
			}
			else if(grid[i][j] == 'M')
				arr[i][j] = -2;
			else if(grid[i][j] == 'W')
				arr[i][j] = -3;
		}
	}
	
	for (i = 0; i < n; i++) {
		for(j = 0; j < m; j++){
			gate1[i][j] = gate2[i][j] = gate3[i][j] = cage[i][j] = arr[i][j];
		}
	}	
	printf("\n");
	
	
//	cage[cage_x][cage_y] = 0;
//	gate1[gate1_x][gate1_y] = gate2[gate2_x][gate2_y] = gate3[gate3_x][gate3_y] = 0;
	setval(cage, cage_x, cage_y, n, m, val, 0);
	setval(gate1, gate1_x, gate1_y, n, m, val, 1);
	setval(gate2, gate2_x, gate2_y, n, m, val, 1);
	setval(gate3, gate3_x, gate3_y, n, m, val, 1);
	
//	printf("Original Grid: \n");
//	for(i = 0; i < n; i++){
//		for(j = 0; j < m; j++){
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	
	printf("Cage Path: \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%d ", cage[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("Gate1 Path: \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%d ", gate1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("Gate2 Path: \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%d ", gate2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("Gate3 Path: \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%d ", gate3[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++){
			if(arr[i][j] == -1){
				if(checkpath(gate1, cage, i, j, gate1_x, gate1_y) || checkpath(gate2, cage, i, j, gate2_x, gate2_y) || checkpath(gate3, cage, i, j, gate3_x, gate3_y))
					ans++;
			}
		}
	}	
	safety = (ans * 100) / grassland;
	printf("Safety Index is %f", safety);
	return 0;
}

void setval(int arr[10][10],int x, int y, int n, int m, int val, int flag) {
	int i, j;
	if(arr[x][y] == -1 || arr[x][y] == -2 || arr[x][y] >= val) {
		arr[x][y] = val;
		if(isvalid(arr, x-1, y, n, m, flag)) 
			setval(arr, x-1, y, n, m, val+1, flag);
			
		if(isvalid(arr, x+1, y, n, m, flag))
			setval(arr, x+1, y, n, m, val+1, flag);
			
		if(isvalid(arr, x, y+1, n, m, flag))
			setval(arr, x, y+1, n, m, val+1, flag);
			
		if(isvalid(arr, x, y-1, n, m, flag))
			setval(arr, x, y-1, n, m, val+1, flag);	
	}
	
}

int isvalid(int arr[10][10], int x, int y, int n, int m, int flag){
	if(flag == 0){
		if(x >= 0 && x < n && y >= 0 && y < m)
			return 1;
		return 0;
	}
	else{
		if(x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != -2)
			return 1;
		return 0;
	}
}

int checkpath(int gate[10][10], int cage[10][10], int x, int y, int gatex, int gatey){
	
	if(gate[x][y] == -1){
		if(cage[x][y] != -1)
			return 0;
		else
			return 1;
	}	
	if(gate[x][y] >= 0 && cage[gatex][gatey] == -1)
		return 1;
		
	if(gate[x][y] < cage[gatex][gatey]){
		return 1;
	}
	return 0;
}


