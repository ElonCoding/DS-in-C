#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

struct Node* swapLastTwoNodes(struct Node* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        printf("Cannot swap last two nodes: list has less than three nodes.\n");
        return head;
    }

    struct Node* current = head;
    struct Node* secondLast = NULL;
    while (current->next->next != NULL) {
        secondLast = current;
        current = current->next;
    }

    struct Node* lastNode = current->next;

    current->next = NULL;
    lastNode->next = current;

    if (secondLast != NULL) {
        secondLast->next = lastNode;
    } else {
        head = lastNode;
    }

    printf("Last two nodes swapped successfully.\n");
    return head;
}

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
    int data;

    printf("Enter elements for the linked list (enter -1 to stop):\n");
    while (1) {
        printf("Enter data: ");
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        head = insertEnd(head, data);
    }

    printf("Original ");
    displayList(head);

    head = swapLastTwoNodes(head);
    displayList(head);

    struct Node* shortList = NULL;
    shortList = insertEnd(shortList, 10);
    shortList = insertEnd(shortList, 20);
    printf("\nOriginal (short list) ");
    displayList(shortList);
    shortList = swapLastTwoNodes(shortList);
    displayList(shortList);

    struct Node* singleNodeList = NULL;
    singleNodeList = insertEnd(singleNodeList, 100);
    printf("\nOriginal (single node) ");
    displayList(singleNodeList);
    singleNodeList = swapLastTwoNodes(singleNodeList);
    displayList(singleNodeList);

    struct Node* emptyList = NULL;
    printf("\nOriginal (empty) ");
    displayList(emptyList);
    emptyList = swapLastTwoNodes(emptyList);
    displayList(emptyList);

    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    current = shortList;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    current = singleNodeList;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}