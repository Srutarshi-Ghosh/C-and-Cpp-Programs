#include<iostream>

int sum_digits(int);
int no_digits(int);
int main(){
	int n, sum,no;
	printf("ENTER A NUMBER");
	scanf("%d", &n);
	sum=sum_digits(n);
	no=no_digits(n);
	printf("THE SUM OF DIGITS IS %d \nTHE NO OF DIGITS IS %d", sum, no);
	return 0;
}

int sum_digits(int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n=n/10;
	}
	return sum;
}

int no_digits(int n){
	int no=0;
	while(n>0){
		no++;
		n=n/10;
	}
	return no;
}
