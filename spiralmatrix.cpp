#include<iostream>

int main(){
	int i, j, num, n, count;
	scanf("%d", &n);
	for(i=n; i>0; i--){
		num=n;

		for(j=0; j<n-i; j++){
			printf("%d ", num);
			num--;
		}
		for(j=0; j<2*i-1; j++){
			printf("%d ", num);
		}

		for(j=0; j<n-i; j++){
			num++;
			printf("%d ", num);
		}
		printf("\n");
	}
	for(i=2; i<=n; i++){
		for(j=0; j<n-i; j++){
		printf("%d ", num);
		num--;
	}
	for(j=0; j<2*i-1; j++){
		printf("%d ", num);
	}

	for(j=0; j<n-i; j++){
		num++;
		printf("%d ", num);
	}
	printf("\n");
	}
}
