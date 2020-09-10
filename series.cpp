#include<stdio.h>


int main(){
	int i, n = 8;
	float ans = 0;
	for(i = 1; i <= n; i++){
		ans += (float)i / ((i+1) * (i+2));
	}
	printf("The sum of the series is %f", ans);
}
