#include<stdio.h>

void DisplayExamTime(int iStandard)
{
    if(iStandard == 1)
    {
        printf("Your exam starts at 8 AM \n");
    }
    else if(iStandard == 2)
    {
        printf("Your exam starts at 9 AM \n");
    }
    else if(iStandard == 3)
    {
        printf("Your exam starts at 10 AM \n");
    }
    else if(iStandard == 4)
    {
        printf("Your exam starts at 11 AM \n");
    }
    else if(iStandard == 5)
    {
        printf("Your exam starts at 12 PM \n");
    }
    else
    {
        printf("Invalid Input...\n");
    }
}

int main()
{
    auto int iValue = 0;

    printf("Enter your standard : \n");
    scanf("%d",&iValue);

    DisplayExamTime(iValue);

    return 0;
}