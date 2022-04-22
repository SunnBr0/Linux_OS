#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

long sum = 0;

void* handler(){
        for (long i = 0; i < 1000000; i++) {
                sum++;
        }
        pthread_exit(0);
}


int main(int argc,char *argv[]){
        int number = atoi(argv[1]);
        pthread_t threads[number];

        for(int i = 0;i<number;i++){
                pthread_create(&threads[i], NULL, handler, NULL);
        }
        for(int j = 0;j<number;j++) pthread_join(threads[j], NULL);
        printf("Sum after %d threads is %ld\n", number, sum);
        return 0;
}
