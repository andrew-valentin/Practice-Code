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

Node **createBuckets()
{
	int i;
	Node **buckets = (Node **)malloc(DECIMAL * sizeof(Node *));
	
	for (i = 0; i < DECIMAL; i++)
		buckets[i] = NULL;
	
	return buckets;
}

void insertToHead(Node **arr, int index, int value)
{
	Node *node = createNode(value);
	
	node->next = arr[index];
	arr[index] = node;
}

int removeFromHead(Node **arr, int index)
{
	int val = arr[index]->data;
	Node *temp = arr[index]->next;
	
	free(arr[index]);
	arr[index] = temp;
	
	return val;
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

void placeInBuckets(Node **buckets, int *arr, int len, int place)
{
	int i, index, num, temp_place;
	
	for (i = len - 1; i >= 0; i--)
	{
		num = arr[i];
		temp_place = place;
		
		while (temp_place > 1)
		{
			num /= 10;
			temp_place--;
		}
		
		index = abs(num % 10);
		
		insertToHead(buckets, abs(index), arr[i]);
	}
}

void placeInArray(Node **buckets, int *arr)
{
	int i, index = 0;

	for (i = 0; i < DECIMAL; i++)
		while (buckets[i] != NULL)
			arr[index++] = removeFromHead(buckets, i);
}

void radixSortHelper(Node **buckets, int *arr, int len, int place)
{
	placeInBuckets(buckets, arr, len, place);
	placeInArray(buckets, arr);
}

void radixSort(int *arr, int len)
{
	int i, pos_len = 0, neg_len = 0, place = 1;
	int num_passes_pos = numDigits(findMax(arr, len)), num_passes_neg = numDigits(findMin(arr, len));
	Node **pos = createBuckets();
	Node **neg = createBuckets();
	int *pos_arr = NULL;
	int *neg_arr = NULL;
	
	for (i = 0; i < len; i++)
	{
		if (arr[i] < 0)
			neg_len++;
		else
			pos_len++;
	}
	
	pos_arr = (int *)malloc(pos_len * sizeof(int));
	neg_arr = (int *)malloc(neg_len * sizeof(int));
	
	pos_len = 0;
	neg_len = 0;
	
	for (i = 0; i < len; i++)
	{
		if (arr[i] < 0)
			neg_arr[neg_len++] = arr[i];
		else
			pos_arr[pos_len++] = arr[i];
	}
	
	for (i = 0; i < num_passes_pos; i++)
	{
		radixSortHelper(pos, pos_arr, pos_len, place);
		place++;
	}
	
	place = 1;
	
	for (i = 0; i < num_passes_neg; i++)
	{
		radixSortHelper(neg, neg_arr, neg_len, place);
		place++;
	}
	
	place = 0;
	
	for (i = neg_len - 1; i >= 0; i--)
		arr[place++] = neg_arr[i];
	
	for (i = 0; i < pos_len; i++)
		arr[place++] = pos_arr[i];
	
	
	free(pos);
	free(neg);
	free(pos_arr);
	free(neg_arr);
}