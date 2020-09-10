#include<stdio.h>
#include<math.h>


int no_of_factors(int n){
	int arr[100000], i = 3, j = 0, x = (int)sqrt(n), ans = 1;
	
	arr[0] = 0;
	while(n % 2 == 0){
		arr[j]++;
		n = n/2;
	}
	j++;
	while(n > 1 && i <= x){
		if(n % i == 0){
			arr[j] = 0;
			while(n % i == 0){
				n = n/i;
				arr[j]++;
			}
			j++;
		}
		i += 2;
	}
	if(n > 1){
		arr[j++] = 1;
	}
	for(i = 0; i < j; i++){
		ans *= (1 + arr[i]);
	}
	return ans;
}


int main(){
	int n, k;
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("No of factors %d", no_of_factors(n));
}

