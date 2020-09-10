#include <bits/stdc++.h> 
using namespace std; 
#define ROW 9 
#define COL 10 

 

int main() 
{ 
    int mat[ROW][COL] = 
    { 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 } 
    }; 
  
    Point source = {0, 0}; 
    Point dest = {3, 4}; 
  
    int dist = shortestPath(mat, source, dest); 
  
    if (dist != INT_MAX) 
        cout << "Shortest Path is " << dist ; 
    else
        cout << "Shortest Path doesn't exist"; 
  
    return 0; 
} 

void isSafe(m, n, x, y){
	if(x >= 0 && x < n, && y >= 0 && y < m)
		return 1;
	return 0;
} 

void isValid(int mat[n][m], int visited[n][m], int x, int y){
	if(mat[x][y] == 0 || visited[x][y])
		return 0;
	return 1;
}


void shortestPath(mat[n][m], int visited[n][m], int x, int y, int min_dist, int dist) {
	
}






