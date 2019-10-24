#include <stdio.h>
#include <stdlib.h>

int findpos(int st[],int s,int pg[],int p,int curr)
{
    int q,r,h=-1,l=0;
    for(q=0;q<s;q++)
    {
        l=0;
        for(r=curr;r<p;r++)
        {
            if(pg[r]==st[q] && h==-1)
            {
                h=q;
                break;
            }
            if(pg[r]==st[q] && h>r)
            {
                h=q;
                break;
            }
            if(pg[r]!=st[q])
                l++;
        }
        if(l>=(p-curr))
            return q;
    }

    return h;
}

int main()
{
    int n,s,i,j,choice,pgflt=0,ci=0,a,b;
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
        a=0;b=0;
        for(j=0;j<s;j++)
        {
            if(stack[j]==pages[i])
            {
                a=1;b=1;
            }
        }
        if(a==0)
        {
            for(j=0;j<s;j++)
            {
                if(stack[j]==-1)
                {
                    stack[j]=pages[i];
                    b=1;
                    pgflt++;
                    break;
                }
            }
        }
        if(b==0)
        {
            ci=findpos(stack,s,pages,n,i);
            stack[ci]=pages[ci];
            pgflt++;
        }
    }
    printf("%d page faults with stack size %d\n",pgflt,s);
    return 0;
}
