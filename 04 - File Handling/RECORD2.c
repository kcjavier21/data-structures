/*This Program will retrieve records from the disk */

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
  FILE  *STUDFILE;
  Student_Record   STUDENT[50],TEMPREC;
  int i,j,k;
  float TGrade;
  char Temp,FName[15];
  system("CLS");
  printf("\n\nEnter Filename where records will be retrieved => ");
  gets(FName);
  printf("\n\nRetrieving records from %s...",FName);

  STUDFILE=fopen(FName,"r");
  /* 
		fopen - opens the file.
			
			Parameters:
				- variable name of the external file.
				- operation of fopen.

			"r" - operation of fopen to READ the file.
				- if file is existing, records will be overwrited.
	 */

  k=0;
  fread(&TEMPREC,sizeof(TEMPREC),1,STUDFILE);
  while(!feof(STUDFILE)) // feof - checks if you reached the end of the file opened.
	  {
		STUDENT[k]=TEMPREC;
		fread(&TEMPREC,sizeof(TEMPREC),1,STUDFILE);
		/* 
			fread - reads a single record to the file variable.
				
				Parameters:
					- address of record
					- size of record
					- 1
					- file variable
	 	*/
		k++;
	  }
  fclose(STUDFILE);


  printf("%d records retrieved!!!",k);
  printf("\n\nPress Any Key To Continue...");
  getch();

  for(i=0;i<k;i++)
	 {
		 system("CLS");
		 printf("<@@ STUDENT's INFORMATION @@>\n\n");
		 printf("Student No.    : %s\n",STUDENT[i].No);
		 printf("Student Name   : %s\n",STUDENT[i].Name);
		 printf("Course and Year: %s\n",STUDENT[i].Crsyr);
		 printf("List of grades:\n");
		 for(j=0;j<5;j++)
			 printf("\tGrade No. %d => %0.2f\n",j+1,STUDENT[i].Grade[j]);
		 printf("\nPress any key to continue...");
		 getch();
	 }

  getch();
  return (0);
}