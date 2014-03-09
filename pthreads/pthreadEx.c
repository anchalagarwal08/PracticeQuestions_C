#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void do_something(void *ptr);
int main()
{
	pthread_t thread1, thread2;
	char *msg = "I am thread1";
	char *msg2 = "I am thread2";
	int iret1, iret2, retjoin1, retjoin2;
	iret1 = pthread_create(&thread1, NULL, (void*) &do_something, (void*)msg);
	iret2 = pthread_create(&thread2, NULL, (void *) &do_something, (void*)msg2);

//wait till threads finish before main continues	
	retjoin1 = pthread_join(thread1, NULL);
	retjoin2 = pthread_join(thread2, NULL);
	
	printf("Thread1 returns: %d\n", iret1);
	printf("Thread2 returns: %d\n", iret2);
	printf("JoinThread1 returns: %d\n", retjoin1);
	printf("JoinThread2 returns: %d\n", retjoin2);
	exit(0);
}

void do_something(void* ptr)
{
	char *m;
	m = (char*)ptr;
	printf("%s \n",m);
	
}
