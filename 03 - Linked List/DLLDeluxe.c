#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<mem.h>
#include<malloc.h>
#include<windows.h>

struct node {
	int data;
	struct node *next, *prev;
};
struct node *HEAD, *TAIL, *NewNode, *DelNode, *TravNode, *Current, *Previous;

void CreateDLL();
void TraverseDLL();
void AddNodeAfterNode();
void DeleteNodeByValue();
void DeleteNodeBeforeNode();

int main() {
    system("CLS");
    CreateDLL();
    TraverseDLL();
    //AddNodeAfterNode();
    //DeleteNodeByValue();
    DeleteNodeBeforeNode();
    TraverseDLL();
}

void CreateDLL() {
	char Resp, Temp;
	int ctr = 1;
    HEAD = NULL;
    TAIL = NULL;

	// === Alllocate Memory to NewNode ===
	NewNode = (struct node*)malloc(sizeof(struct node));
	HEAD = NewNode;
    TAIL = NewNode;
    HEAD->prev = NULL;
	
	printf("Creating Double/Doubly Linked List!\n\n");
	
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

	printf("\nCONTENTS\n\n");
	ctr=1;
	TravNode = HEAD;
	
	if(TravNode == NULL) 
		printf("The Double Linked List is Empty");
	else {
		do {
			printf("Node %d Content \n", ctr);
			printf("\tData => %d\n", TravNode->data);
			
			TravNode = TravNode->next;
			ctr++;
			
		} while(TravNode != NULL);
	}
}


void AddNodeAfterNode() {
    int flag = 0;
    int afterVal = 0;

    NewNode = (struct node*)malloc(sizeof(struct node));
    
    // === Accept value for NewNode->data
    printf("\nEnter NewNode Data => ");
    scanf("%d", &NewNode->data);	
	
	NewNode->next = NULL;
    NewNode->prev = NULL;

    // === Accept value for AfterVal ===
    printf("Insert NewNode after what number? ");
    scanf("%d", &afterVal);

    Current = HEAD;

    if (Current == NULL)
        printf("\nDouble Linked List is Empty!");
    else {
        while ((flag == 0) && (Current != NULL)) {
            if (Current->data == afterVal)
                flag = 1;
            else
                Current = Current->next;
        }

        if (flag == 0)
            printf("The Value where the NewNode will be inserted before does not exist");
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
}

void DeleteNodeByValue() {
    int deleteVal = 0, flag = 0;

    Previous = NULL;
    DelNode = HEAD;
    
    printf("\n\n");
    printf("Insert delete value: ");
    scanf("%d", &deleteVal);

    if (DelNode == NULL) 
        printf("\nDouble Linked List is Empty!");
    else {
        while ((flag == 0) && (DelNode != NULL)) {
            if(DelNode->data == deleteVal)
                flag = 1;
            else
                DelNode = DelNode->next;
        }

        if (flag == 0)
            printf("\nThe Value to be deleted does not exist!");
        else {
            if (DelNode == HEAD) {
                HEAD = HEAD->next;
                HEAD->prev = NULL;
                DelNode->next = NULL;
            } else if (DelNode == TAIL) {
                TAIL = TAIL->prev;
                TAIL->next = NULL;
                DelNode->prev = NULL;
            } else {
                DelNode->prev->next = DelNode->next;
                DelNode->next->prev = DelNode->prev;
                DelNode->next = NULL;
                DelNode->prev = NULL;
            }

            free(DelNode);
            DelNode = NULL;
        }
    }
}


void DeleteNodeBeforeNode() {
    int deleteVal = 0, flag = 0;

    Previous = NULL;
    DelNode = HEAD;
    
    printf("\n\n");
    printf("Insert delete value: ");
    scanf("%d", &deleteVal);

    if (DelNode == NULL) 
        printf("\nDouble Linked List is Empty!");
    else {
        while ((flag == 0) && (DelNode != NULL)) {
            if(DelNode->data == deleteVal)
                flag = 1;
            else
                DelNode = DelNode->next;
        }

        if (flag == 0)
            printf("\nThe Value to be deleted does not exist!");
        else {
            if (DelNode == HEAD) {
                HEAD = HEAD->next;
                HEAD->prev = NULL;
                DelNode->next = NULL;
            } else if (DelNode == TAIL) {
                TAIL = TAIL->prev;
                TAIL->next = NULL;
                DelNode->prev = NULL;
            } else {
                DelNode = DelNode->prev;
                DelNode->prev->next = DelNode->next;
                DelNode->next->prev = DelNode->prev;
               
                DelNode->next = NULL;
                DelNode->prev = NULL;   
            }

            free(DelNode);
            DelNode = NULL;
        }
    }
}