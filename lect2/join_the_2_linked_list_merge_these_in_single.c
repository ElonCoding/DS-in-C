#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of a linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to merge two linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        return head2;
    } else if (head2 == NULL) {
        return head1;
    } else {
        struct Node* current = head1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = head2;
        return head1;
    }
}

int main() {
    struct Node* head1 = NULL; // First linked list
    struct Node* head2 = NULL; // Second linked list

    // Populate first linked list
    head1 = insertEnd(head1, 1);
    head1 = insertEnd(head1, 2);
    head1 = insertEnd(head1, 3);

    // Populate second linked list
    head2 = insertEnd(head2, 4);
    head2 = insertEnd(head2, 5);
    head2 = insertEnd(head2, 6);

    printf("First Linked List: ");
    printList(head1);

    printf("Second Linked List: ");
    printList(head2);

    // Merge the two linked lists
    struct Node* mergedHead = mergeLists(head1, head2);

    printf("Merged Linked List: ");
    printList(mergedHead);

    // Free allocated memory (important to prevent memory leaks)
    struct Node* current = mergedHead;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}