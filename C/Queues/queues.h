/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#define CAP 5

typedef struct Node
{
	int value;
	struct Node *next;
} Node;

typedef struct QueueLinkedList
{
	Node *tail;
	int size; // Number of elements currently in the queue
	int capacity; // Max number of elements the queue can hold
} QueueLL;

typedef struct QueueArrayList
{
	int *arr;
	int front;
	int size;
	int capacity;
} QueueArr;

void printQueueLL(QueueLL *q)
{	
	int i;
	Node *temp;

	if (q == NULL)
	{
		printf("\nQueue does not exist!\n");
		return;
	}
	if (q->size == 0)
	{
		printf("\nQueue is empty!\n");
		return;
	}
	
	temp = q->tail->next;
	
	printf("\nSize: %d\n", q->size);
	printf("Capacity: %d\n\n", q->capacity);
	
	while (temp != q->tail)
	{
		printf("%d%s", temp->value, " <- ");
		temp = temp->next;
	}
	
	printf("%d%c", temp->value, (q->size == q->capacity) ? '\n' : ' ');
	
	for (i = 0; i < q->capacity - q->size; i++)
		printf("<- *empty*%c", (i == q->capacity - q->size - 1) ? '\n' : ' ');
}

void printQueueArr(QueueArr *q)
{
	int i;

	if (q == NULL)
	{
		printf("\nQueue does not exist!\n");
		return;
	}
	if (q->size == 0)
	{
		printf("\nQueue is empty!\n");
		return;
	}

	printf("\nSize: %d\n", q->size);
	printf("Capacity: %d\n\n", q->capacity);

	for (i = q->front; i < (q->front + q->size); i++)
		printf("%s%d", (i == q->front) ? "" : " <- ", q->arr[i % q->capacity]);
	
	for (i = 0; i < q->capacity - q->size; i++)
		printf(" <- *empty*");
	
	printf("\n");
}

Node *createNode(int val)
{
	// your code here
}

QueueLL *createQueueLL()
{
	// your code here
}

QueueArr *createQueueArr()
{
	// your code here
}

// Returns 1 if the queue is empty; otherwise, return 0
int isEmptyLL(QueueLL *q)
{
	// your code here
}

int isEmptyArr(QueueArr *q)
{
	// your code here
}

// Returns 1 if the queue is full; otherwise, return 0
int isFullLL(QueueLL *q)
{
	// your code here
}

int isFullArr(QueueArr *q)
{
	// your code here
}

// Returns the element at the front of the queue
int frontLL(QueueLL *q) // Can also be referred to as "peek()"
{
	// your code here
}

int frontArr(QueueArr *q)
{
	// your code here
}

// Adds an element to the end of the queue
void enqueueLL(QueueLL *q, int val)
{
	// your code here
}

void enqueueArr(QueueArr *q, int val)
{
	// your code here
}

// Removes an element from the front of the queue and returns the element
int dequeueLL(QueueLL *q)
{
	// your code here
}

int dequeueArr(QueueArr *q)
{
	// your code here
}

void freeLL(Node *head)
{
	// your code here
}

void *freeQueueLL(QueueLL *q)
{
	// your code here
}

void *freeQueueArr(QueueArr *q)
{
	// your code here
}