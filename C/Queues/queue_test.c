/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Review-Code/tree/main/Review-Code/Queues
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <stdio.h>
#include <stdlib.h>

#include "queues.h"

#define CAP 5

int main()
{
    int i, front_val, dq_val;

    printf("Linked List implementation:");
    QueueLL *qLL = NULL;

    printQueueLL(qLL);
    // Queue does not exist!

    front_val = frontLL(qLL);

    if (front_val == -1)
        printf("\nThe queue is empty! No front value available!\n");
    else
        printf("\nFront value of the queue: %d\n", front_val);
    // The queue is empty! No front value available!

    if (isEmptyLL(qLL))
        printf("The queue is empty!\n");
    else
        printf("The queue is not empty!\n");
    // The queue is empty!

    if (isFullLL(qLL))
        printf("The queue is full!\n");
    else
        printf("The queue is not full!\n");
    // The queue is not full!

    qLL = createQueueLL();
    printQueueLL(qLL);
    // Queue is empty!

    front_val = frontLL(qLL);

    if (front_val == -1)
        printf("\nThe queue is empty! No front value available!\n");
    else
        printf("\nFront value of the queue: %d\n", front_val);
    // The queue is empty! No front value available!

    if (isEmptyLL(qLL))
        printf("The queue is empty!\n");
    else
        printf("The queue is not empty!\n");
    // The queue is empty!

    if (isFullLL(qLL))
        printf("The queue is full!\n");
    else
        printf("The queue is not full!\n");
    // The queue is not full!

    for (i = 1; i <= CAP; i++)
        enqueueLL(qLL, i);
    printQueueLL(qLL);
    // Size: 5
    // Capacity: 5
    // 1<-2<-3<-4<-5

    front_val = frontLL(qLL);

    if (front_val == -1)
        printf("\nThe queue is empty! No front value available!\n");
    else
        printf("\nFront value of the queue: %d\n", front_val);
    // Front value of the queue: 1

    if (isEmptyLL(qLL))
        printf("The queue is empty!\n");
    else
        printf("The queue is not empty!\n");
    // The queue is not empty!

    if (isFullLL(qLL))
        printf("The queue is full!\n");
    else
        printf("The queue is not full!\n");
    // The queue is full!

    printf("\nValue removed from queue: %d\n", dequeueLL(qLL));
    printf("Value removed from queue: %d\n", dequeueLL(qLL));
    printf("Value removed from queue: %d\n", dequeueLL(qLL));
    printQueueLL(qLL);
    // Value remove from queue: 1
    // Value remove from queue: 2
    // Value remove from queue: 3
    // Size: 2
    // Capacity: 5
    // 4<-5<-empty<-empty<-empty

    front_val = frontLL(qLL);

    if (front_val == -1)
        printf("\nThe queue is empty! No front value available!\n");
    else
        printf("\nFront value of the queue: %d\n", front_val);
    // Front value of the queue: 4

    if (isEmptyLL(qLL))
        printf("The queue is empty!\n");
    else
        printf("The queue is not empty!\n");
    // The queue is not empty!

    if (isFullLL(qLL))
        printf("The queue is full!\n");
    else
        printf("The queue is not full!\n");
    // The queue is not full!

    printf("\n");
    for (i = 0; i < CAP; i++)
    {
        dq_val = dequeueLL(qLL);

        if (dq_val == -1)
            printf("Cannot dequeue. Queue is already empty!\n");
        else
            printf("Value removed from queue: %d\n", dq_val);
    }
    // Value remove from queue: 4
    // Value remove from queue: 5
    // Cannot dequeue. Queue is empty!
    // Cannot dequeue. Queue is empty!
    // Cannot dequeue. Queue is empty!

    qLL = freeQueueLL(qLL);

    printf("\n\n\nArray implementation:");
    QueueArr *qArr = NULL;

    printQueueArr(qArr);
    // Queue does not exist!

    front_val = frontArr(qArr);

    if (front_val == -1)
        printf("\nThe queue is empty! No front value available!\n");
    else
        printf("\nFront value of the queue: %d\n", front_val);
    // The queue is empty! No front value available!

    if (isEmptyArr(qArr))
        printf("The queue is empty!\n");
    else
        printf("The queue is not empty!\n");
    // The queue is empty!

    if (isFullArr(qArr))
        printf("The queue is full!\n");
    else
        printf("The queue is not full!\n");
    // The queue is not full!

    qArr = createQueueArr();
    printQueueArr(qArr);
    // Queue is empty!

    front_val = frontArr(qArr);

    if (front_val == -1)
        printf("\nThe queue is empty! No front value available!\n");
    else
        printf("\nFront value of the queue: %d\n", front_val);
    // The queue is empty! No front value available!

    if (isEmptyArr(qArr))
        printf("The queue is empty!\n");
    else
        printf("The queue is not empty!\n");
    // The queue is empty!

    if (isFullArr(qArr))
        printf("The queue is full!\n");
    else
        printf("The queue is not full!\n");
    // The queue is not full!

    for (i = 1; i <= CAP; i++)
        enqueueArr(qArr, i);
    printQueueArr(qArr);
    // Size: 5
    // Capacity: 5
    // 1<-2<-3<-4<-5

    front_val = frontArr(qArr);

    if (front_val == -1)
        printf("\nThe queue is empty! No front value available!\n");
    else
        printf("\nFront value of the queue: %d\n", front_val);
    // Front value of the queue: 1

    if (isEmptyArr(qArr))
        printf("The queue is empty!\n");
    else
        printf("The queue is not empty!\n");
    // The queue is not empty!

    if (isFullArr(qArr))
        printf("The queue is full!\n");
    else
        printf("The queue is not full!\n");
    // The queue is full!

    printf("\nValue removed from queue: %d\n", dequeueArr(qArr));
    printf("Value removed from queue: %d\n", dequeueArr(qArr));
    printf("Value removed from queue: %d\n", dequeueArr(qArr));
    printQueueArr(qArr);
    // Value remove from queue: 1
    // Value remove from queue: 2
    // Value remove from queue: 3
    // Size: 2
    // Capacity: 5
    // 4<-5<-empty<-empty<-empty

    front_val = frontArr(qArr);

    if (front_val == -1)
        printf("\nThe queue is empty! No front value available!\n");
    else
        printf("\nFront value of the queue: %d\n", front_val);
    // Front value of the queue: 4

    if (isEmptyArr(qArr))
        printf("The queue is empty!\n");
    else
        printf("The queue is not empty!\n");
    // The queue is not empty!

    if (isFullArr(qArr))
        printf("The queue is full!\n");
    else
        printf("The queue is not full!\n");
    // The queue is not full!

    printf("\n");
    for (i = 0; i < CAP; i++)
    {
        dq_val = dequeueArr(qArr);

        if (dq_val == -1)
            printf("Cannot dequeue. Queue is already empty!\n");
        else
            printf("Value removed from queue: %d\n", dq_val);
    }
    // Value remove from queue: 4
    // Value remove from queue: 5
    // Cannot dequeue. Queue is empty!
    // Cannot dequeue. Queue is empty!
    // Cannot dequeue. Queue is empty!

    qArr = freeQueueArr(qArr);

    return 0;
}