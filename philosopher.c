#include<stdio.h> 
#include<semaphore.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 
#define N 5 
#define right ph 
#define left (ph % N) + 1 
sem_t chopstick[5]; 
pthread_t T[N]; 
void * philo(void *); 
void think(int); 
void eat(int); 
void main() { 
int var[N]; 
for (int i = 1; i <= N; i++) { 
sem_init(&chopstick[i], 0, 1); 
} 
for (int i = 1; i <= N; i++) { 
var[i] = i; 
pthread_create(&T[i], NULL, (void * ) philo, (void * ) &var[i]); 
} 
for (int i = 1; i <= N; i++) { 
pthread_join(T[i], NULL); 
} 
} 
void * philo(void * n) { 
while (1) { 
int ph = *(int *) n; 
think(ph); 
printf("\nPhilosopher %d is HUNGRY & wants to Eat", ph); 
printf("\nPhilosopher %d tries to pick up left chopstick", ph); 
sem_wait(&chopstick[left]); 
printf("\nPhilosopher %d has successfully picked up the left chopstick -> %d", ph, left); 
printf("\nPhilosopher %d tries to pick the right chopstick", ph); 
sem_wait(&chopstick[right]); 
printf("\nPhilosopher %d has successfully picked up the right chopstick -> %d", ph, right); 
eat(ph); 
printf("\nPhilosopher %d has finished EATING", ph); 
sem_post(&chopstick[left]); 
printf("\nPhilosopher %d puts down the left chopstick -> %d", ph, left); 
sem_post(&chopstick[right]); 
printf("\nPhilosopher %d puts down the right chopstick -> %d ", ph, right); 
} 
} 
void eat(int ph) { 
printf("\n\tPhilosopher %d begins to EAT using Chopsticks : %d (LEFT) & %d (RIGHT)", ph, left, right); 
sleep(1); 
} 
void think(int ph) { 
printf("\nPhilosopher %d is THINKING", ph); 
sleep(1); 
} 
