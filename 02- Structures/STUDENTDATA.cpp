#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "./custom-headers/studentData.h"

int main()
{
	struct StudentData kenken;
	
	strcpy(kenken.Name, "Kenken JAVIER");
	kenken.StudentID = 201902179;
	kenken.Age = 19;
	kenken.Year = 1;
	
	printf("Name: %s", kenken.Name);
	printf("\nStudent ID: %ld", kenken.StudentID);
	printf("\nAge: %d", kenken.Age);
	printf("\nYear: %d", kenken.Year);
	
	return 0; 
}
