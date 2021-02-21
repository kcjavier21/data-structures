//this is the program for stacks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


struct node
{
    char no[12];
	char name[24];
	char crsyr[10];
	float gwa;
    struct node *next;
};
struct node *top;

void CreateStack();
void AddNode();
void TraverseStack(struct node *head);
void DeleteNode(char *no1);

int main()
{
    char no1[12];
	char name1[24];
	char crsyr1[10];
	float gwa1;
	char temp;
	
    system("CLS");
	printf("\tOperations in Stacks \n\n");
	printf ("\t1: Create Student Record/s\n");
 	printf ("\t2: Traverse Student Record/s\n");
 	printf ("\t3: Add Student Record\n");
 	printf ("\t4: Deleting Student Record\n");
	printf ("\t5: Exit\n");
	
	printf("\n\n\tEnter the number of your choice: ");
	int choose;
	scanf("%d", &choose);
	switch(choose)
	{
		case 1: if (top!=NULL){
				printf("Memory Allocation is not possible .\n");
				}
				else{
				CreateStack();
				}
				system("pause");
				system("cls");
				main();
				break;
				
		case 2: TraverseStack(top);
				system("pause");
				system ("cls");
				main();
				break;
		
		case 3: if (top==NULL)
					printf("Unable to allocate memory.\n");
				else
					AddNode();
				system("pause");
				system("cls");
				main();
				break;
				
		case 4: if (top==NULL){
				printf("Stack is Empty!\n");
				}
				else{
				printf("Enter student number to delete: ");
                scanf("%s", &no1);
				DeleteNode(no1);	
				}
        		system("pause");
				system("cls");
				main();
				break;
				
		case 5: exit(0);
				
		default:printf ("Invalid!\n");
				system("pause");
				system ("cls");
				main();
				break;
	}
	return 0;
}


void CreateStack()
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    int n,i;
    char temp;
    printf ("\n\tEnter Number of Students: ");
    scanf("%d",&n);
   top=NULL;
    for(i=0;i<n;i++)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        printf("\tStudent No.: "); 
        scanf("%s",&tmp->no); 
	    scanf("%c", &temp);
	    printf("\tStudent Name: "); 
	    gets(tmp->name); 
	    printf("\tCourse and Year: "); 
	    gets(tmp->crsyr);
	    printf("\tGWA: ");
		scanf("%f",&tmp->gwa);
		printf("\n");
    	tmp -> next = top;
    	top = tmp;
    }
}

void AddNode()
{
    struct node *tmp;
    int i;
    char temp;
    tmp=(struct node*)malloc(sizeof(struct node));
    if (top==NULL){
    	top=tmp;
	}
	else{
    	printf("\tStudent No.: "); 
   		scanf("%s",&tmp->no); 
  		scanf("%c", &temp);
		printf("\tStudent Name: "); 
		gets(tmp->name); 
		printf("\tCourse and Year: "); 
		gets(tmp->crsyr);
		printf("\tGWA: ");
		scanf("%f",&tmp->gwa);
		printf("\n");
    	tmp -> next = top;
    	top = tmp;
	}
	temp=NULL;
}

void DeleteNode(char *no1)
{
    struct node *temp1=top;
    struct node *temp2=top;
    while(temp1!=NULL){
		
		if(strcmp(temp1->no, no1)==0){
			
			printf("Record with student number %s Found !\n", no1);
			
			if(temp1==temp2){
				top = top->next;
				free(temp1);
			}
			else{
				temp2->next = temp1->next;
				free(temp1); 
			}
			
			printf("Record Successfully Deleted !\n");
			return;
		}
		temp2 = temp1;
		temp1 = temp1->next;
		
	}
	printf("Student number %s is not found !\n", no1);	
}

void TraverseStack(struct node *head)
{
	struct node *tmp;
    tmp = top;
    if(top == NULL)
    {
        printf("The Stack is empty!\n");
    }
   while(tmp != NULL)
    {
        printf("\nStudent No.: %s\n",tmp->no); 
        printf("Student name: %s\n",tmp->name); 
        printf("Course and Year: %s\n",tmp->crsyr); 
        printf("GWA: %.2f\n\n",tmp->gwa);
        tmp=tmp->next;
    }
}

