// Singly Circular LinkedList in OOP
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class SinglyCL
{
    private:
        PNODE First;
        PNODE Last;
        int Count;

    public:
        SinglyCL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no, int ipos);
        void DeleteAtPos(int ipos);
};

SinglyCL::SinglyCL()
{
    First = NULL;
    Last = NULL;
    Count = 0;
}

void SinglyCL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))  // LL is empty
    {
        First = newn;
        Last = newn;       
     }
    else    // LL contains atleast 1 node
    {
        newn->next = First;
        First = newn;
    }
    (Last)->next = First;
    
    Count++;
}
void SinglyCL::InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))  // LL is empty
    {
        First = newn;
        Last = newn;
        Last->next = First;
     }
    else    // LL contains atleast 1 node
    {
        Last->next = newn;
        Last = newn;
        Last->next = First;
    }
    Count++;
}
void SinglyCL::Display()
{
    cout<<"Elements of Linked List are : \n";

    if((First != NULL) && (Last != NULL))
    {
        do
        {
            cout<<"| "<<First->data<<" | -> ";
            First = First -> next;
        }while(First != Last->next);

        cout<<"Address of Fisrt node\n";
    }
}
int SinglyCL::CountNode()
{
    return Count;
}
void SinglyCL::DeleteFirst()
{
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First ->next;
        delete Last->next;
        Last->next = First;
    }
    Count--;
}
void SinglyCL::DeleteLast()
{
    PNODE temp = First;

    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        while(temp->next != Last)
        {
	        temp = temp->next;
        }
        delete Last;
        Last = temp;
        Last->next = First;
    }
    Count--;
}
void SinglyCL::InsertAtPos(int no, int ipos)
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

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp ->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
    Count++;
}
void SinglyCL::DeleteAtPos(int ipos)
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
    }
    Count--;
}

int main()
{
    SinglyCL obj;
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