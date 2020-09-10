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
	int i, n = 168, ans = 1;
	for(i = 2; i < n; i++){
		if(n % i == 0){
			if(isprime(i))
				ans *= i;
		}	
	}
	printf("The product of prime factors of %d is %d", n, ans);

}
