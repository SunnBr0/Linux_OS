#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

void* handler(){
        for (int i = 0; i < 10; i++) {
                printf("привет, я процесс №%ld\n", syscall(SYS_gettid));
        }
        printf("\n");
        pthread_exit(0);
}


int main(int argc,char *argv[]){
        int pthread = atoi(argv[1]);
        pthread_t id;

        for(int j = 0;j<pthread;j++){
                pthread_create(&id, NULL, handler, NULL);
                pthread_join(id, NULL);
        }
        return 0;
}
