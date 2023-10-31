/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#define DECIMAL 10

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *createNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	
	node->data = val;
	node->next = NULL;
	
	return node;
}

void printArr(int *arr, int len)
{
	int i;
	
	for (i = 0; i < len; i++)
		printf("%d%c", arr[i], (i == len - 1) ? '\n' : ' ');
}

void printList(Node* list)
{
	while (list != NULL)
	{
		printf("%d -> ", list->data);
		list = list->next;
	}
	printf("NULL\n");
}

void printBuckets(Node **buckets)
{
	int i;
	
	for (i = 0; i < DECIMAL; i++)
	{
		printf("%d: ", i);
		printList(buckets[i]);
	}
}

/*
The following auxilliary functions are not required, 
but may help you if you are feeling stuck:

	- numDigits()
	- findMin()
	- findMax()
	- createBuckets()
	- insertToHead()
	- removeFromHead()
	- placeInBuckets()
	- placeInArray()
*/

int numDigits(int num)
{
	// your code goes here
}

int findMin(int *arr, int len)
{
	// your code goes here
}

int findMax(int *arr, int len)
{
	// your code goes here
}

Node **createBuckets()
{
	// your code goes here
}

void insertToHead(Node **arr, int index, int value)
{
	// your code goes here
}

int removeFromHead(Node **arr, int index)
{
	// your code goes here
}

void placeInBuckets(Node **buckets, int *arr, int len, int place)
{
	// your code goes here
}

void placeInArray(Node **buckets, int *arr)
{
	// your code goes here
}

void radixSort(int *arr, int len)
{
	// your code goes here
}