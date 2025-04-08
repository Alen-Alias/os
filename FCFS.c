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
  int i,j,n,num,idle=0;
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
  for(i=0;i<n;i++)                       
  {
    for(j=0;j<n-i-1;j++)
    {
      if(p[j].at > p[j+1].at)
      {
        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
      }
    }
  }
  i=0,j=0,num=0;
  while(j<n)           
  {
    if(p[j].at<=i && p[j].status==0)
    {
      if(idle==1)
      {
        d[num].ct=i;
        num++;
        idle = 0;
      }
      strcpy(d[num].name,p[j].name);
      d[num].st = i;
      d[num].ct = i + p[j].bt;
      p[j].wt = d[num].st - p[j].at;
      p[j].tt = p[j].wt + p[j].bt;
      p[j].ct = d[num].ct;
      i = d[num].ct;
      p[j].status = 1;
      j++;
      num++;

    }
    else if(idle == 0)
    {
      strcpy(d[num].name,"Idle");
      d[num].st = i;
      i++;
      idle = 1;
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
Enter Number of Processes : 4

PROCESS : 1
Name : p0
Arrival Time : 1
Burst Time : 2

PROCESS : 2
Name : p1
Arrival Time : 4
Burst Time : 6

PROCESS : 3
Name : p2
Arrival Time : 3
Burst Time : 7

PROCESS : 4
Name : p3
Arrival Time : 2
Burst Time : 8

P       AT      BT      CT      TT      WT
 p0     1       2       3       2       0
 p3     2       8       11      9       1
 p2     3       7       18      15      8
 p1     4       6       24      20      14

GANTT CHART
----------------------------------------------------------
| Idle  | p0    | p3    | p2    | p1     |
----------------------------------------------------------
0       1       3       11      18      24
Average Waiting time : 5.750000
Average Turnaround Time : 11.500000
*/