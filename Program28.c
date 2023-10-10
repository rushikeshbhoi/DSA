// Problem Statement : Accept a value from user and print Jay Ganesh that number of times

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
    int iValue = 0;
    printf("Enter number of times you want to display Jay Ganesh on screen\n");
    scanf("%d",&iValue);
    Display(iValue);

    return 0;
}