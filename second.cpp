#include<stdio.h>

int main(){
	int max, min, max2, min2, i, n, arr[100];
	printf("Enter number of inputs: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if(i == 0){
			max = min = min2 = max2 = arr[0];
		}
		else{
			if(arr[i] > max){
				max2 = max;
				max = arr[i];
			}
			if(arr[i] > max2 && arr[i] < max)
				max2 = arr[i];
			if(max == max2)
				max2 = arr[i];
				
			if(arr[i] < max){
				max2 = min;
				min = arr[i];
			}
			if(arr[i] > min2 && arr[i] < min)
				min2 = arr[i];
			if(min == min2)
				min2 = arr[i];
		}
	}
	printf("%d, %d", max2, min2);
}
