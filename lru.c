//Alen Alias, CSE A 25
#include<stdio.h>
void lru(int pages[],int n,int nof)
{
    int page_faults=0,page_hits=0,i,j,k,flag=0;
    int frame[nof],time[nof];
    for(i=0;i<nof;i++)
    {
        frame[i]=-1;
        time[i]=0;
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<nof;j++)
        {
            if(frame[j]==pages[i])
            {
                flag=1;
                page_hits++;
                time[j]=i;
                break;
            }
        }
        if(flag==0)
        {
            page_faults++;
            for(j=0;j<nof;j++)
            {
                if(frame[j]==-1)
                {
                    frame[j]=pages[i];
                    time[j]=i;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                k=0;
                for(j=1;j<nof;j++)
                {
                    if(time[j]<time[k])
                    {
                        k=j;
                    }
                }
                frame[k]=pages[i];
                time[k]=i;
            }
        }
        printf("Frame: ");
        for(j=0;j<nof;j++)
        {
            printf("%d ",frame[j]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n",page_faults);
    printf("Total Page Hits: %d\n",page_hits);
}
void main()
{
    int pages[30],n,nof,i;
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    printf("Enter the number of frames: ");
    scanf("%d",&nof);
    printf("Enter the pages: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    lru(pages,n,nof);
}
/*
Enter the number of pages: 12
Enter the number of frames: 3
Enter the pages: 1 2 3 1 4 5 2 1 6 2 4 3 7
Frame: 1 -1 -1 
Frame: 1 2 -1
Frame: 1 2 3
Frame: 1 2 3
Frame: 1 4 3
Frame: 1 4 5
Frame: 2 4 5
Frame: 2 1 5
Frame: 2 1 6 
Frame: 2 1 6
Frame: 2 4 6
Frame: 2 4 3
Total Page Faults: 10
Total Page Hits: 2
*/