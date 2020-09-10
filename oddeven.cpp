#include<stdio.h>
#include<conio.h>

int main(){
	int n, i;
	char eo;
	printf("Enter upper limit: ");
	scanf("%d", &n);
	printf("Enter odd or enen: ");
	scanf("\n%c", &eo);
	for(i=0; i<=n; i++){
		if(eo=='e'){
			if(i%2==0)
				printf("%d ", i);
		}
		else if(eo=='o'){
			if(i%2!=0)
				printf("%d ", i);
		}
	}
	return 0;
}
