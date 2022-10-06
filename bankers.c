#include <stdio.h>

int main() {
    int max[10][10], need[10][10], alloc[10][10],avai[10],completed[10], safeSequence[10];
    int p,r, count = 0, process;
    printf("Enter the number of Process: ");
    scanf("%d", &p); 
    for(int i = 0; i < p; i++ )
        completed[i] = 0;
    printf("Enter the number of Resources: ");
    scanf("%d", &r);
    printf("Enter the max Matrix of each Process:\n");
    for (int i = 0; i < p; i++)
    {
        printf("For Process %d : ", i+1);
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i][j]);     
    }
    printf("Enter the Allocation Matrix of each Process:\n");
    for (int i = 0; i < p; i++)
    {
        printf("For Process %d : ", i+1);
        for (int j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);     
    }
    printf("Enter available resources: ");
    for (int i = 0; i < r; i++)
        scanf("%d", &avai[i]);
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    do
    {
        printf("Need Matrix:\tAllocation Matrix:\n");
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < r; j++)
                printf("%d ", need[i][j]);
            printf("\t\t\t");
            for(int j = 0; j < r; j++)
                printf("%d", alloc[i][j]);
            printf("\n");
        }
        process = -1;
        for(int i = 0; i < p; i++) {
            if (completed[i] == 0)
            {
               process = i;
               for (int j = 0; j < r; j++) {
                if (avai[j] < need[i][j]) 
                {
                    process = -1;
                    break;
                }   
               }
            }
            if (process != -1)
                break;
        }
        if (process != -1)
        {
            printf("\nProcess %d runs to Completion!", process+1);
            safeSequence[count] = process+1;
            count++;
            for(int j = 0; j < r; j++) {
                avai[j] = avai[j] + alloc[process][j];
                alloc[process][j] = 0;
                need[process][j] = 0;
                completed[process] = 1;
            }
            printf("\nNow Available: ");
            for (int i = 0; i < r; i++)
                printf("%d", avai[i]);
            printf("\n");
        }
    } while (count != p && process != -1 );
    if (count == p)
    {
        printf("\nThe System is in Safe State!!\n");
        printf("Safe Sequence is :<");
        for(int i = 0; i < p; i++){
            printf("%d,", safeSequence[i]);
        }
    } else {
        printf("\nThe System is in Unsafe State");
    }   
}