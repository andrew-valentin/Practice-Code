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
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = val;
	node->next = NULL;
	
	return node;
}

QueueLL *createQueueLL()
{
	QueueLL *q = (QueueLL *)malloc(sizeof(QueueLL));
	q->tail = NULL;
	q->size = 0;
	q->capacity = CAP;
	
	return q;
}

QueueArr *createQueueArr()
{
	QueueArr *q = (QueueArr *)malloc(sizeof(QueueArr));
	q->arr = (int *)malloc(CAP * sizeof(int));
	q->size = 0;
	q->capacity = CAP;
	
	return q;
}

// Returns 1 if the queue is empty; otherwise, return 0
int isEmptyLL(QueueLL *q)
{
	return (q == NULL || q->size == 0);
}

int isEmptyArr(QueueArr *q)
{
	return (q == NULL || q->size == 0);
}

// Returns 1 if the queue is full; otherwise, return 0
int isFullLL(QueueLL *q)
{
	return (q != NULL && q->size == q->capacity);
}

int isFullArr(QueueArr *q)
{
	return (q != NULL && q->size == q->capacity);
}

// Returns the element at the front of the queue
int frontLL(QueueLL *q) // Can also be referred to as "peek()"
{
	return (q == NULL || q->size == 0) ? -1 : q->tail->next->value;
}

int frontArr(QueueArr *q)
{
	return (q == NULL || q->size == 0) ? -1 : q->arr[q->front];
}

// Adds an element to the end of the queue
void enqueueLL(QueueLL *q, int val)
{
	Node *node;
	
	if (q == NULL || isFullLL(q))
		return;
	
	node = createNode(val);
	
	if (q->tail == NULL)
	{
		q->tail = node;
		q->tail->next = q->tail;
		
		q->size++;
		
		return;
	}
	
	node->next = q->tail->next;
	q->tail->next = node;
	q->tail = node; // q->tail = q->tail->next;
	
	q->size++;
}

void enqueueArr(QueueArr *q, int val)
{
	if (q == NULL || isFullArr(q))
		return;
	
	q->arr[(q->front + q->size) % q->capacity] = val;
	
	q->size++;
}

// Removes an element from the front of the queue and returns the element
int dequeueLL(QueueLL *q)
{
	int val;
	Node *temp;
	
	if (isEmptyLL(q))
		return -1;
	
	temp = q->tail->next;
	q->tail->next = temp->next;
	
	val = temp->value;
	free(temp);
	temp = NULL;
	
	if (q->size == 1)
		q->tail = NULL;
	
	q->size--;
	
	return val;
}

int dequeueArr(QueueArr *q)
{
	int val;
	
	if (isEmptyArr(q))
		return -1;
	
	val = q->arr[q->front];
	
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	
	return val;
}

void freeLL(Node *head)
{
	Node *temp;
	
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	
	temp = NULL;
}

void *freeQueueLL(QueueLL *q)
{
	Node *head;

	if (q == NULL)
		return NULL;
	
	if (q->tail != NULL)
	{
		head = q->tail->next;
		q->tail->next = NULL;
	
		freeLL(head);
	}
	
	free(q);
	
	return NULL;
}

void *freeQueueArr(QueueArr *q)
{
	if (q == NULL)
		return NULL;

	free(q->arr);
	free(q);
	
	return NULL;
}