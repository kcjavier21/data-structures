/* This program will allow saving of records in the disk */

#include <stdio.h>
#include <conio.h>
#include <windows.h>
typedef struct{
			 char  No[12];
			 char  Name[25];
			 char  Crsyr[10];
			 float Grade[5];
		  }Student_Record;
int main()
{
  FILE  *STUDFILE; // FILE - defines a file variable || variable name must have a pointer
  Student_Record   STUDENT[50],TEMPREC;
  int i,j,ns;
  float TGrade;
  char Temp,FName[15];

  do{
		system("CLS");
		printf("How many student records (max. of 50) ? ");
		scanf("%d",&ns);
		if ((ns<1)||(ns>50))
			{
			 printf("\nInvalid Input!!!");
			 printf("\n\nPress Any Key To Continue...");
			 getch();
			}
  }while((ns<1)||(ns>50));
  scanf("%c",&Temp);
  for(i=0;i<ns;i++)
	 {
		 system("CLS");
		 printf("<@@ STUDENT's INFORMATION @@>\n\n");
		 printf("Student No.    : ");
		 gets(STUDENT[i].No);
		 printf("Student Name   : ");
		 gets(STUDENT[i].Name);
		 printf("Course and Year: ");
		 gets(STUDENT[i].Crsyr);
		 printf("List of grades:\n");
		 for(j=0;j<5;j++)
			{
			  printf("\tGrade No. %d => ",j+1);
			  scanf("%f",&TGrade);
			  STUDENT[i].Grade[j]=TGrade;
			}
		 printf("\nPress any key to continue...");
		 getch();
		 scanf("%c",&Temp);
	 }
	 printf("\n\nEnter Filename where records will be saved => ");
	 gets(FName);
	 printf("\n\nSaving of Records being process...");

	 STUDFILE=fopen(FName,"w");
	 /* 
		fopen - opens the file.
			
			Parameters:
				- variable name of the external file.
				- operation of fopen.

			"w" - operation of fopen to WRITE or create a new file.
				- if file is existing, records will be overwrited.
	 */

	 for(i=0;i<ns;i++)
		 {
		  TEMPREC=STUDENT[i]; // Copy STUDENT[i] to TEMPREC
		  fwrite(&TEMPREC,sizeof(TEMPREC),1,STUDFILE);
		  /* 
			fwrite - saves the data to disk.
				
			Parameters:
				- address of record
				- size of record
				- 1
				- file variable
	 	*/

		 }
	 fclose(STUDFILE);
	 /* 
	 	fclose - closes the file

		Parameters:
			- file variable
	*/

	 printf("Saving of Records Completed!!!\n\n");
	 printf("Press Any Key To Exit...");
	 getch();
	 return (0);
}