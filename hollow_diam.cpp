#include<iostream>

int main(){
	int n, i, j, k;
	printf("ENTER THE NUMBER OF ROWS");
	scanf("%d", &n);
	int a=2*(n-1);
	k=3;
	for(i=1; i<=n; i++){
		for(j=0; j<a; j++){
			printf(" ");
		}
		a-=2;
		printf("*");
		if(i!=1){
			
			for(j=0; j<k; j++){
				printf(" ");
			}
			k+=4;
			printf("*");
		}
		printf("\n");
	}
	a=2;
	k=2*n+1;
	for(i=n-1; i>=1; i--){
		for(j=0; j<a; j++){
			printf(" ");
		}
		a+=2;
		printf("*");
		if(i!=1){
			for(j=0; j<k; j++){
				printf(" ");
			}
			k-=4;
			printf("*");
		}
		printf("\n");
	}
	
	
	return 0;
}

