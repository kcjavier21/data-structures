#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

typedef struct Student {
	char name[20];
	float gpa;
	float courseHours;
	struct Student *next; // pointer to the next
};

int main() {
	struct Student *head;
	head = NULL;
	
	char inpName[20], temp;
	float inpGPA, inpCrsHrs;
	int i=0;
	
	struct Student *newStudent;
	struct Student *studentPointer;
	
	
	for(i=1; i<=3; i++) {
		printf("Enter the name: ");
		gets(inpName);
		printf("Enter the gpa: ");
		scanf("%f", &inpGPA);
		printf("Enter the Course Hour/s: ");
		scanf("%f", &inpCrsHrs);
		
		newStudent = new Student;
		
		strcpy(newStudent->name, inpName);
		newStudent->gpa = inpGPA;
		newStudent->courseHours = inpCrsHrs;
		newStudent->next = NULL;
		
		if(head == NULL) 
			head = newStudent;
		else {
			studentPointer = head;
			
			while(studentPointer->next) 
				studentPointer = studentPointer->next;
				
			studentPointer->next = newStudent;	
		}
		
		printf("\n\nPress any key to continue...");
		scanf("%c", &temp);
		getch();
		
		system("CLS");
	}
	
	struct Student *displayPointer;
	
	displayPointer = head;
	
	while(displayPointer) {
		printf("%s\t", displayPointer->name);
		printf("%0.2f\t", displayPointer->gpa);
		printf("%0.2f\t\n", displayPointer->courseHours);
		
		displayPointer = displayPointer->next;
	}
	
	getch();
	return 0;	
}

