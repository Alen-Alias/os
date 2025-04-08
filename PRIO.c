/*ALEN ALIAS, CSE A,25*/
#include<stdio.h>
#include<string.h>
struct process
{
  char name[20];
  int at,pr,tt,bt,wt,ct,status;
}p[20],temp;
struct done
{
  char name[20];
  int st,ct;
}d[20];
void main()
{
  int i,j,n,num,min,ls,found,idle;
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
    printf("PRIORTY : ");
    scanf("%d",&p[i].pr);
    p[i].status = 0;
  }
  i=0,ls=0,num=0,idle=0;
  while(ls<n)
  {
    found=0;
    for(j=0;j<n;j++)
    {
      if(p[j].at<=i && p[j].status==0)
      {
        if(found==0)
        {
          min=j;
          found=1;
        }
        else if(found!=0 && p[min].pr>=p[j].pr || (p[min].pr==p[j].pr && p[min].at>p[j].at))
        {
          min=j;
        }
      }
    }
    if(found==0 && idle==0)
    {
      strcpy(d[num].name,"Idle");
      d[num].st=i;
      i++;
      idle=1;
    }
    else if(found==1)
    {
      if(idle==1)
      {
        d[num].ct=i;
        num++;
        idle=0;
      }
      else
      {
        strcpy(d[num].name,p[min].name);
        d[num].st=i;
        d[num].ct=i+p[min].bt;
        p[min].ct=d[num].ct;
        p[min].tt=p[min].ct-p[min].at;
        p[min].wt=p[min].tt-p[min].bt;
        p[min].status=1;
        i=d[num].ct;
        num++;
        ls++;
      }
    }
    else
    { 
      i++;
    }
  }
  printf("\nP\tAT\tBT\tPR\tCT\tTT\tWT\n");
  for(int i=0;i<n;i++)
  {
    printf(" %s\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tt,p[i].wt);
    awt+=p[i].wt;
    att+=p[i].tt;
  }
  printf("\nGANTT CHART");
  printf("\n----------------------------------------------------------\n");
  for(i=0;i<num;i++)
  {
    printf("|");
    printf(" %s\t",d[i].name);
  }
  printf(" |");
  printf("\n----------------------------------------------------------\n");
  for(i=0;i<num;i++)
  {
    printf("%d\t",d[i].st);
  }
     printf("%d\t",d[num-1].ct);
  printf("\nAverage Waiting time : %f",(awt/n));
  printf("\nAverage Turnaround Time : %f\n",(att/n));
}
/*
Enter Number of Processes : 5

PROCESS : 1
Name : 1
Arrival Time : 0
Burst Time : 10
PRIORTY : 3

PROCESS : 2
Name : 2
Arrival Time : 0
Burst Time : 1
PRIORTY : 1

PROCESS : 3
Name : 3
Arrival Time : 0
Burst Time : 2
PRIORTY : 4

PROCESS : 4
Name : 4
Arrival Time : 0
Burst Time : 1
PRIORTY : 5

PROCESS : 5
Name : 5
Arrival Time : 0
Burst Time : 5
PRIORTY : 2

P       AT      BT      PR      CT      TT      WT
 1      0       10      3       16      16      6
 2      0       1       1       1       1       0
 3      0       2       4       18      18      16
 4      0       1       5       19      19      18
 5      0       5       2       6       6       1

GANTT CHART
----------------------------------------------------------
| 2     | 5     | 1     | 3     | 4      |
----------------------------------------------------------
0       1       6       16      18      19
Average Waiting time : 8.200000
Average Turnaround Time : 12.000000
*/