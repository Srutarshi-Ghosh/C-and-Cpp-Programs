#include<iostream>

void printfibo(int);

int main(){
	int no;
	printf("Enter a no: ");
	scanf("%d", &no);
	printfibo(no);
	return 0;
}

void printfibo(int no){
	int i, a=0, b=1, sum;
	printf("fibonacci series upto %d terms is: \n", no);
	for(i=1; i<=no; i++){
		printf("%d ", a);
		sum=a+b;
		a=b;
		b=sum;
	}
}
