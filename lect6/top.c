#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int data[MAX];
    int topA, topB;
} Mstack;
Mstack *p;
void init()
{
    p = (Mstack *)malloc(sizeof(Mstack));
    p->topA = -1;
    p->topB = MAX;
}
int topA()
{
    if (p->topA == -1)
    {
        printf("Stack A is empty\n");
        return -1;
    }
    else
    {
        return p->data[p->topA];
    }
}
int topB()
{
    if (p->topB == MAX)
    {
        printf("Stack B is empty\n");
        return -1;
    }
    else
    {
        return p->data[p->topB];
    }
}
void pushA(int val)
{
    if (p->topA + 1 == p->topB)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        p->topA++;
        p->data[p->topA] = val;
    }
}
void pushB(int val)
{
    if (p->topB - 1 == p->topA)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        p->topB--;
        p->data[p->topB] = val;
    }
}
int main ()
{
    init();
    pushA(10);
    pushA(20);
    pushB(30);
    pushB(40);
    printf("Top of Stack A: %d\n", topA());
    printf("Top of Stack B: %d\n", topB());
    return 0;
}