/* SAMPLE PROGRAM :  RETRIEVAL OF FILE [ Record ] */

#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct{
	char snum[12], sfname[25], scity[25], crs[7], year[4];
	char grade[5];
   }myrec;
int main()
{

   myrec studrec;
   FILE *sampfile;
   int RecNo;
   float bgrade;
   char  FName[15];

   clrscr();
   printf("Enter Filename where records will be retrieved => ");
   scanf("%s",FName);
   printf("Enter Record No. to be retrieved => ");
   scanf("%d",&RecNo);
   sampfile = fopen(FName,"r");
   clrscr();

   fseek(sampfile,(RecNo-1)*sizeof(studrec),0);
   fread(&studrec,sizeof(studrec),1,sampfile);

   printf("\n\n<*********   STUDENT INFORMATION   *********>\n\n");
   printf("Student Number   : %s ",studrec.snum);
   printf("\nStudent Name   : %s ",studrec.sfname);
   printf("\nCity Address   : %s ",studrec.scity);
   printf("\nCourse         : %s ",studrec.crs);
   printf("\nYear           : %s ",studrec.year);

   bgrade = atof(studrec.grade);

   printf("\nGrade          : %2.2f ",bgrade);
   printf("\n\nPress < Enter > to continue...");
   getch();
   fclose(sampfile);
   return (0);
 }