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

float CalculateArea(float fValue)
{
    auto float fArea = 0.0f;

    fArea = PI * fValue * fValue;
    return fArea;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function of an application which performs addition of 2 integers
//
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    auto float fRadius = 0.0f;
    auto float fResult = 0.0f;

    printf("Enter Radius of Circle : \n");
    scanf("%f",&fRadius);

    fResult = CalculateArea(fRadius);
    
    printf("Area of Circle is : %f\n",fResult);

    return 0;
}