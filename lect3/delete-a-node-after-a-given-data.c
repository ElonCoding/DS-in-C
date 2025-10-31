#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
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

// Function to insert a node at the end of the list
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

// Function to delete a node after a given data
struct Node* deleteAfterNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    // If key is not found or it's the last node
    if (current == NULL || current->next == NULL) {
        printf("Node with data %d not found or it's the last node. Cannot delete after it.\n", key);
        return head;
    }

    struct Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node after %d deleted successfully.\n", key);
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
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

int main() {
    struct Node* head = NULL;
    int keyToDeleteAfter;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    printf("Original ");
    displayList(head);

    printf("Enter the data of the node after which you want to delete: ");
    scanf("%d", &keyToDeleteAfter);
    head = deleteAfterNode(head, keyToDeleteAfter);
    displayList(head);

    printf("\nTesting with another value.\n");
    printf("Enter the data of the node after which you want to delete: ");
    scanf("%d", &keyToDeleteAfter);
    head = deleteAfterNode(head, keyToDeleteAfter);
    displayList(head);

    // Clean up memory (free all nodes)
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}