#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<mem.h>
#include<malloc.h>
#include<windows.h>

struct node {
	int data;
	struct node *left, *right;
};
//struct node *HEAD, *TAIL, *NewNode, *DelNode, *TravNode, *Current, *Previous;

struct node *create(int item);
struct node *insert(struct node *node, int data);
struct node* delete(struct node *root, int x);

void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);

int findMin(struct node *root);



int main() {
    struct node *root = NULL;
    root = insert(root, 50);

    system("CLS");
    
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    delete(root, 80);

    printf("INORDER: ");
    inorder(root);
    printf("\n");
    printf("PREORDER: ");
    preorder(root);
    printf("\n"); 
    printf("POSTORDER: ");
    postorder(root);

    return 0;
}

struct node *create(int item) {
    // === Alllocate Memory to NewNode ===
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}


struct node *insert(struct node *node, int data) {
    if (node == NULL) return create(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int findMin(struct node *root) {
    if(root == NULL) {
        printf("The tree is empty!");
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}



struct node* delete(struct node *root, int data) {
    if(root==NULL)
        return root;
    else if (data < root->data) 
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        //Case 1: No Child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
            return root;
        } 
        //Case 2: One Child
        else if (root->left == NULL) {
            struct node *temp = root;
            root = root->right;
            free(temp);
            return root;
        } else if (root->right == NULL) {
            struct node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        //Case 3: 2 Children
        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }  

}

