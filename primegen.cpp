#include<stdio.h>

int isprime(int);
void primegen(int, int);

int main(){
	int a, b;
	printf("Enter lower limit: ");
	scanf("%d", &a);
	printf("Enter upper limit: ");
	scanf("%d", &b);
	primegen(a, b);
	
	return 0;
}

void primegen(int a, int b){
	int i, arr[100000], j = 0;
	printf("The primes between %d and %d are: \n", a, b);
	for(i=a; i<=b; i++){
		if(isprime(i)==1)
			arr[j++] = i;
	}
	for(i = 0; i < j; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
//	for(i = 1; i < j; i++){
//		printf("%d ", arr[i] - arr[i-1]);
//	}
	
}

int isprime(int n){
	int i;
	if(n<=1)
		return 0;
	if(n==2)
		return 1;
	for(i=2; i<=n/2; i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
