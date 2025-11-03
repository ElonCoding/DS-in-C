#include <stdio.h>

#define MAX_NODES 100

// Node structure
struct Node {
    int data;
    int next;  // Index of the next node in the array, -1 if end
};

// Global node array and head index
struct Node nodePool[MAX_NODES];
int head = -1;
int nodeCount = 0;

// Function to insert at the end
void insertEnd(int data) {
    if (nodeCount >= MAX_NODES) {
        printf("Node pool full. Cannot insert more nodes.\n");
        return;
    }

    nodePool[nodeCount].data = data;
    nodePool[nodeCount].next = -1;

    if (head == -1) {
        head = nodeCount;
    } else {
        int current = head;
        while (nodePool[current].next != -1) {
            current = nodePool[current].next;
        }
        nodePool[current].next = nodeCount;
    }

    nodeCount++;
}

// Function to delete the first node
void deleteFirstNode() {
    if (head == -1) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    int temp = head;
    head = nodePool[head].next;
    printf("Deleted node with data: %d\n", nodePool[temp].data);
    // No need to free memory since it's static
}

// Function to display the list
void displayList() {
    if (head == -1) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    int current = head;
    while (current != -1) {
        printf("%d -> ", nodePool[current].data);
        current = nodePool[current].next;
    }
    printf("NULL\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    printf("Original ");
    displayList();

    deleteFirstNode();
    displayList();

    printf("\nDeleting again...\n");
    deleteFirstNode();
    displayList();

    return 0;
}