#include<stdio.h>
#include<stdlib.h>

// Structure Declaration
struct Node
{
    int data;           // 4 Bytes
    struct node *next;  // 8 Bytes
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE; 

int main()
{
    PNODE First = NULL;

    return 0;
}