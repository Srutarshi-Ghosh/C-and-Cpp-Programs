#include<iostream>

int main(){
	int n, i, j, num=1, a;
	printf("ENTER THE NUMBER OF ROWS");
	scanf("%d", &n);
	a=2*(n-1);
	for(i=1; i<=n; i++){
		for(j=0; j<a; j++){
			printf(" ");
		}
		a-=2;
		for(j=1; j<=2*i-1; j++){
			printf("%d ", num);
			if(j>i-1)
				num--;
			else
				num++;
		}
		num=1;
		printf("\n");
	}
}
