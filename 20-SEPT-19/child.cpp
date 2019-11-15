#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <random>
#include <unistd.h>
using namespace std;
int balance = 10000;
sem_t sy;
void* deposits(void* arg){
        sem_wait(&sy);
        balance = balance + 100;
        cout << "Current Balance after deposit: " << balance << endl;
        sem_post(&sy);
}

void* withdraws(void* arg){
        sem_wait(&sy);
        balance = balance - 100;
        cout << "Current Balance after withdraw: " << balance << endl;
        sem_post(&sy);
}

int main(){
        pthread_t deposit, withdraw;
        while(1){
                sleep(2);
                sem_init(&sy,0,1);
                pthread_create(&deposit,NULL,deposits,NULL);
                pthread_create(&withdraw,NULL,withdraws,NULL);
        }
        pthread_join(deposit,NULL);
        pthread_join(withdraw,NULL);
        pthread_exit(NULL);
}