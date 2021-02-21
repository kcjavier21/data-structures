#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <mem.h>
#include <malloc.h>
#include <windows.h>

void CreateQueue();
void TraverseQueue();
void InsertQueue();
void DeleteQueueByVal();
void Exit();

typedef struct student{
	char no[12];
	char name[24];
	char crsYr[10];
	float gwa;
	struct student *next;
} student; 

student *Front, *Rear;

int main()
{
	int choice;
	
	while(1)
	{
		system("cls");
		printf("\n\tOperations in Queue\n\n");
        printf("\t1. Creation\n");
        printf("\t2. Traversal\n");
        printf("\t3. Insertion of node\n");
        printf("\t4. Deletion of node by value\n");
        printf("\t5. Exit\n");
        
        printf("\n\tChoose operation to perform: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
        	system("cls");
        	CreateQueue();
		}
		
		else if (choice == 2)
		{
			system("cls");
			TraverseQueue();
		}
		
		else if (choice == 3)
		{
			system("cls");
			InsertQueue();
		}
		
		else if (choice == 4)
		{
			system("cls");
			DeleteQueueByVal();
		}
		else if (choice == 6)
		{
			system("cls");
			Exit();
		}

		else	
			printf("\tInvalid Input.");	
	}
	getch();
	return 0;
}

void CreateQueue()
{
	student *AddStudent;
	AddStudent = (struct student*)malloc(sizeof(struct student));
	
	int i = 0;
	float tempGWA;
	char choice, temp;
	
	if(AddStudent == NULL)
	{
		printf("\nQueue Overflowed!");
		return;
	}
	
	do{
		scanf("%c", &temp);
		printf("\nStudent No.#%d", i+1);
		printf("\n\tEnter Student No.: ");
		gets(AddStudent->no);
		
		printf("\tEnter Student Name: ");
		gets(AddStudent->name);
		
		printf("\tEnter Student Course and Year: ");
		gets(AddStudent->crsYr);
		
		printf("\tEnter Student GWA: ");
		scanf("%f", &tempGWA);
		AddStudent->gwa = tempGWA;
		
		AddStudent->next = NULL;
	
		if(Rear == NULL)
		{
			Front = AddStudent;
			Rear = AddStudent;
		}
	
		else
		{
			Rear->next = AddStudent;
			Rear = Rear->next;
		}
		
		printf("\n\nAdd another student to the list? [Y/N]: ");
		scanf(" %c", &choice);
		
		
		if(toupper(choice) == 'Y')
		{
			i++;
			AddStudent->next = (struct student*)malloc(sizeof(struct student));
			AddStudent = AddStudent->next;
		}
		
	} while(toupper(choice) == 'Y');
	
}

void TraverseQueue()
{
	student *Trav;
	int i = 1;      
	Trav = Front;
	printf("\n\t\tTraversal of Queue\n");
    if(Trav == NULL)  
    {  
        printf("\n\tEmpty queue!\n");  
    }  
    else  
    {  
		do{
			printf("\n\tStudent #%d", i);
           	printf("\n\t\tStudent No. %s", Trav->no);
           	printf("\n\t\tStudent Name: %s", Trav->name);
           	printf("\n\t\tCourse and Year: %s", Trav->crsYr);
           	printf("\n\t\tGWA: %0.2f\n", Trav->gwa);
            Trav = Trav->next;
            i++;
            
		}while(Trav != NULL);
    }  
    getch();
}  

void InsertQueue()
{
	student *AddStudent;
	AddStudent = (struct student*)malloc(sizeof(struct student));
	
	float tempGWA;
	char choice, temp;
	
	scanf("%c", &temp);
	printf("\n\tEnter Student No.: ");
	gets(AddStudent->no);
		
	printf("\tEnter Student Name: ");
	gets(AddStudent->name);
		
	printf("\tEnter Student Course and Year: ");
	gets(AddStudent->crsYr);
		
	printf("\tEnter Student GWA: ");
	scanf("%f", &tempGWA);
	AddStudent->gwa = tempGWA;
	
	AddStudent->next = NULL;
	
	if(Rear==NULL)
	{
		Front = Rear = AddStudent;
	}
	
	else
	{
		Rear->next = AddStudent;
		Rear = AddStudent;
	}
	
	AddStudent = NULL;
	
	printf("\n\n\tStudent was successfully added!\n\tPlease press any key to continue...");
	getch();
}


void DeleteQueueByVal()
{  
	struct student *DelVal, *Prev;
	int flag = 0, f = 0;
	char Val[12], temp;
	Prev = NULL;
    DelVal = Front;
    
	if(Front == NULL)  
    {  
        printf("\n\tEmpty Queue!\n");  
        getch();
        return;  
    }  
    else   
    {  
    scanf("%c", &temp);
	printf("\n\nDelete Student No.: ");
	gets(Val);

    while(flag != 1 && DelVal != NULL)
	{
		f += 1;
		if (strcmp(DelVal->no, Val) == 0 )
			{
			flag = 1;
			}
		else
		{
			Prev = DelVal;
			DelVal = DelVal->next;
		}
	}
	
	if(flag == 0)
			printf("\n\n\tStudent cannot be found!");
	else if (flag != 0 && f == 1)
	{
			if(Front->next != NULL)
			{
				DelVal = NULL;
				Front = Front->next;
				DelVal=Front;
				do
				{
				Prev = DelVal;
				DelVal = DelVal->next;
				}while(DelVal != NULL && Front != NULL);
			}
			else 
			{
				DelVal = NULL;
				Front=NULL;
				free(DelVal);
			}
			printf("\n\n\tStudent was successfully deleted!");
	}	
	else 
		{
			Prev->next = DelVal->next;
			DelVal->next = NULL;
			free(DelVal);
			printf("\n\n\tStudent was successfully deleted!");
		}
	}
	  getch();
}   

void Exit()
{
	printf("\n\t\t\t\t   THANK YOU!");
	exit(0);
	return;
}
