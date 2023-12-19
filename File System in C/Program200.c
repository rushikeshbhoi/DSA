// 5.To read the data from the file
#include<stdio.h>
#include<stdlib.h>  
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;
    int iRet = 0;
    char Arr[50] = {"\0"};

    fd = open("Rushikesh.txt",O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        iRet = read(fd, Arr, 14);
        printf("%d bytes gets succesfully read into the files\n",iRet);

        printf("%s\n",Arr);

        close(fd);
    }

    return 0;
}