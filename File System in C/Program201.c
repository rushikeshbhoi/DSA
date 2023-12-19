// 6.To delete the file
#include<stdio.h>
#include<stdlib.h>  
#include<unistd.h>
#include<fcntl.h>

int main()
{
    unlink("Rushikesh.txt");

    return 0;
}