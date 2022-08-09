#include<stdio.h> 
int pages, frames, ref[40], frame[40], k = 0, res = 0, temp, found = 0, least[40], min, pos = 0, least[40], found, 
temp; 
void fifo() { 
printf("\nFIFO PAGE REPLACEMENT"); 
int hit_fifo = 0, fault_fifo = 0; 
for (int i = 0; i < frames; i++) 
frame[i] = -1; 
printf("\nPage Reference\t\tPage Frames\n\n"); 
for (int i = 0; i < pages; i++) { 
res = 0; 
printf("For Page %d -> ", ref[i]); 
for (int j = 0; j < frames; j++) { 
if (frame[j] == ref[i]) { 
hit_fifo++; 
res = 1; 
break; 
} 
} 
if (res == 1) { 
for (int j = 0; j < frames; j++) { 
if (frame[j] != -1) 
printf("\t%d", frame[j]); 
else 
printf("\t"); 
} 
printf("\tHIT "); 
} 
if (res == 0) { 
fault_fifo++; 
frame[k] = ref[i]; 
k = (k + 1) % frames; 
for (int j = 0; j < frames; j++) { 
if (frame[j] != -1) 
printf("\t%d", frame[j]); 
else 
printf("\t"); 
} 
printf("\tFAULT "); 
} 
printf("\n"); 
} 
printf("\n Number of Page Faults -> %d", fault_fifo); 
int hit_ratio = (hit_fifo * 100) / pages; 
int miss_ratio = (fault_fifo * 100) / pages; 
printf("\n Hit Ratio -> %d%%", hit_ratio); 
printf("\n Miss Ratio -> %d%%\n", miss_ratio); 
} 
int isHit(int n) { 
int count = 0; 
for (int j = 0; j < frames; j++) { 
if (frame[j] == n) { 
count = 1; 
break; 
} 
} 
return count; 
} 
void lru() { 
printf("\nLEAST RECENTLY USED (LRU) PAGE REPLACEMENT\n"); 
int fault = 0, hit = 0; 
for (int i = 0; i < frames; i++) frame[i] = -1; 
printf("\nPage Reference\t\tPage Frames\n\n"); 
for (int i = 0; i < pages; i++) { 
printf("\nFor Page %d ->", ref[i]); 
if (isHit(ref[i]) == 0) { 
for (int j = 0; j < frames; j++) { 
temp = frame[j]; 
found = 0; 
for (k = i - 1; k >= 0; k--) { 
if (temp == ref[k]) { 
least[j] = k; 
found = 1; 
break; 
} else 
found = 0; 
} 
if (found == 0) least[j] = -9999; 
} 
int min = 9999; 
int loc; 
for (int j = 0; j < frames; j++) { 
if (least[j] < min) { 
 min = least[j]; 
 loc = j; 
} 
} 
frame[loc] = ref[i]; 
fault++; 
for (int j = 0; j < frames; j++) 
if (frame[j] != -1) 
printf("\t%d", frame[j]); 
else 
printf("\t"); 
printf("\tFAULT "); 
} else { 
hit++; 
for (int j = 0; j < frames; j++) 
if (frame[j] != -1) 
printf("\t%d", frame[j]); 
else 
printf("\t"); 
printf("\tHIT "); 
} 
} 
printf("\n Number of Page Faults -> %d", fault); 
int hit_ratio = (hit * 100) / pages; 
int miss_ratio = (fault * 100) / pages; 
printf("\n Hit Ratio -> %d%%", hit_ratio); 
printf("\n Miss Ratio -> %d%%\n", miss_ratio); 
} 
void main() { 
printf("\n Enter the Size of Page Refrence String : "); 
scanf("%d", & pages); 
printf("\n Enter the Page Reference String : "); 
for (int i = 0; i < pages; i++) 
scanf("%d", & ref[i]); 
printf("\n Enter the Number of Frames : "); 
scanf("%d", & frames); 
fifo(); 
lru(); 
} 
