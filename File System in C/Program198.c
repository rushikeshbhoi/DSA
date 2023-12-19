// 4.To write the data into the file
#include<stdio.h>
#include<stdlib.h>  
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;
    int iRet = 0;
    char Arr[] = "How are you doing?";

    fd = open("Rushikesh.txt",O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        iRet = write(fd, Arr, 19);
        printf("%d bytes gets succesfully written into the files\n",iRet);

        close(fd);
    }

    return 0;
}