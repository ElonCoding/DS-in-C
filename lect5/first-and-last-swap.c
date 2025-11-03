#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

// Function to swap the first and last nodes of the linked list
void swapFirstAndLast(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // List is empty or has only one node, no swap needed
        return;
    }

    struct Node* first = *head;
    struct Node* secondLast = NULL;
    struct Node* last = *head;

    // Find the last node and the second last node
    while (last->next != NULL) {
        secondLast = last;
        last = last->next;
    }

    // If there are only two nodes
    if (secondLast == first) {
        last->next = first;
        first->next = NULL;
        *head = last;
        return;
    }

    // Perform the swap
    last->next = first->next;
    secondLast->next = first;
    first->next = NULL;
    *head = last;
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Number of nodes cannot be negative.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Original linked list: ");
    printList(head);

    swapFirstAndLast(&head);

    printf("Linked list after swapping first and last nodes: ");
    printList(head);

    // Free memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}