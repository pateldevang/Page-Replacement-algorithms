#include <stdio.h>
#include <stdlib.h>

int maximum(int ar[],int sz)
{
    int i,p=-1,pos=0;
    for(i=0;i<sz;i++)
    {
        if(ar[i]>p)
        {
            p=ar[i];
            pos=i;
        }
    }
    return pos;
}

void incval(int ar[],int sz)
{
    int i;
    for(i=0;i<sz;i++){
        if(ar[i]!=-1)
            ar[i]++;
    }
}

int main()
{
    int n,s,i,j,choice,pgflt=0,a,b;
    printf("Enter the number of pages:\n");
    scanf("%d",&n);
    int pages[n];
    printf("Enter the pages:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);
    printf("Enter the size of stack:\n");
    scanf("%d",&s);
    int stack[s],sval[s],m;
    printf("Do you want to initialize stack?(1-Yes,0-No)\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 0:
        for(i=0;i<s;i++){
            stack[i]=-1;
            sval[i]=-1;
        }
        break;
    case 1:
        printf("Enter the initialization stack:\n");
        for(i=0;i<s;i++){
            scanf("%d",&stack[i]);
            sval[i]=0;
        }
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
                printf("page hit! %d at %d\n",pages[i],j);
                incval(sval,s);
                sval[j]--;
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
                    incval(sval,s);
                    sval[j]=0;
                    printf("Fault with -1 at %d,entering %d\n",j,pages[i]);
                    break;
                }
            }
        }
        if(b==0)
        {
            m=maximum(sval,s);
            printf("Replacing %d with %d at %d\n",stack[m],pages[i],m);
            stack[m]=pages[i];
            incval(sval,s);
            sval[m]=0;
            pgflt++;
        }
    }
    printf("%d page faults for %d size of stack.\n",pgflt,s);
}
