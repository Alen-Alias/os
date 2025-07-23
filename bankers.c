#include<stdio.h>
struct process
{
    int status;
    int alloc[5],max[5],need[5];
}p[10];
void display(int avail[],int nop,int nor)
{
    int i,j;
    printf("\nprocess\tAlloc\t\tMax  \t\t  avail\t\tNeed\n");
    for(i=0;i<nop;i++)
    {
        printf("P%d\t",i);
        for(j=0;j<nor;j++)
            printf("%d ",p[i].alloc[j]);
        printf("\t");
        for(j=0;j<nor;j++)
            printf("%d ",p[i].max[j]);
        printf("\t");
        if(i==0)
        {
            for(j=0;j<nor;j++)
                printf("%d ",avail[j]);
            printf("\t");
        }
        else
            printf("\t\t");
        for(j=0;j<nor;j++)
            printf("%d ",p[i].need[j]);
        printf("\n");
    }
}
void issafe(int avail[],int nop,int nor)
{
    int i,j,m,flag,k=0,count=0,safe[10];
    for(m=0;m<nop;m++)
    {
    for(i=0;i<nop;i++)
    {
        if(p[i].status==0)
        {
            flag=0;
            for(j=0;j<nor;j++)
            {
                if(p[i].need[j]>avail[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                safe[k++]=i;
                p[i].status=1;
                for(j=0;j<nor;j++)
                    avail[j]=avail[j]+p[i].alloc[j];
                count++;
            }
        }
    }
    }
    if(count!=nop)
    {
        printf("System is not in safe state\n");
        return;
    }
    else
    {
        printf("System is in safe state\n");
        printf("Safe sequence is : ");
        for(i=0;i<nop;i++)
            printf("P%d ",safe[i]);
    }
}
void main()
{
    int i,j,avail[5],tempavail[5],req[5],nop,nor,reqp;
    printf("Enter the number of process : ");
    scanf("%d",&nop);
    printf("Enter the number of resourses : ");
    scanf("%d",&nor);
    for(i=0;i<nop;i++)
    {
        printf("Enter the resource allocated : ");
        for(j=0;j<nor;j++)
        {
            scanf("%d",&p[i].alloc[j]);
            p[i].status=0;
        }
        printf("Enter the max resource required : ");
        for(j=0;j<nor;j++)
        {
            scanf("%d",&p[i].max[j]);
            p[i].need[j]=p[i].max[j]-p[i].alloc[j];
        }

    }
    printf("Enter the available resources : ");
    for(i=0;i<nor;i++)
    {
        scanf("%d",&avail[i]);
    }
    display(avail,nop,nor);
    for(i=0;i<nor;i++)
    {
        tempavail[i]=avail[i];
    }

    issafe(avail,nop,nor);
for(i=0;i<nop;i++)
{
p[i)].status=0;
}
    for(i=0;i<nor;i++)
    {
        avail[i]=tempavail[i];
    }
    printf("\nEnter the requesting process : ");
    scanf("%d",&reqp);
    printf("Enter the request : ");
    for(i=0;i<nor;i++)
    {
        scanf("%d",&req[i]);
    }
    for(i=0;i<nor;i++)
    {
        if(req[i]>p[reqp].need[i])
        {
            printf("Error: Request is more than need\n");
            return;
        }
        if(req[i]>avail[i])
        {
            printf("Error: Request is more than available\n");
            return;
        }
    }
    for(i=0;i<nor;i++)
    {
        avail[i]=avail[i]-req[i];
        p[reqp].alloc[i]=p[reqp].alloc[i]+req[i];
        p[reqp].need[i]=p[reqp].need[i]-req[i];
    }
    printf("After allocation\n");
    display(avail,nop,nor);
    issafe(avail,nop,nor);
}
