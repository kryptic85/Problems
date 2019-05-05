#include <stdlib.h>
#include <stdio.h>
#include "int.h"


enum eProblems{
    SEARCH_INSERT_POSTION=1,
    MAX,
}eProblems;


int main(int argc, char *argv[])
{
    int idx;
    
    printf("\nEnter case to run:");
    scanf("%d", &idx);
    
    if (SEARCH_INSERT_POSTION == idx)
    {
        int fidx = 0;
        int A[] = {4, 6, 8, 9, 12};

        fidx = searchInsert(A, 5, 5);
        printf("target indx: %d", fidx);
    }

return 0;
}
