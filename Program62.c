#include<stdio.h>
#include<stdlib.h>

int iMinimum(int Arr[], int iSize)
{
    int iCnt = 0;
    int iMin = Arr[0];
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] < iMin)
        {
            iMin = Arr[iCnt];
        }
    }
    return iMin;
}

int main()
{
    int iCount = 0, iCnt = 0;
    int *ptr = NULL;
    int iRet = 0;

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

    iRet = iMinimum(ptr, iCount);

    printf("The minimum element of array is : %d\n",iRet);

    free(ptr);
    
    printf("Dyanmic memory gets deallocated successfully...\n");

    return 0;
}