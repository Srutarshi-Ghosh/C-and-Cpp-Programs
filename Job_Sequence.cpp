#include<stdio.h>
#include<stdlib.h>

typedef struct job{
	int id;
	int deadline;
	int profit;
}job;

void jobSort(job*, int);
void swapJob(job*, int, int);
int min(int, int);
void printJobs(job*, int);
int job_sequence(job*, int, int);

int main(){
	job *job_list;
	int i, n, max_deadline, max_profit;
	
	printf("Enter Number of Jobs: ");
	scanf("%d", &n);
	
	job_list = (job*)malloc(n * sizeof(job));
	
	for(i = 0; i < n; i++){
		printf("Enter job deadline and profit: ");
		scanf("%d %d", &job_list[i].deadline, &job_list[i].profit);
		job_list[i].id = i + 1;
	}
	
	printf("Enter max Deadline: ");
	scanf("%d", &max_deadline);
	
	//printJobs(job_list, n);
	max_profit = job_sequence(job_list, n, max_deadline);
	printf("Maximum Profit is %d\n", max_profit);
	
}



void jobSort(job *job_list, int n){
	int i, j;
	for(i = 0; i < n -1; i++){
		for(j = 0; j < n -i -1; j++){
			if(job_list[j].profit < job_list[j+1].profit)
				swapJob(job_list, j, j+1);
		}
	}
	
}


void swapJob(job *job_list, int a, int b){
	job temp = job_list[a];
	job_list[a] = job_list[b];
	job_list[b] = temp;
}

void printJobs(job *job_list, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("Job ID: %d  Job Deadline: %d  Job Profit: %d\n", job_list[i].id, job_list[i].deadline, job_list[i].profit);
	}
}


int min(int a, int b){
	return (a < b) ? a : b;
}


int job_sequence(job *job_list, int n, int max_deadline){
	
	int i, j, ind, profit = 0, *id_list, no_of_jobs = 0;
	jobSort(job_list, n);
	//printf("%d", min(n, max_deadline));
	
	id_list = (int*)calloc(min(n, max_deadline), sizeof(int));
	
	for(i = 0; i < n; i++){
		ind = min(max_deadline, job_list[i].deadline) - 1;
		//printf("%d\n", ind);
		while(id_list[ind] != 0 && ind >= 0)
			ind--;
		
		if(ind >= 0){
			id_list[ind] = job_list[i].id;
			printf("Job ID: %d  Job Deadline: %d  Job Profit: %d\n", job_list[i].id, job_list[i].deadline, job_list[i].profit);
			profit += job_list[i].profit;
			no_of_jobs++;
		}
				
	}
	
	for(i = 0; i < no_of_jobs; i++){
		printf("%d\n", id_list[i]);
	}
	
	for(i = 0; i < no_of_jobs; i++){
		ind = id_list[i] - 1;
		printf("Job ID: %d  Job Deadline: %d  Job Profit: %d\n", job_list[ind].id, job_list[ind].deadline, job_list[ind].profit);
	}
	return profit;
	
}

