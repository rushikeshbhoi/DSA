#include<stdio.h>

char ConvertCaptical(char cValue)
{
    return cValue - 32;
}

int main()
{
    char ch = '\0';
    char cRet = '\0';

    printf("Enter the character : \n");
    scanf("%c",&ch);

    cRet = ConvertCaptical(ch);

    printf("Converted Captical letter is : %c\n",cRet);

    return 0;
}