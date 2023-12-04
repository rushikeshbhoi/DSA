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

// void InsertFirst(PPNODE Head, int no)
void Push(PPNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

// void DeleteFirst(PPNODE Head)
int Pop(PPNODE Head)
{
    int Value = 0;
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        printf("Stack is empty...");
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
    printf("Elements of Stack are : \n");

    while(Head != NULL)
    {
        printf("| %d |\n",Head->data);
        Head = Head->next;
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    Push(&First, 101);
    Push(&First, 51);
    Push(&First, 21);
    Push(&First, 11);

    Display(First);

    iRet = Pop(&First);
    printf("Poped element is : %d\n",iRet);

    iRet = Pop(&First);
    printf("Poped element is : %d\n",iRet);

    iRet = Pop(&First);
    printf("Poped element is : %d\n",iRet);

    iRet = Pop(&First);
    printf("Poped element is : %d\n",iRet);

    Display(First);

    return 0;
}