#include<stdio.h>

void main() {
    int burstTime[20], burstTimeCopy[20] ,turnAroundTime[20], waitingTime[20], process[20], gantChart[20], time[20] = {0};
    int n, timeSlice, count = 0, sliced, sum, k = 1, l = 0;
    float averageWaitingTime = 0, averageTurnAroundTime = 0;
    printf("\nEnter the No. of Process: ");
    scanf("%d", &n);
    printf("Enter BurstTime of Each Process: \n");
    for(int i = 0; i < n; i++) {
        process[i] = i+1;
        printf("P%d: ", i+1);
        scanf("%d", &burstTime[i]);
        burstTimeCopy[i] = burstTime[i];
    }
    printf("\nEnter the Time Slice: ");
    scanf("%d", &timeSlice);
    while(count != n) {
        for(int i = 0; i < n; i++ ) {
            if(burstTimeCopy[i] == 0) {
                count++;
                continue;
            }
            if(burstTimeCopy[i] > timeSlice) {
                burstTimeCopy[i] = burstTimeCopy[i] - timeSlice;
                sliced = timeSlice;
            } else if (burstTimeCopy[i] <= timeSlice && burstTimeCopy[i] > 0) {
                sliced = burstTimeCopy[i];
                burstTimeCopy[i] = 0; 
            }
            sum = sum + sliced;
            turnAroundTime[i] = sum;
            gantChart[l++] = process[i];
            time[k] = time[k - 1] + sliced;
            k++;
        }
    }
    for(int i = 0; i < n; i++) {
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
        averageWaitingTime = averageWaitingTime + waitingTime[i];
        averageTurnAroundTime = averageTurnAroundTime + turnAroundTime[i];
    }
    averageTurnAroundTime = averageTurnAroundTime / n;
    averageWaitingTime = averageWaitingTime / n;
    printf("\nProcess\t\t Burst Time\t\t Waiting Time\t\t Turnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\n", process[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
    printf("\nAverage Waiting Time : %.2f ms", averageWaitingTime);
    printf("\nAverage Turnaround Time : %.2f ms\n", averageTurnAroundTime);
    printf("\n\n\t\t\t\tGantt Chart\n\n");
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < l; i++)
        printf("|\tP%d\t|", gantChart[i]);
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < k; i++)
        printf("%d\t \t", time[i]);
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

}