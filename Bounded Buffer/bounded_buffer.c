#include "bounded_buffer.h"
#include <stdio.h>
#include <stdlib.h>

/*Do not use any global variables for implementation*/

void bounded_buffer_init(struct bounded_buffer *buffer, int size){
    buffer->size = size;
    buffer->count = 0;
    buffer->head = 0;
    buffer->tail = 0;
    buffer->items = (void **)malloc(size * sizeof(void *));
    pthread_mutex_init(&buffer->mutex, NULL);
    pthread_cond_init(&buffer->notEmpty, NULL);
    pthread_cond_init(&buffer->notFull, NULL);
}

void bounded_buffer_push(struct bounded_buffer *buffer, void *item){
    
    pthread_mutex_lock(&buffer->mutex);
    while (buffer->count == buffer->size) {
        // Wait for not_full condition
        pthread_cond_wait(&buffer->notFull, &buffer->mutex);
    }
    buffer->items[buffer->tail] = item;
    buffer->tail = (buffer->tail + 1) % buffer->size;
    buffer->count++;
    pthread_cond_signal(&buffer->notEmpty); // Signal that the buffer is not empty
    pthread_mutex_unlock(&buffer->mutex);
}

void* bounded_buffer_pop(struct bounded_buffer *buffer){
    pthread_mutex_lock(&buffer->mutex);
    while (buffer->count == 0) {
        // Wait for not_empty condition
        pthread_cond_wait(&buffer->notEmpty, &buffer->mutex);
    }
    void* item = buffer->items[buffer->head];
    buffer->head = (buffer->head + 1) % buffer->size;
    buffer->count--;
    pthread_cond_signal(&buffer->notFull); // Signal that the buffer is not full
    pthread_mutex_unlock(&buffer->mutex);
    return item;
}

void bounded_buffer_destroy(struct bounded_buffer *buffer){
    free(buffer->items); // Free the buffer storage array
    pthread_mutex_destroy(&buffer->mutex); // Destroy the mutex
    pthread_cond_destroy(&buffer->notEmpty); // Destroy the notEmpty condition variable
    pthread_cond_destroy(&buffer->notFull); // Destroy the notFull condition variable
}



