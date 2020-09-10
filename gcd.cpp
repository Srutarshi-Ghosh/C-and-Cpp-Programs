#include<iostream>

int gcd(int, int);

int main(){
	int a, b, hcf;
	printf("Enter first no: ");
	scanf("%d", &a);
	printf("Enter second no: ");
	scanf("%d", &b);
	hcf=gcd(a, b);
	printf("%d", hcf);
	return 0;
}

int gcd(int a, int b){
	int gr, sm, temp;
	if(a>b){
		gr=a;
		sm=b;
	}
	else{
		sm=a;
		gr=b;
	}
	while(sm!=0){
		temp=sm;
		sm=gr%sm;
		gr=temp;
	}
	return gr;
}
