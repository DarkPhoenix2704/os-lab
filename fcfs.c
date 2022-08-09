#include<stdio.h>
#include<strings.h>

void getData();
void calculate();
void display();
void fcfs();
int bt[20], at[20], wt[20], et[20], twt = 0, temp1, temp2, ttt = 0, tt[20], n;
char pName[20][20], temp[20];
float awt, att;
void main() {
    getData();
    fcfs();
    calculate();
    display();
}
void getData() {
    printf("Enter the No of Process : ");
    scanf("%d", & n);
    for (int i = 1; i <= n; i++) {
        printf("\nEnter the Process Name: ");
        scanf("%s", & pName[i]);
        printf("Enter the Arrival Time: ");
        scanf("%d", & at[i]);
        printf("Enter the Burst Time: ");
        scanf("%d", & bt[i]);
    }
}
void fcfs() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (at[i] > at[j]) {
                temp1 = at[i];
                at[i] = at[j];
                at[j] = temp1;
                temp2 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp2;
                strcpy(temp, pName[i]);
                strcpy(pName[i], pName[j]);
                strcpy(pName[j], temp);
            }
        }
    }
}
void calculate() {
    wt[1] = 0;
    tt[1] = 0;
    tt[1] = bt[1];
    et[1] = bt[1];
    et[1] = bt[1] + at[1];
    ttt = tt[1];
    twt = wt[1];
    for (int i = 2; i <= n; i++) {
        wt[i] = et[i - 1] - at[i];
        tt[i] = wt[i] + bt[i];
        et[i] = et[i - 1] + bt[i];
        twt = twt + wt[i];
        ttt = ttt = tt[i];
    }
    awt = (float) twt / n;
    att = (float) ttt / n;
}
void display() {
    printf("\n\n\t\tGantt Chart\n");
    printf("\n____________________________________\n");
    for (int i = 1; i <= n; i++) {
        printf("\t%s\t", pName[i]);
    }
    printf("\n____________________________________\n");
    for (int i = 1; i <= n; i++) {
        printf("\t\t%d\t", et[i]);
    }
    printf("\n\nAvg=%f", awt);
    printf("\nWt=%f", att);
}