// Singly Linear LinkedList in OOP

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

class SinglyLL
{
    private:
        PNODE First;
        int Count;

    public:
        SinglyLL()
        {
            cout<<"Inside constructor\n";
            First = NULL;
            Count = 0;
        }

        void InsertFirst(int no)
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

        void InsertLast(int no)
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
        void Display()
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

        int CountNode()
        {
            return Count;
        }
};

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
    
    return 0;
}