#include<stdio.h>
#include<stdlib.h>

// Structure Declaration
struct Node
{
    int data;           // 4 Bytes
    struct node *next;  // 8 Bytes
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE; 

void InsertFirst(struct Node ** Head, int No)
{
    struct Node * newn = NULL;
    newn = (struct Node *) malloc (sizeof(struct Node));

    newn->data = No;
    newn->next = NULL;
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    return 0;
}