/*ALEN ALIAS, CSE A,25*/
#include<stdio.h>
#include<string.h>
struct process
{
  char name[20];
  int at,tt,bt,wt,ct,status;
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
        else if(found!=0 && p[min].bt>=p[j].bt)
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
  printf("\nP\tAT\tBT\tCT\tTT\tWT\n");
  for(int i=0;i<n;i++)
  {
    printf(" %s\t%d\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
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
Name : p1
Arrival Time : 1
Burst Time : 7

PROCESS : 2
Name : p2
Arrival Time : 3
Burst Time : 3

PROCESS : 3
Name : p3
Arrival Time : 6
Burst Time : 2

PROCESS : 4
Name : p4
Arrival Time : 7
Burst Time : 10

PROCESS : 5
Name : p5
Arrival Time : 9
Burst Time : 8

P       AT      BT      CT      TT      WT
 p1     1       7       8       7       0
 p2     3       3       13      10      7
 p3     6       2       10      4       2
 p4     7       10      31      24      14
 p5     9       8       21      12      4

GANTT CHART
----------------------------------------------------------
| Idle  | p1    | p3    | p2    | p5    | p4     |
----------------------------------------------------------
0       1       8       10      13      21      31
Average Waiting time : 5.400000
Average Turnaround Time : 11.400000
*/