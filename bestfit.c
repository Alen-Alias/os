#include<stdio.h>
#define FREE 0
#define BUSY 1

struct memory
{
    int bno,size,status,fragments;
}block[100];

struct process
{
    int pid,size,blockno;
}P[100];

void main()
{
    int nop,nob,total_fragments = 0,bestblock = 0,bestblockno,temp;
    printf("Enter the number of process: ");
    scanf("%d",&nop);
    printf("Enter the number of blocks: ");
    scanf("%d",&nob);
    printf("Enter the block sizes:\n");
    for(int i=1;i<=nob;i++)
    {
        printf("Block %d size: ",i);
        scanf("%d",&block[i].size);
        block[i].bno = i;
        if(block[i].size > bestblock)
            bestblock = block[i].size;
    }
    printf("Enter the process size:\n");
    for(int i=1;i<=nop;i++)
    {
        printf("Process %d size: ",i);
        scanf("%d",&P[i].size);
        P[i].pid = i;
    }
    temp = bestblock;
    for(int i=1;i<=nop;i++)
    {
        bestblockno = 0;
        bestblock = temp;
        for(int j=1;j<=nob;j++)
        {
            if(block[j].status == FREE)
            {
                if((P[i].size <= block[j].size) && (bestblock > (block[j].size - P[i].size)))
                {
                    bestblockno = j;
                    bestblock = block[j].size - P[i].size;
                    
                }
            }
        }
        if(bestblockno != 0)
        {
            block[bestblockno].status = BUSY;
            block[bestblockno].fragments = block[bestblockno].size - P[i].size;
            P[i].blockno = bestblockno;
        }
    }
    printf("PNo\tPSize\tBno\tBSize\tInt.Fragmentation\n");
    for(int i=1;i<=nop;i++)
    {
        if(P[i].blockno == 0)
            continue;
        printf("P%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].size,P[i].blockno,block[P[i].blockno].size,block[P[i].blockno].fragments);
        total_fragments = total_fragments + block[P[i].blockno].fragments;
    }
    printf("Total Internal Fragmentation = %d",total_fragments);
}
/*   OUTPUT

Enter the number of process: 4
Enter the number of blocks: 6
Enter the block sizes:
Block 1 size: 200
Block 2 size: 400
Block 3 size: 600
Block 4 size: 500
Block 5 size: 300
Block 6 size: 200
Enter the process size:
Process 1 size: 350
Process 2 size: 210
Process 3 size: 550
Process 4 size: 250
PNo	PSize	Bno	BSize	Int.Fragmentation
P1	350	2	400	50
P2	210	5	300	90
P3	550	3	600	50
P4	250	4	500	250
Total Internal Fragmentation = 440

*/