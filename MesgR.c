#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.g>
struct mesg_buffer{
    long mesg_type;
    char mesg_text;
}message;

void main()
{
    key_t key=ftok("shmfile",69);
    int msgid=msgget(key,0666|IPC_CREAT);
    msgrcv(msgid,&message,sizeof(message),1,0);
    printf("\n%s",message.mesg_text);
    msgctl(msgid,IPC_RMID,NULL);
    
}