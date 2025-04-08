/*ALEN ALIAS, CSE A,25*/
#include<stdio.h>
#include<string.h>
#define max 100
int Q[max],front=-1,rear=-1;
struct process
{
    char name[4];
    int at,bt,wt,tt,ct,left,status;
}p[10],temp;
struct done
{
    char name[4];
    int st,ct;
}d[30];
void enqueue(int item)
{
    if(front==-1 && rear==-1)
    {
        front++;
    }
    rear++;
    Q[rear]=item;
}
int dequeue()
{
    int temp=Q[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
    return temp;
}
void main()
{
    int i,j,n,num,idle=0,ls,k,slice;
    float awt=0;
    float att=0;
    printf("Enter Number of Processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)                         
    {
    printf("\nPROCESS : %d",i+1);
    printf("\nName : ");
    scanf(" %s",p[i].name);
    printf("Arrival Time : ");
    scanf("%d",&p[i].at);
    printf("Burst Time : ");
    scanf("%d",&p[i].bt);
    p[i].status = 0;
    p[i].left=p[i].bt;
    } 
    printf("Enter the Time Slice/Quantum : ");
    scanf("%d",&slice);
    i=0,num=0,ls=0;
    while(ls<n)
    {
        for(j=0;j<n;j++)
        {
            if(p[j].at<=i && p[j].status==0)
            {
                enqueue(j);
                p[j].status=1;
            }
        }
        if(front==-1 && idle==0)
        {
            strcpy(d[num].name,"idle");
            d[num].st=i;
            i++;  
            idle=1;
        }
        else if(front!=-1)
        {
            if(idle==1)
            {
                d[num].ct=i;
                num++;
                idle=0;
            }
            k=dequeue();
            d[num].st=i;
            strcpy(d[num].name,p[k].name);
            if(p[k].left<=slice)
            {
                d[num].ct=i+p[k].left;
                p[k].ct=d[num].ct;
                i=d[num].ct;
                p[k].tt=i-p[k].at;
                p[k].wt=p[k].tt-p[k].bt;
                num++;
                ls++;
                p[k].status=2;


            }
            else if(p[k].left>slice)
            {
                d[num].ct=i+slice;
                p[k].ct=d[num].ct;
                i=d[num].ct;
                p[k].left=p[k].left-slice;
                num++;
                for(j=0;j<n;j++)
                {
                    if(p[j].at<=i && p[j].status==0)
                    {
                        enqueue(j);
                        p[j].status=1;
                    }
                }
                enqueue(k);
            }
        }
        else
        {
            i++;
        }
    }
    printf("\nP\tAT\tBT\tCT\tTT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf(" %s\t%d\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
        awt+=p[i].wt;
        att+=p[i].tt;
    }
    printf("\nGANTT CHART");
    printf("\n--------------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<num;i++)
    {
        printf("|");
        printf(" %s\t",d[i].name);
    }
    printf(" |");
    printf("\n--------------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<num;i++)
    {
        printf("%d\t",d[i].st);
    }
    printf("%d\t",d[num-1].ct);
    printf("\nAverage Waiting time : %f",(awt/n));
    printf("\nAverage Turnaround Time : %f\n",(att/n));

}
/*
Enter Number of Processes : 3

PROCESS : 1
Name : 1
Arrival Time : 0
Burst Time : 2

PROCESS : 2
Name : 2
Arrival Time : 3
Burst Time : 6

PROCESS : 3
Name : 3
Arrival Time : 3
Burst Time : 1
Enter the Time Slice/Quantum : 2

P       AT      BT      CT      TT      WT
 1      0       2       2       2       0
 2      3       6       10      7       1
 3      3       1       6       3       2

GANTT CHART
--------------------------------------------------------------------------------------------------------------------
| 1     | idle  | 2     | 3     | 2     | 2      |
--------------------------------------------------------------------------------------------------------------------
0       2       3       5       6       8       10
Average Waiting time : 1.000000
Average Turnaround Time : 4.000000


Enter Number of Processes : 4

PROCESS : 1
Name : p0
Arrival Time : 2
Burst Time : 4

PROCESS : 2
Name : p1 
Arrival Time : 3
Burst Time : 5

PROCESS : 3
Name : p2
Arrival Time : 4
Burst Time : 7

PROCESS : 4
Name : p3
Arrival Time : 5
Burst Time : 8
Enter the Time Slice/Quantum : 2

P       AT      BT      CT      TT      WT
 p0     2       4       10      8       4
 p1     3       5       19      16      11
 p2     4       7       24      20      13
 p3     5       8       26      21      13

GANTT CHART
--------------------------------------------------------------------------------------------------------------------
| idle  | p0    | p1    | p2    | p0    | p3    | p1    | p2    | p3    | p1    | p2    | p3    | p2    | p3     |
--------------------------------------------------------------------------------------------------------------------
0       2       4       6       8       10      12      14      16      18      19      21      23      24      26
Average Waiting time : 10.250000
Average Turnaround Time : 16.250000
*/