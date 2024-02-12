#include <stdio.h>
#include <stdlib.h>
// Define the structure for a binary search tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a value into the binary search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
// Function for pre-order traversal
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
// Function for in-order traversal
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
// Function for post-order traversal
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
// Function to calculate the height of the binary search tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}
 
int countNodes(struct Node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		return 1+countNodes(root -> left) + countNodes(root -> right);
	}
}
// Function to free the memory allocated for the tree nodes
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
// Main function for testing
int main() {
    struct Node* root = NULL;
    int value, choice;
    do {
        printf("Enter a value to insert into the tree (or enter -1 to stop): ");
        scanf("%d", &value);
        if (value != -1) {
            root = insert(root, value);
        }
    } while (value != -1);
    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");
    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");
    printf("Height of the tree: %d\n", height(root));
    printf("Total number of nodes in the tree: %d\n",countNodes(root));
    // Free the allocated memory
    freeTree(root);
    return 0;
}