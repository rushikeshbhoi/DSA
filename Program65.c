#include<stdio.h>
#include<stdlib.h>

int Frequency(int Arr[], int iSize, int iNo)
{
    int iCnt = 0;
    int iFrequency = 0;
    
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            iFrequency++;
        }
    }
    return iFrequency;
}

int main()
{
    int iCount = 0, iCnt = 0, iRet = 0, iValue = 0;
    int *ptr = NULL;

    printf("Enter the number of elements \n");
    scanf("%d",&iCount);

    ptr = (int *) malloc (iCount * sizeof(int));
    printf("Dynamic memory gets allocated successfully...\n");

    printf("Enter the elements : \n");
    for(iCnt = 0; iCnt < iCount; iCnt++)
    {
        printf("\nEnter the element no %d : ",iCnt+1);
        scanf("%d",&ptr[iCnt]);
    }

    printf("Enter the element that you want to search");
    scanf("%d",&iValue);

    iRet = Frequency(ptr, iCount, iValue);

    printf("%d occurs %d times\n",iValue,iRet);

    free(ptr);
    
    printf("Dyanmic memory gets deallocated successfully...\n");

    return 0;
}