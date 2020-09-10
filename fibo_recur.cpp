#include<stdio.h>

int printfibo(int, int, int);

int main(){
	int n;
	printf("Enter the number of the series: ");
	scanf("%d", &n);
	printf("0 ");
	printfibo(1, 0, n);
	return 0;
}

int printfibo(int a, int b, int n){
	int sum = a + b;
	if(n==0)
		return 1;
	printf("%d ", &sum);
	printfibo(sum, a, n);
}



