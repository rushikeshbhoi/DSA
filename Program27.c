// Problem Statement : Write a program to print Jay Ganesh 5 times

#include<stdio.h>

void Display(int iNo)
{
    int iCnt = 0;
   
    for (iCnt = 1; iCnt <= iNo; iCnt++)
    {
    printf("Jay Ganesh...\n");  
    }
}

int main()
{
    Display(8);

    return 0;
}