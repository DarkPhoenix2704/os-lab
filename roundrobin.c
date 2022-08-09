#include<stdio.h> 
void main() { 
int i, sum, gt[20], qt, n, bt[20], tt[20], wt[20], bt_cp[20], p[20], temp, count = 0, l = 0, k = 1, time[20] = {0}; 
float wt_avg = 0, tt_avg = 0; 
printf("\nEnter the number of Processes: "); 
scanf("%d", & n); 
printf("Enter the Burst Time of Each Process:\n"); 
for (int j = 0; j < n; j++) { 
p[j] = j + 1; 
printf("P%d: ", j + 1); 
scanf("%d", & bt[j]); 
bt_cp[j] = bt[j]; 
} 
printf("\nEnter the Time Slice : "); 
scanf("%d", & qt); 
while (count != n) { 
for (i = 0, count = 0; i < n; i++) { 
if (bt_cp[i] == 0) { 
count++; 
continue; 
} 
if (bt_cp[i] > qt) { 
bt_cp[i] -= qt; 
temp = qt; 
} else 
if (bt_cp[i] <= qt && bt_cp[i] > 0) { 
temp = bt_cp[i]; 
bt_cp[i] = 0; 
} 
sum += temp; 
tt[i] = sum; 
gt[l++] = p[i]; 
time[k] = time[k - 1] + temp; 
k++; 
} 
} 
for (i = 0; i < n; i++) { 
wt[i] = tt[i] - bt[i]; 
wt_avg += wt[i]; 
tt_avg += tt[i]; 
} 
wt_avg /= n; 
tt_avg /= n; 
printf("\nProcess\t\t Burst Time\t\t Waiting Time\t\t Turnaround Time\n"); 
for (i = 0; i < n; i++) 
printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i], bt[i], wt[i], tt[i]); 
printf("\nAverage Waiting Time : %.2f ms", wt_avg); 
printf("\nAverage Turnaround Time : %.2f ms\n", tt_avg); 
printf("\n\n\t\t\t\tGantt Chart\n\n"); 
printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n"); 
for (i = 0; i < l; i++) 
printf("|\tP%d\t|", gt[i]); 
printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n"); 
for (i = 0; i < k; i++) 
printf("%d\t \t", time[i]); 
printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n"); 
}