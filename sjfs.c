#include<stdio.h>
#include<string.h>

void getData();
void calculate();
void display();
void sjfs();
int bt[20], wt[20], et[20], twt = 0, temp1, temp2, n, ttt = 0, tt[20];
char pName[20][20], temp[20];
float awt, att;
void main() {
    getData();
    sjfs();
    calculate();
    display();
}
void getData() {
    printf("Enter the no of process :");
    scanf("%d", & n);
    for (int i = 1; i <= n; i++) {
        printf("\nEnter the Process Name: ");
        scanf("%s", & pName[i]);
        printf("Enter the Burst Time: ");
        scanf("%d", & bt[i]);
    }
}
void sjfs() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (bt[i] > bt[j]) {
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
    et[1] = bt[1];
    ttt = tt[1];
    twt = wt[1];
    for (int i = 2; i <= n; i++) {
        wt[i] = et[i - 1];
        tt[i] = wt[i] + bt[i];
        et[i] = et[i - 1] + bt[i];
        twt = twt + wt[i];
        ttt = ttt + tt[i];
    }
    awt = (float) twt / n;
    att = (float) ttt / n;
    printf("\nAverage Turn around time=%3.2f ms", att);
    printf("\nAverage Waiting Time=%3.2f ms", awt);
}
void display() {
    printf("\n\n\t\tGANTT CHART\n");
    for (int i = 1; i <= n; i++) printf("|\t%s\t", pName[i]);
    printf("|\t\n");
    printf("\n------------------------------------------------------------\n");
    printf("\n");
    for (int i = 0; i <= n; i++) {
        printf("%d\t\t", et[i]);
    }
}