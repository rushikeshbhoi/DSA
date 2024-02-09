#include<stdio.h>

int CountCapitalR(char *str)
{
    static int iCount = 0;

    if(*str != '\0')
    {
        if(*str >= 'A' && *str <= 'Z')
        {
        iCount++;
        }
        str++;
        CountCapitalR(str);
    }

    return iCount;
}

int main()
{
    char Arr[20];
    int iRet = 0;

    printf("Enter string : \n");
    scanf("%[^'\n']s",Arr);

    iRet = CountCapitalR(Arr);

    printf("Length of Capital Letters is : %d\n",iRet);
    return 0;
}