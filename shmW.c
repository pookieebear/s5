#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
void main()
{
    key_t key = ftok("shmfile",65);
    int shmid=shmget(key,1024,0666|IPC_CREAT);
    char *str=(char*)shmat(shmid,(void*)0,0);
    printf("\nWrite data : \n");
    gets(str);
    printf("\n Data written in memory");
    shmdt(str);
}