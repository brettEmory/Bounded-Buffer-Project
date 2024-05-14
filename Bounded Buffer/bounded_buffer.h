#ifndef _BOUNDED_BUFFER_H
#define _BOUNDED_BUFFER_H
#include <pthread.h>

/* do not use any global variables in this file */

struct bounded_buffer{
    void **items;            // Array to hold the pointers to the items.
    int size;                // Maximum number of items in the buffer.
    int count;               // Current number of items in the buffer.
    int head;                // Index of the head of the buffer.
    int tail;                // Index of the tail of the buffer.
    pthread_mutex_t mutex;   // Mutex lock for thread safety.
    pthread_cond_t notEmpty; // Condition variable to signal that the buffer is not empty.
    pthread_cond_t notFull;  // Condition variable to signal that the buffer is not full.
};


/* do not change the following function definitions */

/* Initialize a buffer; size is the max number of items in the buffer*/
void bounded_buffer_init(struct bounded_buffer *buffer, int size);

/** Add item to the tail of the buffer. If the buffer is full, wait
 * till the buffer is not full. This function should be thread-safe. */
void bounded_buffer_push(struct bounded_buffer *buffer, void *item);

/** Remove an item from the head of the buffer. If the buffer is empty,
 * wait till the buffer is not empty. Return the removed item. 
 * This function should be thread-safe. */
void* bounded_buffer_pop(struct bounded_buffer *buffer);

/* Release the buffer */
void bounded_buffer_destroy(struct bounded_buffer *buffer);

#endif
