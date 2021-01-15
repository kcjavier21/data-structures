/* SAMPLE PROGRAM :  FILE HANDLING [ Record ] */

#include <stdio.h>
#include <conio.h>
typedef struct{
	char snum[12], sfname[25], scity[25], crs[7], year[4];
	char grade[5];
   }myrec;
main()
{

   myrec studrec;
   FILE *sampfile;
   int numchar,NStudent;
   char temp[2],FName[15];

   clrscr();
   printf("Enter Filename where Records will be stored => ");
   scanf("%s",FName);
   printf("Enter No. of Student Records => ");
   scanf("%d",&NStudent);
   gets(temp);
   sampfile = fopen(FName,"w");
   for(numchar=0;numchar < NStudent;numchar++)
     {
	clrscr();
	printf("<*********   STUDENT INFORMATION   *********>\n\n");
	printf("Student Number : ");
	gets(studrec.snum);
	printf("\nStudent Name   : ");
	gets(studrec.sfname);
	printf("\nCity Address   : ");
	gets(studrec.scity);
	printf("\nCourse         : ");
	gets(studrec.crs);
	printf("\nYear           : ");
	gets(studrec.year);
	printf("\nGrade          : ");
	gets(studrec.grade );
	fwrite(&studrec,sizeof(studrec),1,sampfile);
	printf("\n\n Press < Enter > to continue...");
	getch();
     }
   fclose(sampfile);
   return (0);
 }