#include "bounded_buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep
#include <stdbool.h> // For true

struct bounded_buffer queue;

void *producer(void *ptr);
void *consumer(void *ptr);

int main() {
    // Initialize bounded buffer
    bounded_buffer_init(&queue, 5); 

    pthread_t producers[3]; // Assuming 3 producers
    for (int i = 0; i < 3; i++) {
        // Correctly pass the address of 'queue'
        pthread_create(&producers[i], NULL, producer, (void*)&queue);
    }

    pthread_t consumers[2]; // Assuming 2 consumers
    for (int i = 0; i < 2; i++) {
        // Correctly pass the address of 'queue'
        pthread_create(&consumers[i], NULL, consumer, (void*)&queue);
    }

    // Wait for all producer threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(producers[i], NULL);
    }

    // Allow consumers some time to process remaining items
    sleep(5); // Sleep for 5 seconds

    bounded_buffer_destroy(&queue); // Clean up the bounded buffer resources

    // Terminate the program (also kills consumer threads)
    exit(0);
}

/* this is the function executed by the producer thread. 
   It should generate a number of messages and push them into the queue */
void *producer(void *ptr){
    // Assuming ptr could be used for something else, like a unique ID for each producer
    // In this simplified version, it's not used.
    for(int i = 0; i < 10; i++) {
        int *message = malloc(sizeof(int));
        *message = i; // Simple payload: just the loop index
        bounded_buffer_push(&queue, message);
    }
    return NULL;
}

/* this is the function executed by the consumer thread. 
   It should pop messages from the queue and print them */
void *consumer(void *ptr){
    while (true) { // You might want a way to exit this loop eventually
        int *message = (int *)bounded_buffer_pop(&queue);
        printf("Consumer %ld: Consumed message %d\n", pthread_self(), *message);
        free(message); // Don't forget to free the memory!
    }
    return NULL;
}
