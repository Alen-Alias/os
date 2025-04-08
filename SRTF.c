// ALEN ALIAS, CSE A, 25
#include <stdio.h>
#include <string.h>

struct process {
    char name[20];
    int at, bt, rt, ct, tt, wt, status;
} p[20];

struct done {
    char name[20];
    int st, ct;
} d[100];

void main() {
    int n, i = 0, j, ls = 0, num = 0;
    float awt = 0, att = 0;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for (j = 0; j < n; j++) {
        printf("\nPROCESS %d\n", j + 1);
        printf("Name: ");
        scanf(" %s", p[j].name);
        printf("Arrival Time: ");
        scanf("%d", &p[j].at);
        printf("Burst Time: ");
        scanf("%d", &p[j].bt);
        p[j].rt = p[j].bt;
        p[j].status = 0;
    }

    int prev = -1;

    while (ls < n) {
        int min = -1;
        int min_rt = 9999;

        for (j = 0; j < n; j++) {
            if (p[j].at <= i && p[j].rt > 0 && p[j].rt < min_rt) {
                min_rt = p[j].rt;
                min = j;
            }
        }

        if (min == -1) {
            if (prev != -2) {
                strcpy(d[num].name, "Idle");
                d[num].st = i;
                prev = -2;
            }
            i++;
            if (prev == -2) {
                d[num].ct = i;
                num++;
            }
        }
        else
        {
        if (prev != min) 
        {
            strcpy(d[num].name, p[min].name);
            d[num].st = i;
            prev = min;
            p[min].rt--;
            i++;
        }
            p[min].rt--;
            i++;
            if (p[min].rt == 0) 
            {
                p[min].ct = i;
                p[min].tt = p[min].ct - p[min].at;
                p[min].wt = p[min].tt - p[min].bt;
                p[min].status = 1;
                ls++;
                d[num].ct = i;
                num++;
                prev = -1;
            }
        }
    }

    printf("\nP\tAT\tBT\tCT\tTT\tWT\n");
    for (j = 0; j < n; j++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[j].name, p[j].at, p[j].bt, p[j].ct, p[j].tt, p[j].wt);
        awt += p[j].wt;
        att += p[j].tt;
    }

    printf("\nGANTT CHART\n");
    printf("----------------------------------------------------------\n");
    for (j = 0; j < num; j++) {
        printf("| %s\t", d[j].name);
    }
    printf("|\n----------------------------------------------------------\n");
    for (j = 0; j < num; j++) {
        printf("%d\t", d[j].st);
    }
    printf("%d\n", d[num - 1].ct);

    printf("\nAverage Waiting Time : %.2f", awt / n);
    printf("\nAverage Turnaround Time : %.2f\n", att / n);
    }