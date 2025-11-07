#include <stdio.h>
#include <stdlib.h>

struct lstack
{
    int data;
    struct lstack *next;
};

struct lstack *top = NULL, *temp, *ttemp;

void init()
{
    temp = top = NULL;
}

void push(int val)
{
    ttemp = (struct lstack *)malloc(sizeof(struct lstack));
    ttemp->data = val;
    ttemp->next = top;
    top = ttemp;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int x;
        x = top->data;
        temp = top;
        top = top->next;
        free(temp);
        return x;
    }
}