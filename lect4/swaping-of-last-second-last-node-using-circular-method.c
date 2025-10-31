#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    if (head == 0) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

void swapLastTwoNodes(struct Node** head) {
    if (*head == 0 || (*head)->next == *head)
        return;

    struct Node* first = *head;
    struct Node* secondLast = *head;
    struct Node* last = (*head)->next;

    while (last->next != *head) {
        secondLast = last;
        last = last->next;
    }

    secondLast->next = *head;
    struct Node* temp = (*head)->next;

    if (temp == *head) {
        *head = last;
        last->next = secondLast;
        return;
    }

    struct Node* cur = *head;
    while (cur->next != secondLast)
        cur = cur->next;

    cur->next = last;
    last->next = secondLast;
    secondLast->next = *head;
}

int main() {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node nodes[100];

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &nodes[i].data);
        nodes[i].next = &nodes[(i + 1) % n];
    }

    struct Node* head = &nodes[0];

    printf("\nOriginal list:\n");
    printList(head);

    swapLastTwoNodes(&head);

    printf("\nAfter swapping last two nodes:\n");
    printList(head);

    return 0;
}
