#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n=0;
    printf("Enter a number: ");
    scanf("%d",&n);

    int*A=(int*)malloc(sizeof(int)*n);
    if(A==NULL)
    {
        printf("Memory allocation failed.....\n");
        exit(-1);
    }
}