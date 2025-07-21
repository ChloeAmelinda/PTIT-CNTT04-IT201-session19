#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
}Queue;
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (Node**)malloc(sizeof(Node*) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
int isQueueEmpty(Queue* queue) {
    return queue->rear ==  queue->capacity -1;
}
int isQueueFull(Queue* queue) {
    return queue->rear > queue->rear;
}
void enQueue(Queue* queue, Node* node) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = node;
}
Node *deQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    Node* node = queue->arr[queue->front];
    queue->front++;
    return node;
}
void addNode(Node *root, int value) {
    if (root == NULL) {
        printf("Node is null\n");
        return;
    }
    Queue* queue = createQueue(100);
    enQueue(queue, root);
    while (!isQueueEmpty(queue)) {
        Node *current = deQueue(queue);
        if (current == NULL) {
            continue;
        }
        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        }else {
            enQueue(queue, current->left);
        }
        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        }else {
            enQueue(queue, current->right);
        }

    }

}
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main(void) {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node* root = createNode(n);
    root->left = createNode(n+1);
    root->right = createNode(n+2);
    root->left->left = createNode(n+3);
    preOrder(root);

    int addValue;
    printf("Enter the number of nodes: ");
    scanf("%d", &addValue);
    addNode(root, addValue);
    preOrder(root);
    return 0;
}