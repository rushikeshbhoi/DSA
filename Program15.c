// Problem Statement : Accpet the students percentage and display its class

#include<stdio.h>

void DisplayClass (float fMarks)
{
    if((fMarks < 0.00) || (fMarks > 100.00))    // Filter
    {
        printf("Invalid Marks...\n");
    }

    if((fMarks >= 0.00) && (fMarks < 35.00))
    {
        printf("Your are fail...\n");
;    }
    else if((fMarks >= 35.00) && (fMarks < 50.00))
    {
        printf("Your class is Pass class\n");
    }
    else if((fMarks >= 50.00) && (fMarks < 60.00))
    {
        printf("Your class is Second class\n");
    }
    else if((fMarks >= 60.00) && (fMarks < 75.00))
    {
        printf("Your class is First class");
    }
    else if((fMarks >= 75.00) && (fMarks < 100.00))
    {
        printf("Your class is First with Distinction\n");
    }
}

int main()
{
    auto float fValue = 0.0f;

    printf("Enter the percentage : \n");
    scanf("%f",&fValue);

    DisplayClass(fValue);

    return 0;
}