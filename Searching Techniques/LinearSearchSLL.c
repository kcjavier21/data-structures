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
void SearchNode();

int main() {

    char Resp, Temp;

    system("CLS");
    CreateSLL();
    TraverseSLL();
    SearchNode();

    free(START);
    Current=START=NULL;
    getch();
    return 0;
}

void CreateSLL() {
	char Resp, Temp;
	int count = 1;

    START = NULL;

	// === Alllocate Memory to NewNode ===
	NewNode = (struct node*)malloc(sizeof(struct node));
	START = NewNode;
	
	printf("Creating Single/Singly Linked List!\n\n");
	
	do {
		// === Accept value for NewNode->data
		printf("Node No. %d\n", count);
		printf("Enter Data => ");
		scanf("%d", &NewNode->data);
		scanf("%c", &Temp);
		
		// === Decide if you want to enter another Node ===
		printf("\nAdd another NODE [Y/N]?");
		Resp = getche();
        getch();

        printf("\n");
		
		if (toupper(Resp) == 'Y') {
			count++;
			NewNode->next = (struct node*)malloc(sizeof(struct node));
			NewNode=NewNode->next;
		}
	} while(toupper(Resp) == 'Y');
	
	NewNode->next = NULL;
	NewNode=NULL;

    system("CLS");
}


void TraverseSLL() {
    int count = 1;

	printf("\nCONTENTS\n\n");
	count=1;
	Current=START;
	
	if(Current==NULL) 
		printf("The Single Linked List is Empty");
	else {
		do {
			printf("Node %d Content \n", count);
			printf("\tData => %d\n", Current->data);
			
			Current = Current->next;
			count++;
			
		} while(Current != NULL);
	}
}

void SearchNode() {
    printf("\n\nSearch for the node!\n\n");

    int flag = 0;
    int searchVal = 0;
    int count = 0;
  
    // === Accept value for searchVal ===
    printf("Insert number you want to search: ");
    scanf("%d", &searchVal);

    Current = START;

    do {
        count++;
        if (searchVal == Current->data)
            flag = 1;
        else 
            Current = Current->next;
        
    } while ((flag != 1) && (Current != NULL));


    if (flag == 1) {
        printf("The value is located in Node %d!", count);
    } else {
        printf("The value which you want to search in the node is not existing!");
        Current = NULL;
    }
}