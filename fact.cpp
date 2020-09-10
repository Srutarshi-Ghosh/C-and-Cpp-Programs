#include<iostream>

int main(){
	int i, res=1, n;
	scanf("%d",&n);
	for(i=2; i<=n-n%2; i+=2){
		res*=i*(i-1);
		
	}
	if(n%2==1)
		res*=n;
	printf("%d", res);
}
