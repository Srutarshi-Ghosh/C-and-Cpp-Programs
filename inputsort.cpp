#include<stdio.h>

int main(){
	int arr[100], n, i, j, temp, k, x=0;
	printf("Enter no of elements: ");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	scanf("%d", &arr[0]);
	for(i=1; i<n; i++){
		scanf("%d", &arr[i]);
		x=0;
		for(j=i-1; j>=0; j--){
			if(arr[j]==arr[i]){
				printf("Enter element again: \n");
				x=1;
				break;
			}
		}
		if(x==1){
			i--;
			continue;
		}
		temp=arr[i];
		j=i-1;
		while(arr[j]>temp && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
}
	for(i=0; i<n; i++){
		printf("%d", arr[i]);
	}
	return 0;
}
