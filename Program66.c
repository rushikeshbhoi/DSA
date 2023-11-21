#include<stdio.h>

void Display()
{
    int iCnt = 0;
    
    for(iCnt = 1; iCnt <= 6; iCnt++)
    {
        printf("*\t");
    }
    printf("\n");
}

int main()
{

    Display();

    return 0;
}