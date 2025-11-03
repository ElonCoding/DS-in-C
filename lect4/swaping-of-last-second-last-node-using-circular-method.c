#include <stdio.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

void swapLastTwoNodes(struct Node** head) {
    if (*head == NULL || (*head)->next == *head) {
        // List is empty or has only one node, nothing to swap
        return;
    }

    struct Node* last = (*head)->prev;
    struct Node* secondLast = last->prev;

    if (secondLast == *head) { // Only two nodes in the list
        // Swap head and last node
        *head = last;
        last->next = secondLast;
        last->prev = secondLast;
        secondLast->next = last;
        secondLast->prev = last;
        return;
    }

    // General case: more than two nodes
    struct Node* thirdLast = secondLast->prev;
    struct Node* first = *head;

    // Adjust pointers for thirdLast and last
    thirdLast->next = last;
    last->prev = thirdLast;

    // Adjust pointers for last and secondLast
    last->next = secondLast;
    secondLast->prev = last;

    // Adjust pointers for secondLast and first (head)
    secondLast->next = first;
    first->prev = secondLast;

    // If the head was one of the swapped nodes, update head
    if (*head == secondLast) {
        *head = last;
    }
}

int main() {
    // Create a sample doubly circular linked list
    struct Node node1 = {1, NULL, NULL};
    struct Node node2 = {2, NULL, NULL};
    struct Node node3 = {3, NULL, NULL};
    struct Node node4 = {4, NULL, NULL};

    node1.next = &node2;
    node1.prev = &node4;

    node2.next = &node3;
    node2.prev = &node1;

    node3.next = &node4;
    node3.prev = &node2;

    node4.next = &node1;
    node4.prev = &node3;

    struct Node* head = &node1;

    printf("\nOriginal list:\n");
    printList(head);

    swapLastTwoNodes(&head);

    printf("\nAfter swapping last two nodes:\n");
    printList(head);

    return 0;
}
