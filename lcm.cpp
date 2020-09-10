#include<iostream>

int lcm(int, int);

int main(){
	int a, b, l;
	scanf("%d %d", &a, &b);
	printf("%d", lcm(a, b));
	
	return 0;
}

int lcm(int a, int b){
	int i, lar, small;
	if(a>=b){
		lar=a;
		small=b;
	}
	else{
		lar=b;
		small=a;
	}
	for(i=lar; i<=lar*small; i+=lar){
		if(i%small==0)
			return i;
	}
	return a*b;
}
