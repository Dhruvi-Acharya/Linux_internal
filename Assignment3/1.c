#include<unistd.h>
#include<pthread.h>
#include<stdio.h>

pthread_t tid1;
pthread_t tid2;

void *threadFun(void *arg)
{
  printf("Newly created thread is executing\n");
  sleep(4);
  printf("Exit from Thread\n");
}


int main()
{
  pthread_create(&tid1, NULL,threadFun,NULL); //thread1
  pthread_create(&tid2, NULL,threadFun,NULL); //thread2
  printf("Main Function\n");
  sleep(1);
  printf("Main task exit\n");
  pthread_exit(NULL);

  return 0;
}