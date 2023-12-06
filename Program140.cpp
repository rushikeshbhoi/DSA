// Singly Linear LinkedList in OOP

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class SinglyLL
{
    private:
        PNODE First;
        int Count;

    public:
        SinglyLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no, int ipos);
        void DeleteAtPos(int ipos);
};

/*
Return_Value Class_Name :: Function_Name()
*/
SinglyLL::SinglyLL()
{
    cout<<"Inside constructor\n";
    First = NULL;
    Count = 0;
}

void SinglyLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)   // if (Count == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Count++;
}

void SinglyLL::InsertLast(int no)
{
    PNODE temp = First;
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)   // if (Count == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

void SinglyLL::Display()
{
    PNODE temp = First;

    cout<<"Elements of the LinkedList are : \n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL \n";
}

int SinglyLL::CountNode()
{
    return Count;
}

void SinglyLL::DeleteFirst()
{
    PNODE temp = First;

    if(First == NULL)   // LL is empty
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
    }
    Count--;
}

void SinglyLL::DeleteLast()
{

    if(First == NULL)   // LL is empty
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

void SinglyLL::InsertAtPos(int no, int ipos)
{
    if((ipos < 1)||(ipos > Count+1))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        PNODE temp = First;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

void SinglyLL::DeleteAtPos(int ipos)
{
    if((ipos < 1)||(ipos > Count))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        int i = 0;

        for(i = 1; i < ipos; i++)
        {
            temp = temp->next;
        }

        PNODE targetednode = temp->next;

        temp->next = temp->next->next;
        delete targetednode;

        Count--;
    }
}

int main()
{
    int iRet = 0;
    SinglyLL obj;

    obj.InsertFirst(111);
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
    
    obj.InsertAtPos(105,5);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.DeleteAtPos(5);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    return 0;
}