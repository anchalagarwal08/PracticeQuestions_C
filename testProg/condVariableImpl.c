#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t init = PTHREAD_COND_INITIALIZER;
int initialized = 0;

void func1(){
	pthread_mutex_lock(&lock);
	printf("In func1\n");
	initialized = 1;
	pthread_cond_signal(&init);
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}
void func2(){
        pthread_mutex_lock(&lock);
	while(initialized!=1){
		pthread_cond_wait(&init, &lock);
	}
        printf("In func2\n");
        initialized = 2;
        pthread_cond_signal(&init);
        pthread_mutex_unlock(&lock);
	 pthread_exit(NULL);
}
void func3(){
        pthread_mutex_lock(&lock);
	while(initialized!=2){
                pthread_cond_wait(&init, &lock);
        }
        printf("In func3\n");
       // initialized = 0;
        pthread_mutex_unlock(&lock);
	 pthread_exit(NULL);
}
int main()
{
        pthread_t thread1, thread2, thread3;
        int iret1, iret2, iret3, retjoin3, retjoin1, retjoin2;
        iret1 = pthread_create(&thread1, NULL, (void*) &func1, NULL);
        iret2 = pthread_create(&thread2, NULL, (void *) &func2, NULL);
	iret3 = pthread_create(&thread3, NULL, (void *) &func3, NULL);
//wait till threads finish before main continues        
        retjoin1 = pthread_join(thread1, NULL);
        retjoin2 = pthread_join(thread2, NULL);
	retjoin3 = pthread_join(thread3, NULL);
        pthread_mutex_destroy(&lock);
	exit(0);
}

