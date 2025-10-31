#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void swapFirstTwoNodes(struct Node** head) {
    if (*head == NULL || (*head)->next == *head) {
        printf("List is too short to swap nodes.\n");
        return;
    }

    struct Node* first = *head;
    struct Node* second = first->next;
    struct Node* last = *head;

    // Find the last node
    while (last->next != *head) {
        last = last->next;
    }

    // Perform the swap
    first->next = second->next;
    second->next = first;
    last->next = second;

    *head = second; 
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("NULL (circular)\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Original circular linked list: ");
    printList(head);

    swapFirstTwoNodes(&head);

    printf("Circular linked list after swapping first two nodes: ");
    printList(head);

    if (head != NULL) {
        struct Node* current = head->next;
        while (current != head) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
        free(head);
    }

    return 0;
}

