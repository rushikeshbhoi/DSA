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

void InsertFirst(PPNODE Head, int No)
{
    // Step 1 : Allocate memory for node
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    // Step 2 : Initialise the node
    newn->data = No;
    newn->next = NULL;

    // Step 3 : Check whether Linkedlist is empty or not
    if(*Head == NULL)   // LL is empty
    {
        *Head = newn;
    }
    else    //  LL contains atleast 1 node in it
    {
        newn -> next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head)
{
    printf("Elements of Linked List are : \n");

    while(Head != NULL)
    {
        printf("| %d | -> ", Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    Display(First);

    return 0;
}