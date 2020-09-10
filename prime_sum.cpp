#include<stdio.h>
#include<stdlib.h>

int isprime(int);
int* primegen(int);
int primesum(int*, int);

int main(){
	int n, i=0, len, j, sum=0;
	int* prime;
	printf("Enter the range: ");
	scanf("%d", &n);
	prime = primegen(n);
	while(prime[i]!=0){
		i++;
	}
	len = i;
	for(i=2; i<len; i++){
		if(primesum(prime, prime[i])==1){
			j=0;
			sum=0;
			printf("%d=", prime[i]);
			while(sum!=prime[i]){
				printf("%d+", prime[j]);
				sum+=prime[j];
				j++;
			}
			printf("\b \n");
		}
	}
	return 0;
}

int isprime(int n){
	int i;
	if(n==2)
		return 1;
	if(n%2==0)
		return 0;
	for(i=3; i*i<=n; i+=2){
		if(n%i==0)
			return 0;
	}
	return 1;
}

int* primegen(int n){
	int i, j=0;
	int *ptr, *prime;
	ptr = (int*)malloc(sizeof(int)*1000);
	for(i=2; i<=n; i++){
		if(isprime(i)==1){
			ptr[j]=i;
			j++;
		}
	}
	prime = (int*)realloc(ptr, sizeof(int)*(j+1));
	prime[j]=0;
	return prime;
}

int primesum(int* prime, int n){
	int i=0, len, sum=0;
	while(sum<=n){
		if(sum==n)
			return 1;
		sum+=prime[i];
		i++;
	}
	return 0;
}


