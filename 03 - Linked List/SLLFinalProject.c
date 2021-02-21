#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<mem.h>
#include<malloc.h>
#include<windows.h>

struct Student_Record {
	char number[12];
    char name[24];
    char crsYr[10];
    float gwa;
	struct Student_Record *next;
};
struct Student_Record *START, *END, *NewNode, *DelNode, *Current, *Previous;

void CreateSLL();
void TraverseSLL();
void SelectOperation();
void AddNodeAtTheEnd();
void DeleteNodeByValue();

int main() {
    CreateSLL();
    TraverseSLL();
   
    free(START);
    Current=START=NULL;
    getch();
    return 0;
}

void SelectOperation() {
    char Resp, Temp;

    printf("\n\nPLEASE SELECT OPERATOR\n\n");
    printf("A. Add Student\nB. Delete Student\nC. Exit\n\nYour Choice(Letter only): ");
    Resp = getche();
    getch();

    if (toupper(Resp) == 'A') {
        AddNodeAtTheEnd();
        TraverseSLL();
    } else if (toupper(Resp) == 'B') {
        DeleteNodeByValue();
        TraverseSLL();
    } else if (toupper(Resp) == 'C') {
        system("CLS");
        printf("\nPress any key to continue exit...\n");
        getch();
        free(START);
        Current=START=NULL;
        getch();
    } else {
        system("CLS");
        printf("\n\nInvalid Input!\n");
        SelectOperation();
    }
}

void CreateSLL() {
    system("CLS");

	char Resp, Temp, inpNum[12], inpName[24], inpCrsYr[10];
	int ctr = 1;
    float inpGWA = 0;

    START = NULL;

	// === Alllocate Memory to NewNode ===
	NewNode = (struct Student_Record*)malloc(sizeof(struct Student_Record));
	START = NewNode;
	
	printf("Creating Student Record List!\n\n");
	
    // === Add Data ===
	do {
		printf("Student %d\n", ctr);

		printf("Enter Student Number: ");
	    gets(inpNum);

        printf("Enter Student Name: ");
		gets(inpName);

        printf("Enter Course and Year: ");
		gets(inpCrsYr);

        printf("Enter GWA: ");
		scanf("%f", &inpGWA);

		
        strcpy(NewNode->number, inpNum);
        strcpy(NewNode->name, inpName);
        strcpy(NewNode->crsYr, inpCrsYr);
        NewNode->gwa = inpGWA;

        scanf("%c", &Temp);
		
		// === Decide if you want to enter another Student ===
		printf("\nAdd another Student_Record [Y/N]?");
		Resp = getche();
        getch();

        printf("\n");
		
		if (toupper(Resp) == 'Y') {
			ctr++;
			NewNode->next = (struct Student_Record*)malloc(sizeof(struct Student_Record));
			NewNode=NewNode->next;
		}
	} while(toupper(Resp) == 'Y');
	
	NewNode->next = NULL;
	NewNode=NULL;

    system("CLS");
}

void TraverseSLL() {
    int ctr = 1;

	printf("\nSTUDENT RECORDS\n\n");
	ctr=1;
	Current=START;
	
	if(Current==NULL) 
		printf("The Single Linked List is Empty");
	else {
		do {
			printf("\nStudent %d\n", ctr);
			printf("\tStudent No.: %s\n", Current->number);
            printf("\tName: %s\n", Current->name);
            printf("\tCourse and Year: %s\n", Current->crsYr);
            printf("\tGWA: %0.2f\n", Current->gwa);
			
			Current = Current->next;
			ctr++;
			
		} while(Current != NULL);
	}

    SelectOperation();
}


void AddNodeAtTheEnd() {
	char Resp, Temp, inpNum[12], inpName[24], inpCrsYr[10];
	int ctr = 1;
    float inpGWA = 0;

    NewNode = (struct Student_Record*)malloc(sizeof(struct Student_Record));

	// === Accept value for NewNode ===
    printf("\n\n");
    printf("Enter New Student Data\n\n");

    printf("Enter Student Number: ");
    gets(inpNum);

    printf("Enter Student Name: ");
    gets(inpName);

    printf("Enter Course and Year: ");
    gets(inpCrsYr);

    printf("Enter GWA: ");
    scanf("%f", &inpGWA);

    
    strcpy(NewNode->number, inpNum);
    strcpy(NewNode->name, inpName);
    strcpy(NewNode->crsYr, inpCrsYr);
    NewNode->gwa = inpGWA;

    scanf("%c", &Temp);
	
	NewNode->next = NULL;

    END = START;

    while (END->next != NULL) 
        END = END->next;

    END->next = NewNode;
	NewNode=NULL;
    END = NULL;

    system("CLS");
}

void DeleteNodeByValue() {
    char deleteVal[12]; 
    int flag = 0;

    Previous = NULL;
    DelNode = START;
    
    printf("\n\n");
    printf("Insert student number: ");
    gets(deleteVal);

    while((flag != 1) && (DelNode != NULL)) {
        if (strcmp(deleteVal, DelNode->number) == 0)
            flag = 1;
        else {
            Previous = DelNode;
            DelNode = DelNode->next;
        }
    }

    if (flag == 0)  {
        printf("\n\n");
        printf("Delete Value not found :(");
    }
    else {
        if (DelNode == START) {
            START = START->next;
            DelNode->next = NULL;
        } else {
            Previous->next = DelNode->next;
            DelNode->next = NULL;
        }

        free(DelNode);
    }

    Previous = NULL;
    DelNode = NULL;

    system("CLS");
}