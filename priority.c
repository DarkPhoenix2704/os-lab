#include<stdio.h>
#include<string.h>

void getData();
void findPriority();
void calculate();
void display();

int burstTime[20], waitingTime[20], turnAroundTime[20], exitTime[20], priority[20];
int n, temp, totalWaitingTime, totalTurnAroundTime;
char pName[20][20], temp1[20];
float averageWaitingTime, averageTurnAroundTime;

void main() {
    getData();
    findPriority();
    calculate();
    display();
}

void getData() {
    printf("Enter the No of Process: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++ ) {
        printf("\nEnter the Process Name: ");
        scanf("%s", &pName[i]);
        printf("Enter the Priority: ");
        scanf("%d", &priority[i]);
        printf("Enter the BurstTime: ");
        scanf("%d", &burstTime[i]);
    }
}

void findPriority() {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1 ; j <= n; j++) {
            if(priority[i] > priority[j]) {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
                strcpy(temp1, pName[i]);
                strcpy(pName[i], pName[j]);
                strcpy(pName[j], temp1);
            }
        }
    }
}

void calculate() {
    waitingTime[0] = 0;
    turnAroundTime[0] = burstTime[0] + waitingTime[0];
    exitTime[0] = burstTime[0];

    totalTurnAroundTime = turnAroundTime[0];
    totalWaitingTime = waitingTime[0];

    for(int i = 1; i <= n; i++) {
        waitingTime[i] = exitTime[i-1];
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
        exitTime[i] = exitTime[i-1] + burstTime[i];

        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
        totalWaitingTime = totalWaitingTime + waitingTime[i];
    }
    averageTurnAroundTime = (float) totalTurnAroundTime / n;
    averageWaitingTime = (float) totalWaitingTime / n;
}

void display() {
    printf("\nGantt Chart");
    printf("\n\n");
    for(int i = 0; i <= n; i++)
        printf("|\t%s\t", pName[i]);
    printf("|\t\n\n\n");
    for (int i = 0; i <= n; i++) {
        printf("%d\t\t", exitTime[i]);
    }
    printf("\nAverage TAT: %f", averageTurnAroundTime);
    printf("\nAverage WT: %f", averageWaitingTime);
}