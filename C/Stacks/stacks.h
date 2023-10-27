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
	// your code here
}

// Dynamically creates a stack and returns the address
StackLL *createStackLL()
{
	// your code here
}

// Dynamically creates a stack and returns the address
StackArr *createStackArr()
{
	// your code here
}

// Returns 1 if the stack is empty; otherwise, return 0
int isEmptyLL(StackLL *s)
{	
	// your code here
}

// Returns 1 if the stack is empty; otherwise, return 0
int isEmptyArr(StackArr *s)
{
	// your code here
}

// Returns 1 if the stack is full; otherwise, return 0
int isFullLL(StackLL *s)
{
	// your code here
}

// Returns 1 if the stack is full; otherwise, return 0
int isFullArr(StackArr *s)
{
	// your code here
}

// Returns the element at the top of the stack
int topLL(StackLL *s) // Can also be referred to as "peek()"
{
	// your code here
}

// Returns the element at the top of the stack
int topArr(StackArr *s) // Can also be referred to as "peek()"
{
	// your code here
}

// Adds an element to the top of the stack
void pushLL(StackLL *s, int val)
{
	// your code here
}

// Adds an element to the top of the stack
void pushArr(StackArr *s, int val)
{
	// your code here
}

// Removes an element from the top of the stack and returns the element
int popLL(StackLL *s)
{
	// your code here
}

// Removes an element from the top of the stack and returns the element
int popArr(StackArr *s)
{
	// your code here
}

// Frees the memory of an entire LL
void freeLL(Node *head)
{
	// your code here
}

// Frees the memory of an entire stack
void *freeStackLL(StackLL *s)
{
	// your code here
}

// Frees the memory of an entire stack
void *freeStackArr(StackArr *s)
{
	// your code here
}