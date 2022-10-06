#include<stdio.h>
#include<string.h>

void getData();
void fcfs();
void calculate();
void display();

int arrivalTime[10], burstTime[10], waitingTime[10], exitTime[10], turnAroundTime[10];
int n, temp, totalWaitingTime, totalTurnAroundTime;
float averageWaitingTime, averageTurnAroundTime;
char pName[20][20], temp1[20];
void main() {
    getData();
    fcfs();
    calculate();
    display();
}

void getData() {
    printf("\nEnter the number of Process: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("\nEnter the Procees Name: ");
        scanf("%s", &pName[i]);
        printf("Enter the Arrival Time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Enter the Burst Time: ");
        scanf("%d", &burstTime[i]);
    }
}

void fcfs() {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if (arrivalTime[i] > arrivalTime[j]) {
                temp = arrivalTime[j];
                arrivalTime[j] = arrivalTime[i];
                arrivalTime[i] = temp;
                temp = burstTime[j];
                burstTime[j] = burstTime[i];
                burstTime[i] = temp;
                strcpy(temp1, pName[j]);
                strcpy(pName[j], pName[i]);
                strcpy(pName[i], temp1);
            }
        }
    }
}
void calculate() {
    waitingTime[0] = 0;
    turnAroundTime[0] = burstTime[0] + waitingTime[0];
    exitTime[0] = burstTime[0] + arrivalTime[0];
    totalTurnAroundTime = turnAroundTime[0];
    totalWaitingTime = waitingTime[0];
    for(int i = 1; i <= n; i++) {
        waitingTime[i] = exitTime[i-1] - arrivalTime[i];
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
        exitTime[i] = exitTime[i-1] +  burstTime[i];
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
        totalWaitingTime = totalWaitingTime + waitingTime[i];
    }
    averageTurnAroundTime = (float) totalTurnAroundTime / n;
    averageWaitingTime = (float) totalWaitingTime / n;
}

void display() {
    printf("\n\nGantt Chart\n");
    printf("\n__________________________________\n");
    for(int i = 0; i <= n; i++)
        printf("\t%s\t", pName[i]);
    printf("\n__________________________________\n");
    for(int i = 0; i <= n; i++)
        printf("\t%d\t", exitTime[i]);
    printf("\nAvarage TAT=%f", averageTurnAroundTime);
    printf("\nAverage WT =%f", averageWaitingTime);
}