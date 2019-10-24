#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s,i,j,choice,pgflt=0,pgh,ci=0;
    printf("Enter the number of pages:\n");
    scanf("%d",&n);
    int pages[n];
    printf("Enter the pages:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);
    printf("Enter the size of stack:\n");
    scanf("%d",&s);
    int stack[s];
    printf("Do you want to initialize stack?(1-Yes,0-No)\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 0:
        for(i=0;i<s;i++)
            stack[i]=-1;
        break;
    case 1:
        printf("Enter the initialization stack:\n");
        for(i=0;i<s;i++)
            scanf("%d",&stack[i]);
        break;
    default:
        printf("Wrong choice,exiting execution!");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        pgh=0;
        for(j=0;j<s;j++)
        {
            if(stack[j]==pages[i])
                pgh=1;
        }
        if(pgh==0)
        {
            printf("Page fault detected:%d replacing %d\n",pages[i],stack[ci]);
            stack[ci]=pages[i];
            ci=(ci+1)%s;
            pgflt++;
        }
    }
    printf("Page Faults are %d with stack size %d\n",pgflt,s);
}
