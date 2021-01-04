#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<mem.h>
#include<malloc.h>
#include<windows.h>

struct node {
	int data;
	struct node *next;
};
struct node *START, *END, *NewNode, *DelNode, *Current, *Previous;

void CreateSLL();
void TraverseSLL();
void AddNodeAtTheStart();
void AddNodeAtTheEnd();
void AddNodeBeforeNode();
void AddNodeAfterNode();
void DeleteNodeAtTheStart();
void DeleteNodeAtTheEnd();
void DeleteNodeByValue();


int main() {
    char Resp, Temp;

    CreateSLL();
    TraverseSLL();

    printf("\n\nChoose Any of the Operations: \n\n");
    printf("A. Add Node\n");
    printf("B. Delete Node\n");
    printf("C. Exit\n\n");

    printf("Your response => ");
    Resp = getche();
    getch();
    
    system("CLS");
    
    if (toupper(Resp) == 'A') {
        printf("ADD NODE\n\n");
        printf("A. Add Node At the Start\n");
        printf("B. Add Node At the End\n");
        printf("C. Add Node Before Existing the Node\n");
        printf("D. Add After the Existing Node\n\n");

        printf("Your response (Letter Only) => ");
        Resp = getche();
        getch();

        if (toupper(Resp) == 'A') {
            AddNodeAtTheStart();
            TraverseSLL();
        }
        else if (toupper(Resp) == 'B') {
            AddNodeAtTheEnd();
            TraverseSLL();
        }
        else if (toupper(Resp) == 'C') {
            AddNodeBeforeNode();
            TraverseSLL();
        }
        else if (toupper(Resp) == 'D') {
            AddNodeAfterNode();
            TraverseSLL();
        }
        else 
            printf("Invalid Input!");
    }
    else if (toupper(Resp) == 'B') {
        printf("DELETE NODE\n\n");
        printf("A. Delete Node At the Start\n");
        printf("B. Delete Node At the End\n");
        printf("C. Delete Node by Value\n");

        printf("Your response (Letter Only) => ");

        Resp = getche();
        getch();

        if (toupper(Resp) == 'A') {
            DeleteNodeAtTheStart();
            TraverseSLL();
        }
        else if (toupper(Resp) == 'B') {
            DeleteNodeAtTheEnd();
            TraverseSLL();
        }
        else if (toupper(Resp) == 'C') {
            DeleteNodeByValue();
            TraverseSLL();
        }
        else 
            printf("Invalid Input!");
    }
    else {
        system("CLS");
        printf("Thank You!");
    }

    free(START);
    Current=START=NULL;
    getch();
    return 0;
}


void CreateSLL() {

	char Resp, Temp;
	int ctr = 1;

    START = NULL;

	// === Alllocate Memory to NewNode ===
	NewNode = (struct node*)malloc(sizeof(struct node));
	START = NewNode;
	
	printf("Creating Single/Singly Linked List!\n\n");
	
	do {
		// === Accept value for NewNode->data
		printf("Node No. %d\n", ctr);
		printf("Enter Data => ");
		scanf("%d", &NewNode->data);
		scanf("%c", &Temp);
		
		// === Decide if you want to enter another Node ===
		printf("\nAdd another NODE [Y/N]?");
		Resp = getche();
        getch();

        printf("\n");
		
		if (toupper(Resp) == 'Y') {
			ctr++;
			NewNode->next = (struct node*)malloc(sizeof(struct node));
			NewNode=NewNode->next;
		}
	} while(toupper(Resp) == 'Y');
	
	NewNode->next = NULL;
	NewNode=NULL;

    system("CLS");
}


void TraverseSLL() {
    int ctr = 1;

	printf("\nCONTENTS\n\n");
	ctr=1;
	Current=START;
	
	if(Current==NULL) 
		printf("The Single Linked List is Empty");
	else {
		do {
			printf("Node %d Content \n", ctr);
			printf("\tData => %d\n", Current->data);
			
			Current = Current->next;
			ctr++;
			
		} while(Current != NULL);
	}
}


void AddNodeAtTheStart() {
    NewNode = (struct node*)malloc(sizeof(struct node));   

    // === Accept value for NewNode->data
    printf("\n\n");
    printf("Enter NewNode Data => ");
    scanf("%d", &NewNode->data);
	
	NewNode->next = NULL;
    NewNode->next = START;
    START = NewNode;
	NewNode=NULL;
}

void AddNodeAtTheEnd() {
    NewNode = (struct node*)malloc(sizeof(struct node));

	// === Accept value for NewNode->data
    printf("\n\n");
    printf("Enter NewNode Data => ");
    scanf("%d", &NewNode->data);
	
	NewNode->next = NULL;

    END = START;

    while (END->next != NULL) 
        END = END->next;

    END->next = NewNode;
	NewNode=NULL;
    END = NULL;
	
	system("CLS");
}

void AddNodeBeforeNode() {
    int flag = 0;
    int beforeVal = 0;

    NewNode = (struct node*)malloc(sizeof(struct node));
    
    // === Accept value for NewNode->data
    printf("\n\n");
    printf("Enter NewNode Data => ");
    scanf("%d", &NewNode->data);
	
	NewNode->next = NULL;
  
    printf("Insert NewNode before what number? ");
    scanf("%d", &beforeVal);

    Previous = NULL;
    Current = START;

    do {
        if (beforeVal == Current->data)
            flag = 1;
        else {
            Previous = Current;
            Current = Current->next;
        }
    } while ((flag != 1) && (Current != NULL));


    if (flag == 1) {
        NewNode->next = Current;

        if (Previous == NULL)
            START = NewNode;
        else 
            Previous->next = NewNode;
    
        NewNode = NULL;
    
    } else {
        printf("The Value where you want to insert the NewNode before does not Exist!");
        Previous = NULL;
        Current = NULL;
    }

}


void AddNodeAfterNode() {
    int flag = 0;
    int afterVal = 0;

    NewNode = (struct node*)malloc(sizeof(struct node));
    
    // === Accept value for NewNode->data
    printf("Enter NewNode Data => ");
    scanf("%d", &NewNode->data);	
	
	NewNode->next = NULL;
  
    // === Accept value for AfterVal ===
    printf("Insert NewNode after what number? ");
    scanf("%d", &afterVal);

    Previous = NULL;
    Current = START;

    do {
        if (afterVal == Current->data)
            flag = 1;
        else 
            Current = Current->next;
        
    } while ((flag != 1) && (Current != NULL));

    if (flag == 1) {
        NewNode->next = Current->next;
        Current->next = NewNode;
        NewNode = NULL;
    } else {
        printf("The Value where you want to insert the NewNode after does not Exist!");
        Current = NULL;
    }
}

void DeleteNodeAtTheStart() {
    DelNode = START;
    START = START->next;
    DelNode->next = NULL;
    free(DelNode);
    DelNode = NULL;
}

void DeleteNodeAtTheEnd() {
    Previous = NULL;
    DelNode = START;

    while (DelNode->next != NULL) {
        Previous = DelNode;
        DelNode = DelNode->next;
    }

    Previous->next = NULL;
    Previous = NULL;
    free(DelNode);
    DelNode = NULL;
}

void DeleteNodeByValue() {
    int deleteVal = 0, flag = 0;

    Previous = NULL;
    DelNode = START;
    
    printf("\n\n");
    printf("Insert delete value: ");
    scanf("%d", &deleteVal);

    while((flag != 1) && (DelNode != NULL)) {
        if (deleteVal == DelNode->data)
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
}