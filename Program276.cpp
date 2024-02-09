// Bubble Sort Efficient

#include<iostream>
using namespace std;

class Array
{
    private:
        int *Arr;
        int iSize;

    public:
        Array(int X)        // Parametrised Constructor
        {
            iSize = X;
            Arr = new int[iSize];
        }

        ~Array()            // Destructor
        {   
            delete []Arr;
        }

        void Accept()       // Member function
        {
            int iCnt = 0;
            cout<<"Please enter the elements : "<<endl;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display()      // Member function
        {
            cout<<"Elements of the array are : "<<endl;
            int iCnt = 0;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<endl;
        }

        void BubbleSortEfficent(char choice)
        {
            int iTemp = 0;
            int i = 0, j = 0;
            bool bFlag = false;

            if(choice == 'I' || choice == 'i')
            {
                for(i = 0; i < iSize; i++)  // Outer
            {
                cout<<"Data after Pass : "<<(i+1)<<"\n";
                bFlag = false;

                for(j = 0; j < iSize-i-1; j++)  // Inner
                {
                    if(Arr[j] > Arr[j+1])   // It will display in decreaseing order
                    {
                        iTemp = Arr[j];
                        Arr[j] = Arr[j+1];
                        Arr[j+1] = iTemp;
                        bFlag = true;
                    }
                }

                if(bFlag == false)
                {
                    break;
                }
                Display();
            }
            }
            else if(choice == 'D' || choice == 'd')
            {
                for(i = 0; i < iSize; i++)  // Outer
            {
                cout<<"Data after Pass : "<<(i+1)<<"\n";
                bFlag = false;

                for(j = 0; j < iSize-i-1; j++)  // Inner
                {
                    if(Arr[j] < Arr[j+1])   // It will display in decreaseing order
                    {
                        iTemp = Arr[j];
                        Arr[j] = Arr[j+1];
                        Arr[j+1] = iTemp;
                        bFlag = true;
                    }
                }

                if(bFlag == false)
                {
                    break;
                }
                Display();
            }
            }
            else
            {
                cout<<"Invalid choice\n";
                cout<<"Use below choices\n";
                cout<<"I/i : Increasing order\n";
                cout<<"D/d : Decreasing order\n";
            }
        }
};

int main()
{
    int iLength = 0;
    char cChoice = '\0';

    cout<<"Enter the number of elements: "<<endl;
    cin>>iLength;

    Array *aobj = new Array(iLength);

    aobj->Accept();
    aobj->Display();
    
    cout<<"Please enter your choice for sorting : \n";
    cout<<"I/i : Increasing order\n";
    cout<<"D/d : Decreasing order\n";

    cin>>cChoice;

    aobj->BubbleSortEfficent(cChoice);

    aobj->Display();

    delete aobj;
    return 0;
}