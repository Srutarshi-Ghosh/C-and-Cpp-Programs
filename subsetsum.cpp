#include<stdio.h>
#include<stdlib.h>
void subsets(int[], int, FILE*);

int main(){
	FILE *fp;
	int *a;
	char ch;
	int i=0, j, sum=0, size, no, arr[100];
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	printf("Enter the elements of the array: ");
	for(i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the number: ");
	scanf("%d", &no);
	a = (int*)malloc(size*sizeof(int));
	subsets(arr, size, fp);
	fp = fopen("sample.txt", "r");
	
	ch = fgetc(fp);
	do{
		
		while(ch!='\n'){
			a[i]=0;
			while(ch!=' '){
				
				a[i] += (int)ch-(int)'0';
			
				a[i] = a[i]*10;
				ch = fgetc(fp);
			}
			a[i]=a[i]/10;
			sum+=a[i];
			i++;
			ch = fgetc(fp);
		}
		
		
		if(sum==no){
			for(j=0; j<i; j++){
				printf("%d ", a[j]);
			}
			printf("\n");
		}
		i=0;
		sum=0;
		ch = fgetc(fp);
	}while(ch!=EOF);
}
void subsets(int arr[], int n, FILE *fp){
	int i,j;
	fp = fopen("sample.txt", "w");
	for(i=1; i<(1<<n); i++){
	
		for(j=0; j<n; j++){
			if((i&(1<<j))>0)
				fprintf(fp, "%d ", arr[j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}
