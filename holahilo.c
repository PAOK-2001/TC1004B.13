#define NUM_THREADS 15000
#include <stdio.h>
#include <unistd.h>
#include<pthread.h>
 int saldo;

void *printHola(void *args){
    char *p =(char *)args;
    printf("Hola hilo %s \n",p);
    pthread_exit(NULL);

}
pthread_mutex_t lockSaldo = PTHREAD_MUTEX_INITIALIZER;
void* suma100(void *args){
    int lsaldo;
    pthread_mutex_lock(&lockSaldo);
    lsaldo =saldo;
    lsaldo+=100;
    saldo=lsaldo;
    pthread_mutex_unlock(&lockSaldo);
    pthread_exit(NULL);
}


int main(){
    pthread_t threads[NUM_THREADS];
    char* s="Soy un Hilo";
    saldo = 0;
    for(int i=0; i<NUM_THREADS; i++){
        pthread_create(&threads[i], NULL,suma100,NULL);
    }
    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("Saldo final  %d \n", saldo);
    pthread_exit(NULL);
}