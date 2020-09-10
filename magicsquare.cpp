#include<stdio.h>
#include<stdlib.h>

void magicsq(int);

int main(){
	int size;
	printf("Enter size of grid: ");
	scanf("%d", &size);
	(size%2==0)?(size+=1):size ;
	magicsq(size);
	return 0;
}

void magicsq(int n){
	int **grid, i, j, num=1;
	grid = (int**)malloc(sizeof(int*)*n);
	for(i=0; i<n; i++){
		grid[i] = (int*)calloc(sizeof(int),n);
	}
	i = n/2;
	j = n-1;
	for(num=1; num<=n*n; num++){
		if(i==-1 && j==n){
			j = n-2;
			i = 0;
		}
		else{
		 	if(j==n)
				j = 0;
			if(i<0)
				i = n-1;
		}
		if(grid[i][j]!=0){
			j -= 2; 
			i++;
			num--;
			continue;
		}
		else{
			grid[i][j] = num;
		}
		i--;
		j++;	
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf(" %d ", grid[i][j]);
		}
		printf("\n");
	}
}
