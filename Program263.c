#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE, *PNODE, **PPNODE;

void Insert(PPNODE Head, int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*Head == NULL)   // BST is empty
    {
        *Head = newn;
    }
    else    // BST contains at least one node
    {
        while(1)    // Unconditional loop
        {
            if(no == temp->data)
            {
                printf("Unable to insert as data is already present\n");
                free(newn);
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }

                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }

                temp = temp->lchild;
            }
        }
    }
}

void Inorder(PNODE Head)
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);
        printf("%d\n",Head->data);
        Inorder(Head->rchild);
    }
}

void Preorder(PNODE Head)
{
    if(Head != NULL)
    {
        printf("%d\n",Head->data);
        Preorder(Head->lchild);
        Preorder(Head->rchild);
    }
}

void Postorder(PNODE Head)
{
    if(Head != NULL)
    {
        Postorder(Head->lchild);
        Postorder(Head->rchild);
        printf("%d\n",Head->data);
    }
}

bool Search(PNODE Head, int no)
{
    bool flag = false;

    if(Head == NULL)
    {
        printf("Tree is empty\n");
        return false;
    }

    while(Head != NULL)
    {
        if(no == Head->data)
        {
            flag = true;
            break;
        }
        else if(no > Head->data)
        {
            Head = Head->rchild;
        }
        else if(no < Head->data)
        {
            Head = Head->lchild;
        }
    }

    return flag;
}

int Count(PNODE Head)
{
    static int iCount;

    if(Head != NULL)
    {
        iCount++;
        Count(Head->lchild);
        Count(Head->rchild);
    }

    return iCount;
}

int CountLeaf(PNODE Head)
{
    static int iCount;

    if(Head != NULL)
    {
        if((Head->lchild == NULL) && (Head->rchild == NULL))
        {
            iCount++;
        }
        CountLeaf(Head->lchild);
        CountLeaf(Head->rchild);
    }

    return iCount;
}

int CountParent(PNODE Head)
{
    static int iCount;

    if(Head != NULL)
    {
        if((Head->lchild != NULL) || (Head->rchild != NULL))
        {
            iCount++;
        }
        CountParent(Head->lchild);
        CountParent(Head->rchild);
    }

    return iCount;
}

int Summation(PNODE Head)
{
    static int iSum = 0;

    if(Head != NULL)
    {
        iSum = iSum + (Head->data);

        Summation(Head->lchild);
        Summation(Head->rchild);
    }

    return iSum;
}

int CountEven(PNODE Head)
{
    static int iCount = 0;

    if(Head != NULL)
    {
        if((Head->data % 2) == 0)
        {
            iCount++;
        }

        CountEven(Head->lchild);
        CountEven(Head->rchild);
    }

    return iCount;
}

int CountOdd(PNODE Head)
{
    static int iCount = 0;

    if(Head != NULL)
    {
        if((Head->data % 2) != 0)
        {
            iCount++;
        }

        CountOdd(Head->lchild);
        CountOdd(Head->rchild);
    }

    return iCount;
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;
    bool bRet = false;

    Insert(&first,21);
    Insert(&first,11);
    Insert(&first,17);
    Insert(&first,45);
    Insert(&first,10);
    Insert(&first,78);
    Insert(&first,30);
    Insert(&first,5);
    Insert(&first,11);

    Inorder(first);

    iRet = Count(first);

    printf("Number of elements are : %d\n",iRet);

    iRet = CountLeaf(first);

    printf("Number of leaf nodes are : %d\n",iRet);

    iRet = CountParent(first);

    printf("Number of parent nodes are : %d\n",iRet);

    iRet = Summation(first);

    printf("Sum of all nodes are : %d\n",iRet);

    iRet = CountEven(first);

    printf("Even elements are : %d\n",iRet);

    iRet = CountOdd(first);

    printf("Odd elements are : %d\n",iRet);

    return 0;
}