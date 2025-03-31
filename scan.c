//Alen Alias, CSE A 25
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    int disksize=200;
    int tracks[30],n,i,j,seek=0,head,ctrack,temp,index;
    char path[100]="",str[10];
    printf("Enter the number of tracks: ");
    scanf("%d",&n);
    printf("Enter the head position: ");
    scanf("%d",&head);
    printf("Enter the tracks: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&tracks[i]);
    }
    ctrack=head;
    sprintf(str,"%d",ctrack);
    strcat(path,str);
    tracks[n]=disksize-1;
    n+=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(tracks[j]>tracks[j+1])
            {
                temp=tracks[j];
                tracks[j]=tracks[j+1];
                tracks[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(tracks[i]>head)
        {
            index=i;
            break;
        }
    }
    for(i=index;i<n;i++)
    {
        seek+=abs(tracks[i]-ctrack);
        ctrack=tracks[i];
        strcat(path,"->");
        sprintf(str,"%d",ctrack);
        strcat(path,str);  
    }
    for(i=index-1;i>=0;i--)
    {
        seek+=abs(tracks[i]-ctrack);
        ctrack=tracks[i];
        strcat(path,"->");
        sprintf(str,"%d",ctrack);
        strcat(path,str);  
    }
    printf("Total Seek Time: %d\n",seek);
    printf("Path: %s\n",path);

}
/*
Enter the number of tracks: 8
Enter the head position: 53
Enter the tracks: 98 183 37 122 14 124 65 67
Total Seek Time: 331
Path: 53->65->67->98->122->124->183->199->37->14
*/