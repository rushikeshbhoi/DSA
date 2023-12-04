// Stack
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// void InsertLast(PPNODE Head, int no)
void Enqueue(PPNODE Head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = *Head;

    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

// void DeleteFirst(PPNODE Head)
int Dequeue(PPNODE Head)
{
    int Value = 0;
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        printf("Queue is empty...");
        return Value;
    }
    else
    {
        Value = (*Head)->data;
        *Head = (*Head)->next;
        free(temp);
    }

    return Value;
}
void Display(PNODE Head)
{
    printf("Elements of Queue are : \n");

    while(Head != NULL)
    {
        printf("| %d |\t",Head->data);
        Head = Head->next;
    }
    printf("\n");
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    Enqueue(&First, 11);
    Enqueue(&First, 21);
    Enqueue(&First, 51);
    Enqueue(&First, 101);
    
    Display(First);

    iRet = Dequeue(&First);
    printf("Removed element from queue is : %d\n",iRet);

    iRet = Dequeue(&First);
    printf("Removed element from queue is : %d\n",iRet);

    Display(First);

    return 0;
}