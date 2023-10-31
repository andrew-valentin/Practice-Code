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

int numDigits(int num)
{
	int digits = 0, n = num;
	
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	
	return digits;
}

Node **createBuckets()
{
	int i;
	Node **buckets = (Node **)malloc(DECIMAL * sizeof(Node *));
	
	for (i = 0; i < DECIMAL; i++)
		buckets[i] = NULL;
	
	return buckets;
}

int findMin(int *arr, int len)
{
	int i, min = INT_MAX;
	
	for (i = 0; i < len; i++)
		if (arr[i] < min)
			min = arr[i];
	
	return min;
}

int findMax(int *arr, int len)
{
	int i, max = INT_MIN;
	
	for (i = 0; i < len; i++)
		if (arr[i] > max)
			max = arr[i];
	
	return max;
}

Node *insertToBucketList(Node *head, Node *node)
{
	Node *temp;
	
	if (head == NULL)
		return node;
	
	if (node->data < head->data)
	{
		node->next = head;
		return node;
	}
	
	temp = head;
	
	while (temp->next != NULL)
	{
		if (node->data < temp->next->data)
		{
			node->next = temp->next;
			temp->next = node;
			return head;
		}
		
		temp = temp->next;
	}

	temp->next = node;

	return head;
}

void insertToBucket(int val, Node **buckets, int len)
{
	int i, n = 10;
	Node *node = createNode(val);
	
	for (i = 0; i < (len - 1); i++)
		val /= n;

	buckets[abs(val % n)] = insertToBucketList(buckets[val % n], node);
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

void bucketSortLL(int *arr, int len)
{
	int i, j = 0, min = findMin(arr, len), max = findMax(arr, len);
	int minLen = numDigits(min), maxLen = numDigits(max);
	Node **pos = createBuckets();
	Node **neg = createBuckets();
	Node *temp = NULL;
	
	for (i = 0; i < len; i++)
	{
		if (arr[i] >= 0)
			insertToBucket(arr[i], pos, maxLen);
		else
			insertToBucket(arr[i], neg, minLen);
	}
	
	for (i = DECIMAL - 1; i >= 0; i--)
	{
		while (neg[i] != NULL)
		{
			arr[j++] = (neg[i])->data;
			temp = neg[i];
			neg[i] = (neg[i])->next;
			free(temp);
		}
		
		neg[i] = NULL;
	}
	
	for (i = 0; i < DECIMAL; i++)
	{
		while (pos[i] != NULL)
		{
			arr[j++] = (pos[i])->data;
			temp = pos[i];
			pos[i] = (pos[i])->next;
			free(temp);
		}
	}
	
	free(pos);
	free(neg);
}