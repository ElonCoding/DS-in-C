#include <stdio.h>

#define MAX_NODES 100

struct Node {
    int data;
    int next;
};

struct Node nodes[MAX_NODES];
int nodeCount = 0;

int createNode(int value) {
    if (nodeCount >= MAX_NODES) {
        printf("Maximum nodes reached.\n");
        return -1;
    }
    nodes[nodeCount].data = value;
    nodes[nodeCount].next = -1;
    return nodeCount++;
}

void insertAtEnd(int* head, int value) {
    int newNodeIndex = createNode(value);
    
    if (*head == -1) {
        *head = newNodeIndex;
        return;
    }
    
    int temp = *head;
    while (nodes[temp].next != -1) {
        temp = nodes[temp].next;
    }
    
    nodes[temp].next = newNodeIndex;
}

void displayList(int head) {
    if (head == -1) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Linked List: ");
    int temp = head;
    while (temp != -1) {
        printf("%d -> ", nodes[temp].data);
        temp = nodes[temp].next;
    }
    printf("NULL\n");
}

void insertBeforeLast(int* head, int new_data) {
    if (*head == -1 || nodes[*head].next == -1) {
        int newNodeIndex = createNode(new_data);
        nodes[newNodeIndex].next = *head;
        *head = newNodeIndex;
        return;
    }
    
    int current = *head;
    while (nodes[nodes[current].next].next != -1) {
        current = nodes[current].next;
    }
    
    int newNodeIndex = createNode(new_data);
    nodes[newNodeIndex].next = nodes[current].next;
    nodes[current].next = newNodeIndex;
}

int main() {
    int head = -1;
    int n, value;
    
    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }
    
    printf("\nOriginal linked list:\n");
    displayList(head);
    
    printf("\nEnter value to insert before the last node: ");
    scanf("%d", &value);
    insertBeforeLast(&head, value);
    
    printf("\nLinked list after inserting %d before the last node:\n", value);
    displayList(head);
    
    return 0;
}