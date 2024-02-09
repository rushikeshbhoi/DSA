#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)   // LL is empty
    {
        *Head = newn;
    }
    else
    {
        newn -> next = *Head;
        *Head = newn;
    }
}


void Display(PNODE Head)
{
    printf("Contents of Linked List : \n");

    while(Head != NULL)
    {
        printf("| %d | -> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

bool LoopCheck(PNODE Head)
{
    PNODE Slow = Head;
    PNODE Fast = Head;
    bool bFlag = false;

    while((Slow != NULL) && (Fast->next != NULL))
    {
        Slow = Slow->next;
        Fast = Fast->next->next;

        if(Slow == Fast)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

int main()
{
    PNODE First = NULL;
    bool bRet = false;
    
    PNODE ThirdNode = NULL;
    PNODE LastNode = NULL;

    InsertFirst(&First, 111);
    InsertFirst(&First, 101);
    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);
    
    ThirdNode = First;
    LastNode = First;

    ThirdNode = ThirdNode->next->next;
    LastNode = LastNode->next->next->next->next;
    LastNode->next = ThirdNode;

    bRet = LoopCheck(First);

    if(bRet == true)
    {
        printf("Loop detected in the LinkedList...\n");
    }
    else
    {
        printf("No Loop detected in the LinkedList...\n");

    }

    return 0;
}