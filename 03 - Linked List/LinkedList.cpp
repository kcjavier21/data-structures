#include<stdio.h>
#include<conio.h>
#include<string.h>

struct Student{
	char name[20];
	float gwa;
	float courseHours;
	Student *next;
};

int main() {
	Student *head;
	head = NULL;
	
	Student *newStudent;
	newStudent = new Student;
	
	strcpy(newStudent->name, "Steve");
	newStudent->gwa = 3.5;
	newStudent->courseHours = 18.0;
	newStudent->next = NULL;
	head = newStudent;
	
	newStudent = new Student;
	
	strcpy(newStudent->name, "Tony");
	newStudent->gwa = 3.0;
	newStudent->courseHours = 15.0;
	newStudent->next = NULL;
	head->next = newStudent;
	
	
	Student *displayPointer;
	displayPointer = head;
	
	while(displayPointer) {
		printf("%s\n", displayPointer->name);
		printf("%0.1f\n", displayPointer->gwa);
		printf("%0.1f\n", displayPointer->courseHours);
		printf("\n");
		
		displayPointer = displayPointer->next;
	}
	
	getch();
	return 0;
}
