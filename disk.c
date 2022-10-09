#include<stdio.h>

#include<stdlib.h>

int max, head, no, q[30] = {
    0
};
void exit(int status);
void fcfs(int ch) {
    int curr, seek = 0, arr[30];
    for (int i = 0; i < no; i++)
        arr[i] = q[i];
    printf("\n The Order of Head Movement in FCFS : ");
    for (int i = 0; i < no; i++)
        printf("%d -> ", arr[i]);
    for (int i = 0; i < no; i++) {
        curr = arr[i];
        seek += abs(curr - ch);
        ch = curr;
    }
    printf("\n The Total Seek Time -> %d", seek);
}
void sstf(int ch) {
    int count = 0, seek = 0, loc = 0, new_arr[30] = {
        0
    }, k = 0, flag, arr[30];
    for (int i = 0; i < no; i++)
        arr[i] = q[i];
    printf("\n The Order of Head Movement in SSTF : ");
    while (count != no) {
        int min = 1000;
        for (int i = 0; i < no; i++) {
            flag = abs(arr[i] - ch);
            if (min > flag) {
                min = flag;
                loc = i;
            }
        }
        seek += min;
        ch = arr[loc];
        new_arr[k++] = ch;
        arr[loc] = 1000;
        count++;
    }
    for (int i = 0; i < no; i++)
        printf("%d -> ", new_arr[i]);
    printf("\n The Total Seek Time -> %d", seek);
}
void scan(int ch) {
    int i, j, arr[30], temp, new_arr[30], k = 0, seek = 0;
    for (int i = 0; i < no; i++)
        arr[i] = q[i];
    for (i = 1; i < no; i++)
        for (j = 0; j < no - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    for (i = 0; i < no; i++)
        if (arr[i] >= ch)
            break;
    for (j = i; j < no; j++)
        new_arr[k++] = arr[j];
    for (j = i - 1; j >= 0; j--)
        new_arr[k++] = arr[j];
    seek += abs(max - 1 - ch);
    seek += abs(max - 1 - arr[0]);
    printf("\n The Order of Head Movement in SCAN : ");
    for (int i = 0; i < no; i++)
        printf("%d -> ", new_arr[i]);
    printf("\n The Total Seek Time -> %d", seek);
}
void c_scan(int ch) {
    int i, j, arr[30], temp, new_arr[30] = {
        0
    }, k = 0, seek = 0;
    for (int i = 0; i < no; i++)
        arr[i] = q[i];
    for (i = 1; i < no; i++)
        for (j = 0; j < no - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    for (i = 0; i < no; i++)
        if (arr[i] >= ch)
            break;
    for (j = i; j < no; j++)
        new_arr[k++] = arr[j];
    for (j = 0; j < i; j++)
        new_arr[k++] = arr[j];
    seek += abs(max - 1 - ch);
    seek += abs(max - 1 - 0);
    seek += abs(arr[i - 1] - 0);
    printf("\n The Order of Head Movement in C-SCAN : ");
    for (i = 0; i < no; i++)
        printf("%d -> ", new_arr[i]);
    printf("\n The Total Seek Time -> %d", seek);
}
void look(int ch) {
    int i, j, arr[30], temp, new_arr[30], k = 0, seek = 0;
    for (int i = 0; i < no; i++)
        arr[i] = q[i];
    for (i = 1; i < no; i++)
        for (j = 0; j < no - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    for (i = 0; i < no; i++)
        if (arr[i] >= ch)
            break;
    for (j = i; j < no; j++)
        new_arr[k++] = arr[j];
    for (j = i - 1; j >= 0; j--)
        new_arr[k++] = arr[j];
    seek += abs(arr[no - 1] - ch);
    seek += abs(arr[no - 1] - arr[0]);
    printf("\n The Order of Head Movement in LOOK : ");
    for (int i = 0; i < no; i++)
        printf("%d -> ", new_arr[i]);
    printf("\n The Total Seek Time -> %d", seek);
}
void c_look(int ch) {
    int i, j, arr[30], temp, new_arr[30] = {
        0
    }, k = 0, seek = 0;
    for (int i = 0; i < no; i++)
        arr[i] = q[i];
    for (i = 1; i < no; i++)
        for (j = 0; j < no - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    for (i = 0; i < no; i++)
        if (arr[i] >= ch)
            break;
    for (j = i; j < no; j++)
        new_arr[k++] = arr[j];
    for (j = 0; j < i; j++)
        new_arr[k++] = arr[j];
    seek += abs(arr[no - 1] - ch);
    seek += abs(arr[no - 1] - arr[0]);
    seek += abs(arr[0] - new_arr[k - 1]);
    printf("\n The Order of Head Movement in C-LOOK : ");
    for (i = 0; i < no; i++)
        printf("%d -> ", new_arr[i]);
    printf("\n The Total Seek Time -> %d", seek);
}
void main() {
        int choice;
        char ans;
        printf("\nEnter the maximum number of tracks : ");
        scanf("%d", & max);
        printf("\nEnter the number of Disk Queue elements : ");
        scanf("%d", & no);
        printf("\nEnter the Disk Requests : \n");
        for (int i = 0; i < no; i++)
            scanf("%d", & q[i]);
        printf("\nEnter the Disk Head starting position : ");
        scanf("%d", & head);
        do {
            printf("\n\n Disk Scheduling Algorithms Menu : ");
            printf("\n 1. FCFS");
            printf("\n 2. SSTF");
            printf("\n 3. SCAN");
            printf("\n 4. C-SCAN");
            printf("\n 5. LOOK");
            printf("\n 6. C-LOOK");
            printf("\n 7. EXIT");
            printf("\n\tEnter your choice -> ");
            scanf("%d", & choice);
            switch (choice) {
            case 1: {
                fcfs(head);
                break;
            }
            case 2: {
                sstf(head);
                break;
            }
            case 3: {
                scan(head);
                break;
            }
            case 4: {
                c_scan(head);
                break;
            }
            case 5: {
                look(head);
                break;
            }
            case 6: {
                c_look(head);
                break;
            }
            case 7: {
                exit(0);
                break;
            }
            default:
                printf("\n Wrong choice!!");
            }
            printf("\n Do You Want To Continue (Y/N) ? ");
            scanf(" %c", & ans);
        } while (ans == 'Y' || ans == 'y');
}