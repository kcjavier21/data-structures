/* Linked List recursion
		functions: add, delete, and display
	
	by Allyza Maureen Catura
*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <mem.h>
#include <ctype.h>
#include <stdlib.h>

// struct declaration

typedef struct node {
	int data;
	node *next;
}node;

// global declaration

node *START, *NewNode;

// function declaration

node* addNode(node* START);
node* addBefore(node *START, int val);
node* addAfter(node *START, int val);
node* addStart(node *START);
node* addEnd(node *START);
node* deleteNode(node *START, int val);
void displayList(node *START);

int main() {
	node *START, *NewNode;
	int ctr=1, val, resp;
	START=NULL;
	system("cls");
	
	// user will choose which function to do
	
	do {
		system("cls");
		printf("Single Linked List (Recursive)");
		printf("\n\t1 - Add\n\t2 - Delete\n\t3 - Display\n\t4 - Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d", &resp);
		system("cls");
		switch(resp) {
			case 1: 
				// adding a node
				
				START = addNode(START);
				break;
			case 2: 
				// deleting a node
				
				printf("Enter the value to be deleted: ");
				scanf("%d", &val);
				START = deleteNode(START,val);
				system("cls");
				break;
			case 3: 
				// displaying of list
				
				if(START==NULL) 
					printf("The list is empty.");
				else 
					printf("Displaying of the single linked linked.\n");
					displayList(START);
				getch();
				break;
			default:
				
				printf("Invalid input.");
				system("cls");
				
				
			
		}
	} while(resp!=4);
	printf("Press any key to exit...");
	getch();
	return 0;
}

// function for adding of node

node* addNode(node *START) {
	int resp, val;
	system("cls");
	printf("\nSingle Linked List (Recursive)\n\n");
	printf("\t1 - Start\n\t2 - Before\n\t3 - After\n\t4 - End\n");
	printf("\n\nEnter your choice: ");
	scanf("%d", &resp);
	switch(resp) {
		case 1:
			// case 1: add node at the beginning
			printf("Adding of node at the beginning. \n");
			START = addStart(START); // addStart function for adding a node at the beginning
			break;
		case 2:
			// case 2: add node before a value
			
			if(START==NULL) {
				printf("You can't add a value since the list is empty.'");
				getch();
				return NULL;
			} else {
				printf("\nAdding of node before a value.");
				printf("\nEnter the value: "); // node data to be inserted before
				scanf("%d", &val);
				START = addBefore(START, val); // addBefore function for adding a node before a value	
			} 
			break;
		case 3:
			// case 3: add node after a value
			
				if(START==NULL) {
				printf("You can't add a value since the list is empty.'");
				getch();
				return NULL;
			} else {
				printf("\nAdding of node after a value.");
				printf("\nEnter the value: "); // node data to be inserted after
				scanf("%d", &val);
				START = addAfter(START, val); // addAfter function for adding a node after a value	
			} 
			break;
		case 4:
			// case 4: add node at the end
			
				if(START==NULL) {
				printf("You can't add a value since the list is empty.'");
				getch();
				return NULL;
			} else 
				START = addEnd(START); // addEnd function for adding a node at the end
			break;		
	}
}

// addBefore function for adding a node at the beginning

node* addBefore(node* START, int val) {
	node *NewNode, *TempNode;
	if(START==NULL)
		return NULL;
	
	// if the value is equal to the data
	
	else if(val==START->data) {
		TempNode = START;
		NewNode = (node*) malloc(sizeof(node));
		NewNode->next = NULL;
		printf("Enter data: ");
		scanf("%d", &NewNode->data);
		START = NewNode;
		NewNode->next = TempNode;
		return START;
	}
	
	// recursive function call of addBefore
	
	START->next = addBefore(START->next, val);
	return START;
}

// addAfter function for adding a node after a value

node* addAfter(node* START, int val) {
	node *NewNode, *TempNode;
	if(START==NULL)
		return NULL;
	
	// if the value is equal to the data
	
	else if(val==START->data) {
		TempNode = START->next;
		NewNode = (node*) malloc(sizeof(node));
		NewNode->next = NULL;
		printf("Enter data: ");
		scanf("%d", &NewNode->data);
		START->next = NewNode;
		NewNode->next = TempNode;
		return START;
	}
	
	// recursive function call of addAfter
	
	START->next = addAfter(START->next, val);
	return START;
}
// addStart function for adding a node at the beginning

node* addStart(node *START) {
	node *NewNode,*TempNode;
	if(START==NULL) { // when the list is empty, it will be the start node
		NewNode = (node*)malloc(sizeof(node));
		printf("Enter data: ");
		scanf("%d", &NewNode->data);
		NewNode->next = NULL;
		START = NewNode;
		return START;
	} else {
		TempNode = START;
		NewNode = (node*)malloc(sizeof(node));
		printf("Enter data: ");
		scanf("%d", &NewNode->data);
		NewNode->next = NULL;
		START = NewNode;
		START->next = TempNode;
		return START;
	}
}


// addEnd function for adding a node at the end

node* addEnd(node* START) {
	node *NewNode;
	if(START==NULL) { // when the list is empty
		NewNode = (node*)malloc(sizeof(node));
		printf("Enter data: ");
		scanf("%d", &NewNode->data);
		NewNode->next = NULL;
		START = NewNode; 
		return START;
	} else if (START->next==NULL) { // when the end is found
		NewNode = (node*)malloc(sizeof(node));
		printf("Enter data: ");
		scanf("%d", &NewNode->data);
		NewNode->next = NULL;
		START->next = NewNode;
		return START;
	}
	START->next = addEnd(START->next);
	return START;
}

// deleteNode function for deleting a node

node* deleteNode(node* START, int val) {
	node *TempNode;
	if(START==NULL)
		return NULL;
	else if(val==START->data) {
		TempNode = START->next;
		free(START);
		return TempNode;
	}
	START->next = deleteNode(START->next, val);
	return START;
}

// displayList function to display the list

void displayList(node *START) {
	if(START==NULL) 
		return;
	printf("\n\tData => %d", START->data);
	displayList(START->next);
}
	
