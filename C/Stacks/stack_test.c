/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <stdio.h>
#include <stdlib.h>

#include "stacks.h"

int main()
{
    int i, top_val, pop_val;

    printf("Linked List implementation:\n");
    StackLL *sLL = NULL;

    printStackLL(sLL);
    // Stack does not exist!

    top_val = topLL(sLL);

    if (top_val == -1)
        printf("\nThe stack is empty! No top value available!\n");
    else
        printf("\nTop value of the stack: %d\n", top_val);
    // The stack is empty! No top value available!

    if (isEmptyLL(sLL))
        printf("The stack is empty!\n");
    else
        printf("The stack is not empty!\n");
    // The stack is empty!

    if (isFullLL(sLL))
        printf("The stack is full!\n");
    else
        printf("The stack is not full!\n");
    // The stack is not full!

    sLL = createStackLL();
    printStackLL(sLL);
    // Stack is empty!

    top_val = topLL(sLL);

    if (top_val == -1)
        printf("\nThe stack is empty! No top value available!\n");
    else
        printf("\nTop value of the stack: %d\n", top_val);
    // The stack is empty! No top value available!

    if (isEmptyLL(sLL))
        printf("The stack is empty!\n");
    else
        printf("The stack is not empty!\n");
    // The stack is empty!

    if (isFullLL(sLL))
        printf("The stack is full!\n");
    else
        printf("The stack is not full!\n");
    // The stack is not full!
    
    for (i = 1; i <= CAP; i++)
        pushLL(sLL, i);
    printStackLL(sLL);
    // Size: 5
    // Capacity: 5
    // 5->4->3->2->1
    
    top_val = topLL(sLL);

    if (top_val == -1)
        printf("\nThe stack is empty! No top value available!\n");
    else
        printf("\nTop value of the stack: %d\n", top_val);
    // Top value of the stack: 5

    if (isEmptyLL(sLL))
        printf("The stack is empty!\n");
    else
        printf("The stack is not empty!\n");
    // The stack is not empty!

    if (isFullLL(sLL))
        printf("The stack is full!\n");
    else
        printf("The stack is not full!\n");
    // The stack is full!

    printf("\nValue removed from stack: %d\n", popLL(sLL));
    printf("Value removed from stack: %d\n", popLL(sLL));
    printf("Value removed from stack: %d\n", popLL(sLL));
    printStackLL(sLL);
    // Value remove from stack: 5
    // Value remove from stack: 4
    // Value remove from stack: 3
    // Size: 2
    // Capacity: 5
    // empty->empty->empty->2->1
    
    top_val = topLL(sLL);

    if (top_val == -1)
        printf("\nThe stack is empty! No top value available!\n");
    else
        printf("\nTop value of the stack: %d\n", top_val);
    // Top value of the stack: 2

    if (isEmptyLL(sLL))
        printf("The stack is empty!\n");
    else
        printf("The stack is not empty!\n");
    // The stack is not empty!

    if (isFullLL(sLL))
        printf("The stack is full!\n");
    else
        printf("The stack is not full!\n");
    // The stack is not full!
    
    printf("\n");
    for (i = 0; i < CAP; i++)
    {
        pop_val = popLL(sLL);

        if (pop_val == -1)
            printf("Cannot pop. Stack is empty!\n");
        else
            printf("Value removed from stack: %d\n", pop_val);
    }
    // Value remove from stack: 2
    // Value remove from stack: 1
    // Cannot pop. Stack is empty!
    // Cannot pop. Stack is empty!
    // Cannot pop. Stack is empty!

    sLL = freeStackLL(sLL);
    
    printf("\n\n\nArray implementation:\n");
    StackArr *sArr = NULL;

    printStackArr(sArr);
    // Stack does not exist!

    top_val = topArr(sArr);

    if (top_val == -1)
        printf("\nThe stack is empty! No top value available!\n");
    else
        printf("\nTop value of the stack: %d\n", top_val);
    // The stack is empty! No top value available!

    if (isEmptyArr(sArr))
        printf("The stack is empty!\n");
    else
        printf("The stack is not empty!\n");
    // The stack is empty!

    if (isFullArr(sArr))
        printf("The stack is full!\n");
    else
        printf("The stack is not full!\n");
    // The stack is not full!

    sArr = createStackArr();
    printStackArr(sArr);
    // Stack is empty!

    top_val = topArr(sArr);

    if (top_val == -1)
        printf("\nThe stack is empty! No top value available!\n");
    else
        printf("\nTop value of the stack: %d\n", top_val);
    // The stack is empty! No top value available!

    if (isEmptyArr(sArr))
        printf("The stack is empty!\n");
    else
        printf("The stack is not empty!\n");
    // The stack is empty!

    if (isFullArr(sArr))
        printf("The stack is full!\n");
    else
        printf("The stack is not full!\n");
    // The stack is not full!
    
    for (i = 1; i <= CAP; i++)
        pushArr(sArr, i);
    printStackArr(sArr);
    // Size: 5
    // Capacity: 5
    // 5->4->3->2->1

    top_val = topArr(sArr);

    if (top_val == -1)
        printf("\nThe stack is empty! No top value available!\n");
    else
        printf("\nTop value of the stack: %d\n", top_val);
    // Top value of the stack: 5

    if (isEmptyArr(sArr))
        printf("The stack is empty!\n");
    else
        printf("The stack is not empty!\n");
    // The stack is not empty!

    if (isFullArr(sArr))
        printf("The stack is full!\n");
    else
        printf("The stack is not full!\n");
    // The stack is full!

    printf("\nValue removed from queue: %d\n", popArr(sArr));
    printf("Value removed from queue: %d\n", popArr(sArr));
    printf("Value removed from queue: %d\n", popArr(sArr));
    printStackArr(sArr);
    // Value remove from stack: 5
    // Value remove from stack: 4
    // Value remove from stack: 3
    // Size: 2
    // Capacity: 5
    // empty->empty->empty->2->1

    top_val = topArr(sArr);

    if (top_val == -1)
        printf("\nThe stack is empty! No top value available!\n");
    else
        printf("\nTop value of the stack: %d\n", top_val);
    // Top value of the stack: 2

    if (isEmptyArr(sArr))
        printf("The stack is empty!\n");
    else
        printf("The stack is not empty!\n");
    // The stack is not empty!

    if (isFullArr(sArr))
        printf("The stack is full!\n");
    else
        printf("The stack is not full!\n");
    // The stack is not full!

    printf("\n");
    for (i = 0; i < CAP; i++)
    {
        pop_val = popArr(sArr);

        if (pop_val == -1)
            printf("Cannot pop. Stack is empty!\n");
        else
            printf("Value removed from stack: %d\n", pop_val);
    }
    // Value remove from stack: 2
    // Value remove from stack: 1
    // Cannot dequeue. Stack is already empty!
    // Cannot dequeue. Stack is already empty!
    // Cannot dequeue. Stack is already empty!

    sArr = freeStackArr(sArr);
    
    return 0;
}