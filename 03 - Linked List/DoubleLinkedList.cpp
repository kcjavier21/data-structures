#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct Student {
	char name[20];
	float gwa;
	float courseHours;
	Student *prev; // pointer to the previous student
	Student *next; // pointer to the next student
};

int main() {
	Student *head;
	head = NULL;
	
	Student *newStudent;
	Student *nextStudPointer;
	Student *prevStudPointer;
	
	char inpName[20], temp;
	float inpGWA, inpCrsHrs;
	int i=0;
	
	newStudent = new Student;
	
	for(i=1; i<=3; i++) {
		printf("Enter name : ");
		gets(inpName);
		printf("Enter GWA : ");
		scanf("%f", &inpGWA);
		printf("Enter Course Hour/s : ");
		scanf("%f", &inpCrsHrs);
		
		if (head == NULL) {
			newStudent = new Student;
			strcpy(newStudent->name, inpName);
			newStudent->gwa = inpGWA;
			newStudent->courseHours = inpCrsHrs;
			
			newStudent->prev = NULL;
			newStudent->next = NULL;
			head = newStudent;
			prevStudPointer = head;
		} else {
			nextStudPointer = new Student;
			strcpy(nextStudPointer->name, inpName);
			nextStudPointer->gwa = inpGWA;
			nextStudPointer->courseHours = inpCrsHrs;
			
			prevStudPointer->next = nextStudPointer;
			nextStudPointer->prev = prevStudPointer;
			nextStudPointer->next = NULL;
			prevStudPointer = nextStudPointer;
		}
		
		printf("\n\nPress any key to continue...");
		scanf("%c", &temp);
		getch();
		
		system("CLS");
		
	}
	
	
	
	
	/*
	strcpy(newStudent->name, "AJ");
	newStudent->gwa = 3.5;
	newStudent->courseHours = 18;
	newStudent->prev = NULL;
	newStudent->next = NULL;
	*/
	
	Student *displayPointer;
	displayPointer = head;
	
	if(displayPointer == NULL) {
		printf("No Node to display.\n");
	} else {
		printf("Data stored is/are \n\n");
		
		while(displayPointer != NULL) {
			printf("Name: %s \n", displayPointer->name);
			printf("GPA: %0.2f \n", displayPointer->gwa);
			printf("Course Hours: %0.2f \n", displayPointer->courseHours);
			printf("\n");
			
			displayPointer = displayPointer->next;
		}
	}
	
	getch();
	return 0;

}
