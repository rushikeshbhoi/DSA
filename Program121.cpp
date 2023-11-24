#include<iostream>
using namespace std;

class Array
{
    private:
        int *Arr;
        int iSize;

    public:
        Array(int X)    // Parameterised Constructor
        {
            iSize = X;
            Arr = new int[iSize];
        }

        ~Array()    //  Destructor
        {
            delete []Arr;
        }

        void Accept()   // Member Function
        {
            int iCnt = 0;
            cout<<"Please enter the elements : "<<endl;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display()  //  Member Function
        {
            int iCnt = 0;
            cout<<"Elements of the array are : "<<endl;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<endl;
        }
};  //  End of class

int main()
{
    int iLength = 0;

    cout<<"Enter the number of elements that you want to store : "<<endl;
    cin>>iLength;

    Array *aboj = new Array(iLength);

    aboj->Accept();
    aboj->Display();

    delete aboj;
    
    return 0;
}