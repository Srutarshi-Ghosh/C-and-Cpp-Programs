#include<iostream>

int main(){
	int i, j, n, a;
	scanf("%d", &n);
	a=2*(n-1);
	for(i=1; i<=n; i++){
		for(j=0; j<a; j++){
			printf(" ");
		}
		a-=2;
		for(j=0; j<2*i-1; j++){
			printf("* ");
		}
		printf("\n");
	}
	a=2;
	for(i=n-1; i>=1; i--){
		for(j=0; j<a; j++){
			printf(" ");
		}
		a+=2;
		for(j=0; j<2*i-1; j++){
			printf("* ");
		}
		printf("\n");
	}
}
