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
	struct Student_Record *next, *prev;
};
struct Student_Record *HEAD, *TAIL, *NewNode, *DelNode, *TravNode, *Current, *Previous;

void CreateDLL();
void TraverseDLL();
void AddNodeAfterNode();
void DeleteNodeBeforeNode();
void SelectOperation();

int main() {
    system("CLS");
    CreateDLL();
    TraverseDLL();
    //AddNodeAfterNode();
    //DeleteNodeByValue();
    //DeleteNodeBeforeNode();
   // TraverseDLL();

    free(HEAD);
    Current=HEAD=NULL;
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
        AddNodeAfterNode();
        TraverseDLL();
    } else if (toupper(Resp) == 'B') {
        DeleteNodeBeforeNode();
        TraverseDLL();
    } else if (toupper(Resp) == 'C') {
        system("CLS");
        printf("\nPress any key to continue exit...\n");
        getch();
        free(HEAD);
        Current=HEAD=TAIL=NULL;
        getch();
    } else {
        system("CLS");
        printf("\n\nInvalid Input!\n");
        SelectOperation();
    }
}

void CreateDLL() {
	char Resp, Temp, inpNum[12], inpName[24], inpCrsYr[10];
    float inpGWA = 0;
	int ctr = 1;
    HEAD = NULL;
    TAIL = NULL;

	// === Alllocate Memory to NewNode ===
	NewNode = (struct Student_Record*)malloc(sizeof(struct Student_Record));
	HEAD = NewNode;
    TAIL = NewNode;
    HEAD->prev = NULL;
	
	printf("Create Student Record List using Double/Doubly Linked List!\n\n");
	
	do {
		// === Accept value for NewNode->data
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
		
		// === Decide if you want to enter another Node ===
		printf("\nAdd another NODE [Y/N]?");
		Resp = getche();
        getch();

        printf("\n");
		
		if (toupper(Resp) == 'Y') {
			ctr++;
			NewNode->next = (struct Student_Record*)malloc(sizeof(struct Student_Record));
            NewNode->next->prev = NewNode;
			NewNode = NewNode->next;
            TAIL = NewNode;
		}
	} while(toupper(Resp) == 'Y');
	
	TAIL->next = NULL;
	NewNode = NULL;

    system("CLS");
}


void TraverseDLL() {
    int ctr = 1;

	printf("\nSTUDENT RECORDS\n\n");
	ctr=1;
	TravNode = HEAD;
	
	if(TravNode == NULL) 
		printf("The Double Linked List is Empty");
	else {
		do {
			printf("\nStudent %d\n", ctr);
			printf("\tStudent No.: %s\n", TravNode->number);
            printf("\tName: %s\n", TravNode->name);
            printf("\tCourse and Year: %s\n", TravNode->crsYr);
            printf("\tGWA: %0.2f\n", TravNode->gwa);
			
			TravNode = TravNode->next;
			ctr++;
			
		} while(TravNode != NULL);
	}

    SelectOperation();
}


void AddNodeAfterNode() {
    char Resp, Temp, inpNum[12], inpName[24], inpCrsYr[10], afterVal[12];
    int flag = 0;
    float inpGWA = 0;

    NewNode = (struct Student_Record*)malloc(sizeof(struct Student_Record));
    
    // === Accept value for NewNode->data
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
    NewNode->prev = NULL;

    // === Accept value for AfterVal ===
    printf("Insert New Student after whom? Insert the student number. ");
    gets(afterVal);

    Current = HEAD;

    if (Current == NULL)
        printf("\nDouble Linked List is Empty!");
    else {
        while ((flag == 0) && (Current != NULL)) {
            if (strcmp(afterVal, Current->number) == 0)
                flag = 1;
            else
                Current = Current->next;
        }

        if (flag == 0)
            printf("The Student where the New student will be inserted before does not exist");
        else {
            if(Current == TAIL) {
                NewNode->prev = TAIL;
                TAIL->next = NewNode;
                TAIL = NewNode;
            } else {
                NewNode->next = Current->next;
                NewNode->prev = Current;
                Current->next->prev = NewNode;
                Current->next = NewNode;
            }
            Current = NewNode = NULL;
        }
    }

    system("CLS");
}


void DeleteNodeBeforeNode() {
    int flag = 0;
    char deleteVal[12];

    Previous = NULL;
    DelNode = HEAD;
    
    printf("\n\n");
    printf("Who to delete? Insert the number of student next to him/her : ");
    scanf("%s", &deleteVal);
    //gets(deleteVal);

    if (DelNode == NULL) 
        printf("\nDouble Linked List is Empty!");
    else {
        while ((flag == 0) && (DelNode != NULL)) {
            if (strcmp(deleteVal, DelNode->number) == 0)
                flag = 1;
            else
                DelNode = DelNode->next;
        }

        if (flag == 0)
            printf("\nThe Student does not exist!");
        else {
            if (DelNode == HEAD) {
                system("CLS");
                printf("\nCannot delete the preceding student because there is none!\n\n");
            }
            
            if (DelNode != HEAD) {
                DelNode = DelNode->prev;

                if (DelNode == HEAD) {
                    HEAD = HEAD->next;
                    HEAD->prev = NULL;
                    DelNode->next = NULL;
                } else {
                    DelNode->prev->next = DelNode->next;
                    DelNode->next->prev = DelNode->prev;
                
                    DelNode->next = NULL;
                    DelNode->prev = NULL;   
                }

                free(DelNode);
                DelNode = NULL;
                system("CLS");
            }    
        }
    }   
}