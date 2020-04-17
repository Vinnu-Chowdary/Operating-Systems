#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int shmid;
	char a[100];
	void*s_memory;
	memset(a,'\0',100);
	shmid=shmget(12355,1024,0777|IPC_CREAT);

	if(shmid!=-1)
	{
	s_memory=shmat(shmid,NULL,0);
	read(0,a,100);
	strcpy(s_memory,a);
	printf("send\n");
	}
}