#include<stdio.h>

void DisplayR(int iNo)
{
    static int iCnt = 1;

    while(iCnt <= iNo)
    {
        printf("%d\n",iCnt);
        iCnt++;
        DisplayR(iNo);
    }
}

int main()
{
    int iNo = 0;
    
    DisplayR(4);

    return 0;
}