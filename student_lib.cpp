#include<stdio.h>

typedef struct marks{
		char paper[100];
		int marks;
	} exam;

typedef struct student{
	char name[100];
	int roll;
	exam data[10];
} st; 

int main(){
	int n, i, j, ser, flag=0, sub;
	printf("Enter the number of Students to store data: ");
	scanf("%d", &n);
	printf("Enter the number of Subjects: ");
	scanf("%d", &sub);
	st lib[10];
	for(i=0; i<n; i++){
		printf("Enter student name: ");
		scanf("%s", lib[i].name);
		printf("Enter student roll no: ");
		scanf("%d", &lib[i].roll);
		for(j=0; j<sub; j++){
			printf("Enter subject: ");
			scanf("%s", lib[i].data[j].paper);
			printf("Enter marks: ");
			scanf("%d", &lib[i].data[j].marks);
		}	
	}
	printf("\nEnter roll no to search: ");
	scanf("%d", &ser);
	for(i=0; i<n; i++){
		if(lib[i].roll==ser){
			flag=1;
			printf("%s\t%d\n", lib[i].name, lib[i].roll);
			for(j=0; j<sub; j++){
				printf("%s\t%d\n", lib[i].data[j].paper, lib[i].data[j].marks);
			}
			break;
		}
	}
	if(flag==0)
		printf("Roll no not found!");
	return 0;
}
