#include<stdio.h>


int isprime(int n){
	int i;
	for(i = 2; i < n; i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int main(){
	int i, n;
	scanf("%d", &n);
	printf("The prime factors of %d are: ", n);
	for(i = 2; i < n; i++){
		if(n % i == 0){
			if(isprime(i))
				printf("%d ", i);
		}	
	}
	
}
