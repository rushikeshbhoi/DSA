// Doubly Linear LinkedList in OOP
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE, *PNODE;

class DoublyLL
{
    private:
        PNODE First;
        int Count;

    public:
        DoublyLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no, int ipos);
        void DeleteAtPos(int ipos);
};

DoublyLL::DoublyLL()
{
    First = NULL;
    Count = 0;
}

void DoublyLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Count++;
}

void DoublyLL::InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = First;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
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
        newn->prev = temp;
    }
    Count++;
}

void DoublyLL::Display()
{
    cout<<"Elements of LinkedList are : \n";

    PNODE temp = First;
    cout<<"NULL <=> ";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int DoublyLL::CountNode()
{
    return Count;
}
void DoublyLL::DeleteFirst()
{
    PNODE temp = First;

    if(First == NULL)
    {
        return;
    }
    else if((First->next == NULL) && (First->prev == NULL))
    {
        delete temp;
        temp = NULL;
    }
    else
    {
        temp = temp->next;
        delete temp->prev;
        temp->prev = NULL;
    }
    Count--;
}

void DoublyLL::DeleteLast()
{
    PNODE temp = First;

    if(First == NULL)
    {
        return;
    }
    else if((First->next == NULL) && (First->prev == NULL))
    {
        delete temp;
        temp = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}
void DoublyLL::InsertAtPos(int no, int ipos)
{
    int size = 0, i = 0;
    size = Count;
    PNODE newn = NULL;
    PNODE temp = First;

    if((ipos < 1)||(ipos > size+1))
    {
        cout<<"Invalid Position\n";
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
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn; 
        temp->next = newn;
        newn->prev = temp; 
    }
    Count++;
}
void DoublyLL::DeleteAtPos(int ipos)
{
    int size = 0, i = 0;
    size = Count;
    PNODE temp = First;

    if((ipos < 1)||(ipos > size))
    {
        cout<<"Invalid Position\n";
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
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;        
        temp->next->prev = temp;
    }
    Count--;
}

int main()
{
    DoublyLL obj;
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