#include <pthread.h>
#include <stdio.h>

void* fun(void* arg) {
    printf("Hello World\n");
    return NULL;
}

int main() {
    pthread_t tid[4];  // Correct data type for thread ID is pthread_t, not pthread
    for (int i = 0; i <= 3; i++) {
        int status = pthread_create(&tid[i], NULL, fun, NULL);
        if (status == 0) {
            printf("Thread created\n");
        } else {
            printf("Error occurred\n");
        }
        printf("Thread id is %ld\n", (long)tid[i]);  // Correct format specifier for pthread_t is %ld
    }
    pthread_exit(NULL);  // Wait for all threads to finish before exiting
    return 0;
}