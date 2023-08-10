#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define max 10
struct mesg_buffer{
    long mesg_type;
    char mesg_text[100];
}message;
void main()
{
    key_t key=ftok("shmfle",65);
    int msgid=msgget(key,0666|IPC_CREAT);
    message.mesg_type=1;
    printf("Write data: \n");
    fgets(message.mesg_text,MAX,stdin);
    msgsnd(msgid,&message,sizeof(message),0);
}