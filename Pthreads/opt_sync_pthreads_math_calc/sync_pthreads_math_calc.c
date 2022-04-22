
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

long sum = 0;
pthread_mutex_t sumlock;

void* handler(){
        long tmp = 0;
        for (int i = 0; i < 10; i++) {
                printf("поток № %ld\n", syscall(SYS_gettid));
                for (long int j = 0; j < 1000000; j++) tmp++;
                printf("\n");
        }
        printf("\n");
        pthread_mutex_lock(&sumlock); // захват мьютекса
        sum+=tmp;
        pthread_mutex_unlock(&sumlock); // освобождение мьютекса

        pthread_exit(0);
}


int main(int argc,char *argv[]){
        int number = atoi(argv[1]);
        pthread_t threads[number];
        pthread_mutex_init(&sumlock,NULL); // инициализация мьютекса


        for(int i = 0;i<number;i++) pthread_create(&threads[i], NULL, handler, NULL);
        for(int j = 0;j<number;j++) pthread_join(threads[j], NULL);
        printf("Sum after %d threads is %ld\n", number, sum);
        pthread_mutex_destroy(&sumlock);
        return 0;
}
