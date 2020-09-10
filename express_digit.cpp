#include<stdio.h>


int express(int arr[], int n){
	int min = arr[1], ind = 1, i, ans = 0;
	
	for(i = 2; i < 10; i++){
		if(arr[i] < min){
			min = arr[i];
			ind = i;
		}
	}  
	
	if(arr[0] <= min){
		ans = 1;
		for(i = 1; i <= arr[0] + 1; i++) 
            ans *= 10; 
            
        return ans;
	}
	else{
		ans = ind;
		for(i = 0; i < min; i++){
			ans = (ans * 10) + ind;
		}
		return ans;
	}
	
}


int main(){
	int arr[] =  {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
    int n = 10; 
      
    // Calling function 
    printf("%d", express(arr, n)); 
}
