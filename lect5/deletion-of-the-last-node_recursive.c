#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node (uses malloc, as allowed for list creation)
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of a linked list (uses loop, as allowed for list creation)
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* deleteLastNodeRecursive(struct Node* head) {
    if (head == NULL) {
        // List is empty, nothing to delete
        return NULL;
    }
    if (head->next == NULL) {
        // This is the last node, delete it
        free(head);
        return NULL;
    }
    // Recursively call for the rest of the list
    head->next = deleteLastNodeRecursive(head->next);
    return head;
}

int main() {
    struct Node* head = NULL;

    // Populate the linked list
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    printf("Original ");
    printList(head);

    // Delete the last node recursively
    head = deleteLastNodeRecursive(head);
    printf("After deleting last node ");
    printList(head);

    // Delete another last node
    head = deleteLastNodeRecursive(head);
    printf("After deleting another last node ");
    printList(head);

    // Delete last node from a list with one element
    head = deleteLastNodeRecursive(head);
    printf("After deleting last node from a smaller list ");
    printList(head);

    // Clean up remaining memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}