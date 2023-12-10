// Doubly Circular LinkedList in OOP
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE, *PNODE;

class DoublyCL
{
    private:
        PNODE First;
        PNODE Last;
        int Count;

    public:
        DoublyCL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no, int ipos);
        void DeleteAtPos(int ipos);
};

DoublyCL::DoublyCL()
{
    First = NULL;
    Last = NULL;
    Count = 0;
}

void DoublyCL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))  // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;

    Count++;
}

void DoublyCL::InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))  // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->prev = Last;
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    First->prev = Last;

    Count++;
}

void DoublyCL::Display()
{
    cout<<"Elements of LinkedList are : \n";

    if(First != NULL && Last != NULL)
    {
        do
        {
            printf("| %d | <=>",First->data);
            First = First->next;
        }while(First != Last->next);
    }
}
int DoublyCL::CountNode()
{
    return Count;
}
void DoublyCL::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))    // LL is empty
    {
        return;
    }
    else if(First == Last)   // LL contains single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // LL contains more than one node
    {
        First = First->next;
        delete Last->next;
        First->prev = Last;
        Last->next = First;
    }
    Count--;
}
void DoublyCL::DeleteLast()
{
    if((First == NULL) && (Last == NULL))    // LL is empty
    {
        return;
    }
    else if(First == Last)   // LL contains single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // LL contains more than one node
    {
        Last = Last->prev;
        delete Last->next;
        Last->next = First;
        First->prev = Last;
    }
    Count--;
}
void DoublyCL::InsertAtPos(int no, int ipos)
{
    int size = 0, i = 0;
    size = Count;
    PNODE newn = NULL;

    PNODE temp = First;

    if((ipos < 1) || (ipos > size+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
       InsertFirst(no); 
    }
    else if(ipos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp ->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}
void DoublyCL::DeleteAtPos(int ipos)
{
    int size = 0, i = 0;
    size = Count;

    PNODE temp = First;
    PNODE targatednode = NULL;

    if((ipos < 1) || (ipos > size))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
       DeleteFirst(); 
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        for(i = 1; i < ipos-1; i++)
        {
            temp = temp ->next;
        }

        targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;
        temp->next->prev = temp;
    }
    Count--;
}

int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.InsertAtPos(105,5);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
    
    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
   
    return 0;
}