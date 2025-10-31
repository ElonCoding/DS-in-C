#include <stdio.h>

typedef struct mytype
{
    int a;
    float b;
} mytype;
int main()
{
    struct mytype m1, m2;
    mytype m1, m2;
    printf("\n&m1.a=%p\t&m1.b=%p", (void*)&m1.a, (void*)&m1.b);
    printf("\nSize of m1=%zu", sizeof(m1));
    printf("\nSize of m2=%zu", sizeof(m2));
    printf("\nEnter m1.a and m1.b: ");
    scanf("%d%f", &m1.a, &m1.b);
    printf("\nEnter m2.a and m2.b: ");
    scanf("%d%f", &m2.a, &m2.b);
    return 0;
}