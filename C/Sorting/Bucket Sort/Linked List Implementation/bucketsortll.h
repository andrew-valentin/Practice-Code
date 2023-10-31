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

void printArr(int *arr, int len)
{
	int i;
	
	for (i = 0; i < len; i++)
		printf("%d%c", arr[i], (i == len - 1) ? '\n' : ' ');
}

/*
The following auxilliary functions are not required, 
but may help you if you are feeling stuck:

	- numDigits()
	- createBuckets()
	- findMin()
	- findMax()
	- insertToBucketList()
	- insertToBucket()
*/

int numDigits(int num)
{
	// your code goes here
}

Node **createBuckets()
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

Node *insertToBucketList(Node *head, Node *node)
{
	// your code goes here
}

void insertToBucket(int val, Node **buckets, int len)
{
	// your code goes here
}

void bucketSortLL(int *arr, int len)
{
	// your code goes here
}