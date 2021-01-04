#include<stdio.h>
#include<conio.h>
#include<windows.h>


struct college_info{
	
	char col_name[50];
	char col_coll[50];
	char col_dep[50];
};


struct student_info{
	
	char stu_name[40];
	char stu_age[3];
	char stu_number[20];
	
	struct college_info kolehiyo;
};

int main()
{
	
	struct student_info S[5];
	int i;
	
	for(i=0; i<5; i++)
	{
	
		printf("Student Name: ");
		gets(S[i].stu_name);
		printf("Age: ");
		gets(S[i].stu_age);
		printf("Student Number: ");
		gets(S[i].stu_number);
		printf("School Name: ");
		gets(S[i].kolehiyo.col_name);
		printf("College: ");
		gets(S[i].kolehiyo.col_coll);
		printf("College Department: ");
		gets(S[i].kolehiyo.col_dep);
		printf("\n\nPress any key to continue... ");
		getch();
		system("CLS");
	}
	
		
		for(i=0; i<5; i++)
	{
		printf("Student Name:           %s\n", S[i].stu_name);
		printf("Age:                    %s\n", S[i].stu_age);
		printf("Student Number:         %s\n", S[i].stu_number);
		printf("School Name:            %s\n", S[i].kolehiyo.col_name);
		printf("College:                %s\n", S[i].kolehiyo.col_coll);
		printf("College Department:     %s\n\n\n", S[i].kolehiyo.col_dep);
	}
	
	getch();
	return 0;	
				
}
