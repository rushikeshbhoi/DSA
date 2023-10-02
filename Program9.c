// Problem Statement : Accept radius from user and calculate the area of circle

// Step 1 : Understand the program statement
// Conclusion : We are going to use the formula as PI*R*R

// Steo 2 : Algorithm
/*
    START
        Accept radius from user and store into RADIUS
        Create variable as PI and store value 3.14
        Calculate area PI * RADIUS * RADIUS
        Display the value of Area to the user
    STOP
*/

#include<stdio.h>

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : CalculateArea
//  Description   : It is used to calculate area of circle
//  Input         : Float
//  Output        : Float
//  Auther Name   : Rushikesh Dhanlal Bhoi
//  Date          : 02/10/2023
//
/////////////////////////////////////////////////////////////////////////////////

#define PI 3.14

double CalculateArea(double fValue)
{
    auto double fAns = 0.0;
    
    fAns = PI * fValue * fValue;
    return fAns;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function of an application which performs addition of 2 integers
//
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    auto double fRadius = 0.0;
    auto double fResult = 0.0;

    printf("Enter the radius of circle : \n");
    scanf("%lf",&fRadius);

    fResult = CalculateArea(fRadius);

    printf("Area of circle is : %lf\n",fResult);

    return 0;
}