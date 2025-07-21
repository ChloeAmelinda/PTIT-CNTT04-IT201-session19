#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 100
typedef struct Node {
    int data;
    struct Node *right;
    struct Node *left;

}Node;
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
typedef struct Queue {
    Node* item[MAX_QUEUE];
    int front;
    int rear;

}Queue;
void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;

}
int isEmptyQueue(Queue* queue) {
    return queue->rear == queue->front;
}
int isFullQueue(Queue* queue) {
    return queue->rear == MAX_QUEUE;
}
void enQueue(Queue* queue, Node* node) {
    if (isFullQueue(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->item[queue->rear++] = node;

}
Node* deQueue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->item[queue->front++] ;
}
void levelOderQueue(Node * root) {
    if (root == NULL) {
        return;
    }
    Queue q;
    initQueue(&q);
    enQueue(&q, root);
    while (!isEmptyQueue(&q)) {
        Node* current = deQueue(&q);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enQueue(&q, current->left);

        }
        if (current->right != NULL) {
            enQueue(&q, current->right);
        }
    }
}
int main(void) {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node* root = createNode(n);
    root->left = createNode(n+1);
    root->right = createNode(n+2);
    root->left->left = createNode(n+3);
    levelOderQueue(root);

    return 0;
}