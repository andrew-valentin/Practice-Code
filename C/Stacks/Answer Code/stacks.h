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

typedef struct StackLinkedList
{
	Node *head;
	int size; // Number of elements currently in the stack
	int capacity; // Max number of elements the stack can hold
} StackLL;

typedef struct StackArrayList
{
	int *arr;
	int size;
	int capacity;
} StackArr;

void printStackLL(StackLL *s)
{	
	int i;
	Node *temp;

	if (s == NULL)
	{
		printf("Stack does not exist!\n");
		return;
	}
	if (s->size == 0)
	{
		printf("Stack is empty!\n");
		return;
	}

	temp = s->head;
	
	printf("\nSize: %d\n", s->size);
	printf("Capacity: %d\n\n", s->capacity);
	
	for (i = 0; i < s->capacity - s->size; i++)
		printf("*empty*\n");
	int count = 0;
	while (temp != NULL)
	{
		if (count++ == 10) return;
		printf("%d%s", temp->value, (temp->next == NULL) ? "\n\n" : "\n");
		temp = temp->next;
	}
}

void printStackArr(StackArr *s)
{
	int i;

	if (s == NULL)
	{
		printf("Stack does not exist!\n");
		return;
	}
	if (s->size == 0)
	{
		printf("Stack is empty!\n");
		return;
	}
	
	printf("\nSize: %d\n", s->size);
	printf("Capacity: %d\n\n", s->capacity);
	
	for (i = 0; i < s->capacity - s->size; i++)
		printf("*empty*\n");
	
	i = s->size;
	
	while (i-- != 0)
		printf("%d\n", s->arr[i]);
	
	printf("\n");
}

// Dynamically create a node and return the address
Node *createNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = val;
	node->next = NULL;
	
	return node;
}

// Dynamically creates a stack and returns the address
StackLL *createStackLL()
{
	StackLL *s = (StackLL *)malloc(sizeof(StackLL));
	s->head = NULL;
	s->size = 0;
	s->capacity = CAP;
	
	return s;
}

// Dynamically creates a stack and returns the address
StackArr *createStackArr()
{
	StackArr *s = (StackArr *)malloc(sizeof(StackArr));
	s->arr = (int *)malloc(CAP * sizeof(int));
	s->size = 0;
	s->capacity = CAP;
	
	return s;
}

// Returns 1 if the stack is empty; otherwise, return 0
int isEmptyLL(StackLL *s)
{	
	return (s == NULL || s->size == 0);
}

// Returns 1 if the stack is empty; otherwise, return 0
int isEmptyArr(StackArr *s)
{
	return (s == NULL || s->size == 0);
}

// Returns 1 if the stack is full; otherwise, return 0
int isFullLL(StackLL *s)
{
	return (s != NULL && s->size == s->capacity);
}

// Returns 1 if the stack is full; otherwise, return 0
int isFullArr(StackArr *s)
{
	return (s != NULL && s->size == s->capacity);
}

// Returns the element at the top of the stack
int topLL(StackLL *s) // Can also be referred to as "peek()"
{
	return (s == NULL || s->size == 0) ? -1 : s->head->value;
}

// Returns the element at the top of the stack
int topArr(StackArr *s) // Can also be referred to as "peek()"
{
	return (s == NULL || s->size == 0) ? -1 : s->arr[s->size - 1];
}

// Adds an element to the top of the stack
void pushLL(StackLL *s, int val)
{
	Node *node;
	
	if (s == NULL || isFullLL(s))
		return;
	
	node = createNode(val);
	node->next = s->head;
	s->head = node;

	s->size++;
}

// Adds an element to the top of the stack
void pushArr(StackArr *s, int val)
{
	if (isFullArr(s))
		return;
		
	s->arr[s->size++] = val;
}

// Removes an element from the top of the stack and returns the element
int popLL(StackLL *s)
{
	int val;
	Node *temp;
	
	if (isEmptyLL(s))
		return -1;
	
	val = topLL(s);
	
	temp = s->head;
	s->head = temp->next; // s->head = s->head->next;
	
	free(temp);
	temp = NULL;
	
	s->size--;
	
	return val;
}

// Removes an element from the top of the stack and returns the element
int popArr(StackArr *s)
{
	int val;
	
	if (isEmptyArr(s))
		return -1;
	
	val = topArr(s);
	
	s->size--;
	
	return val;
}

// Frees the memory of an entire LL
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

// Frees the memory of an entire stack
void *freeStackLL(StackLL *s)
{
	if (s == NULL)
		return NULL;
		
	freeLL(s->head);
	free(s);
	
	return NULL;
}

// Frees the memory of an entire stack
void *freeStackArr(StackArr *s)
{
	if (s == NULL)
		return NULL;
		
	free(s->arr);
	free(s);
	
	return NULL;
}