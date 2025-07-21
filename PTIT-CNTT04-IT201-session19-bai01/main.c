#include <stdio.h>
#include <stdlib.h>

typedef  struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode( int capacity) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed in insert()\n");
        exit(0);
    }
    temp->data = capacity;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


int main(void) {
    int n=0;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node *temp = createNode(n);
    printf("data : %d", temp->data);


    return 0;
}