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

int main() {

// ======== CREATION of SINGLE LINKED LIST ========

	struct node *START, *NewNode, *Current;
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
		scanf("%c", &Resp);
		
		if (toupper(Resp) == 'Y') {
			ctr++;
			NewNode->next = (struct node*)malloc(sizeof(struct node));
			NewNode=NewNode->next;
		}
	} while(toupper(Resp) == 'Y');
	
	NewNode->next = NULL;
	NewNode=NULL;
	

	system("CLS");



// =========== ADDING of NODE at THE START ========

// === Alllocate Memory to NewNode ===
	NewNode = (struct node*)malloc(sizeof(struct node));

	printf("Creating Single/Singly Linked List!\n\n");
    
		// === Accept value for NewNode->data
		printf("Enter NewNode Data => ");
		scanf("%d", &NewNode->data);
		scanf("%c", &Temp);		
	
	NewNode->next = NULL;
    NewNode->next = START;
    START = NewNode;
	NewNode=NULL;
	

	system("CLS");



// ======== TRAVERSAL of SINGLE LINKED LIST ========

	printf("Display Contents\n\n");
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
	

	free(START);
	Current=START=NULL;
	getch();
	return 0;
}
