/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */
 
 

#define EMPTY 0

// Node struct
typedef struct Node 
{
	int value;
	struct Node *next;
} Node;

// Linked List struct that holds head and tail
typedef struct LL 
{
	Node *head;
	Node *tail;
} LL;

// Prints a linked list
void printLLHead(Node *head) 
{
	Node *temp = head;

	printf("\n");

	while (temp != NULL) 
	{
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	  
	printf("NULL\n");
}

void printLL(LL *list) 
{
	if (list == NULL)
	{
		printf("\nList does not exist!\n");
		return;
	}
	
	printLLHead(list->head);
}

// Creates an empty linked list and returns the address
LL *createLL()
{
	return (LL *)malloc(sizeof(LL));
}

// Initializes values inside an empty linked list to NULL
void initLL(LL *ll) 
{
	ll->head = NULL;
	ll->tail = NULL;
}

// Creates an empty node and returns the address
Node *createNode() 
{
	Node *node = (Node *)malloc(sizeof(Node));
	
	// If malloc() fails return NULL
	// (I won't be doing this for every function for the sake
	// of simplicity, but do keep this in mind for future code)
	if (node == NULL)
		return NULL;
	
	node->value = EMPTY;
	node->next = NULL;
	
	return node;
}

// Creates a node that holds a value and returns the address
Node *createNodeWithValue(int val) 
{
	Node *node = (Node *)malloc(sizeof(Node));
	
	node->value = val;
	node->next = NULL;
	
	return node;
}

// Return 1 if a node with a specific value exists within the linked list
// Otherwise, return 0
int containsNodeHead(Node *head, int val)
{
	Node *temp;
	
	if (head == NULL)
		return 0;
	
	temp = head;
	
	while (temp != NULL)
	{
		if (temp->value == val)
			return 1;
			
		temp = temp->next;
	}
	
	return 0;
}

int containsNodeLL(LL *list, int val)
{
	return (list == NULL) ? 0 : containsNodeHead(list->head, val);
}

/*
 * NOTE:
 * 	The following functions are meant to explore the different
 * 	ways one could insert or remove nodes from a linked list.
 *
 * 	There are functions that do the same thing; however, they
 * 	are slightly different due to way they have to be implemented.
 *
 * 	Make sure to read the comments carefully since they all explain
 * 	the purpose of each function.
 *
 * 	You could approach each function with a different solution;
 * 	however, in order to stay consistent, the function descriptions
 * 	are written to guide you toward a specific solution.
 * 
 * 	Feel free to play around with the functions in order to implement
 * 	different solutions, but do keep in mind that the function
 * 	descriptions are written to reflect the consistency that I usually
 * 	aim to achieve whenever I write code (and which is something you
 * 	should keep in mind whenever you write code in order to write cleaner,
 * 	easier to understand code).
 */
 
// Inserts an empty node to the head of a linked list and returns the new head
Node *insertEmptyNodeToHead(Node *head) 
{
	Node *node = createNode();
	node->next = head;
	
	return node;
}

// Inserts a node with a value to the head of a linked list and returns the new head
Node *insertNodeWithValueToHead(Node *head, int val) 
{
	Node *node = createNodeWithValue(val);
	node->next = head;
	
	return node;
}

// Inserts an empty node to the head of a linked list
void insertNodeToListHead(LL *list) 
{
	Node *node;
	
	if (list == NULL)
		return;
	
	if (list->head == NULL)
	{
		list->head = createNode();
		list->tail = list->head;
		
		return;
	}
	
	node = createNode();
	node->next = list->head;
	list->head = node;
}

// Inserts a node with a value to the head of a linked list
void insertNodeWithValueToListHead(LL *list, int val) 
{
	Node *node;
	
	if (list == NULL)
		return;
	
	if (list->head == NULL)
	{
		list->head = createNodeWithValue(val);
		list->tail = list->head;
		
		return;
	}
	
	node = createNodeWithValue(val);
	node->next = list->head;
	list->head = node;
}

// Inserts an empty node to the tail of a linked list and returns the head
Node *insertEmptyNodeToTail(Node *head) 
{
	Node *temp;
	
	if (head == NULL)
		return createNode();
		
	temp = head;
	
	while (temp->next != NULL)
		temp = temp->next;
	
	temp->next = createNode();
	
	return head;
}

// Inserts a node with a value to the tail of a linked list and returns the head
Node *insertNodeWithValueToTail(Node *head, int val) 
{
	Node *temp;

	if (head == NULL)
		return createNodeWithValue(val);
		
	temp = head;
	
	while (temp->next != NULL)
		temp = temp->next;
	
	temp->next = createNodeWithValue(val);
	
	return head;
}

// Inserts an empty node to the tail of a linked list
void insertNodeToListTail(LL *list) 
{
	Node *node;
	
	if (list == NULL)
		return;
	
	if (list->head == NULL)
	{
		list->head = createNode();
		list->tail = list->head;
		
		return;
	}
	
	node = createNode();
	list->tail->next = node;
	list->tail = node;
}

// Inserts a node with a value to the tail of a linked list
void insertNodeWithValueToListTail(LL *list, int val) 
{
	Node *node;
	
	if (list == NULL)
		return;
	
	if (list->head == NULL)
	{
		list->head = createNodeWithValue(val);
		list->tail = list->head;
		
		return;
	}
	
	node = createNodeWithValue(val);
	list->tail->next = node;
	list->tail = node;
}

/*
 * NOTE:
 * 	The following functions are meant to give you practice inserting a node
 *  into the middle of a linked list or removing a node from the middle of
 *  a linked list at some arbitrary index.
 *  
 *  The index can start at 0 or 1 (that is up to you to decide).
 *
 *  Just make sure to stay consistent so you don't cause any errors
 *  or confusion later on!
 */

// Inserts an empty node to a specific index in the linked list and returns the head
Node *insertEmptyNodeToLLHead(Node *head, int index) 
{
	Node *temp, *prev, *new_node;
	int curr;
	
	if (head == NULL)
		return NULL;
	
	if (index == 0)
		return insertEmptyNodeToHead(head);
	
	temp = head->next;
	prev = head;
	curr = 1;
	
	while (temp != NULL)
	{
		if (index == curr)
		{
			new_node = createNode();
			new_node->next = temp;
			prev->next = new_node;
			
			return head;
		}
		
		temp = temp->next;
		prev = prev->next;
		curr++;
	}
	
	if (curr == index)
		prev->next = createNode();
	
	return head;
}

// Inserts a node with a value to a specific index in the linked list and returns the head
Node *insertNodeWithValueToLLHead(Node *head, int val, int index) 
{
	Node *temp, *prev, *new_node;
	int curr;
	
	if (head == NULL)
		return NULL;
	
	if (index == 0)
		return insertNodeWithValueToHead(head, val);
	
	temp = head->next;
	prev = head;
	curr = 1;
	
	while (temp != NULL)
	{
		if (index == curr)
		{
			new_node = createNodeWithValue(val);
			new_node->next = temp;
			prev->next = new_node;
			
			return head;
		}
		
		temp = temp->next;
		prev = prev->next;
		curr++;
	}
	
	if (curr == index)
		prev->next = createNodeWithValue(val);
	
	return head;
}

// Inserts an empty node to a specific index in the linked list
void insertEmptyNodeToLL(LL *list, int index) 
{
	Node *temp, *prev;
	int curr;
	
	if (list == NULL || list->head == NULL)
		return;
	
	if (index == 0)
	{
		list->head = insertEmptyNodeToHead(list->head);
		return;
	}
	
	temp = list->head->next;
	prev = list->head;
	curr = 1;
	
	while (temp != NULL)
	{
		if (index == curr)
		{
			prev->next = createNode();
			prev->next->next = temp;
			
			return;
		}
		
		temp = temp->next;
		prev = prev->next;
		curr++;
	}
	
	if (curr == index)
	{
		list->tail->next = createNode();
		list->tail = list->tail->next;
	}
}

// Inserts a node with a value to a specific index in the linked list
void insertNodeWithValueToLL(LL *list, int val, int index) 
{
	Node *temp, *prev;
	int curr;
	
	if (list == NULL || list->head == NULL)
		return;
	
	if (index == 0)
	{
		list->head = insertNodeWithValueToHead(list->head, val);
		return;
	}
	
	temp = list->head->next;
	prev = list->head;
	curr = 1;
	
	while (temp != NULL)
	{
		if (index == curr)
		{
			prev->next = createNodeWithValue(val);
			prev->next->next = temp;
			
			return;
		}
		
		temp = temp->next;
		prev = prev->next;
		curr++;
	}
	
	if (curr == index)
	{
		list->tail->next = createNodeWithValue(val);
		list->tail = list->tail->next;
	}
}

// Takes in the head of a linked list and inserts a node with value val in between every node
void insertBetweenAllNodesLLHead(Node *head, int val)
{
	Node *temp, *temp_next;

	if (head == NULL)
		return;
	
	temp = head;

	while (temp->next != NULL)
	{
		temp_next = temp->next;
		temp->next = createNodeWithValue(val);
		temp = temp->next;
		temp->next = temp_next;
		temp = temp->next;
	}
}

// Takes in a linked list and inserts a node with value val in between every node
void insertBetweenAllNodesLL(LL *list, int val)
{
	Node *temp, *temp_next;

	if (list == NULL || list->head == NULL)
		return;
	
	temp = list->head;

	while (temp->next != NULL)
	{
		temp_next = temp->next;
		temp->next = createNodeWithValue(val);
		temp = temp->next;
		temp->next = temp_next;
		temp = temp->next;
	}
}

// Takes in the head of a linked list, removes a node from the head, and returns the new head
Node *removeNodeFromHead(Node *head)
{
	Node *new_head;
	
	if (head == NULL)
		return NULL;
	
	new_head = head->next;
	free(head);
	
	return new_head;
}

// Takes in a linked list and removes a node from the head
void removeNodeFromListHead(LL *list)
{
	Node *old_head;

	if (list == NULL || list->head == NULL)
		return;
	
	if (list->head == list->tail)
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		
		return;
	}
	
	old_head = list->head;
	list->head = list->head->next;
	free(old_head);
	
	return;
}

// Takes in the head of a linked list, removes a node from the tail, and returns the head
Node *removeNodeFromTail(Node *head)
{
	Node *temp;
	
	if (head == NULL)
		return NULL;
		
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	
	temp = head;
	
	while (temp->next->next != NULL)
		temp = temp->next;
	
	free(temp->next);
	temp->next = NULL;
	
	return head;
}

// Takes in a linked list and removes a node from the tail
void removeNodeFromListTail(LL *list)
{
	Node *temp;
	
	if (list == NULL || list->head == NULL)
		return;
		
	if (list->head == list->tail)
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		
		return;
	}
	
	temp = list->head;
	
	while (temp->next->next != NULL)
		temp = temp->next;
	
	free(temp->next);
	temp->next = NULL;
	list->tail = temp;
}

// Takes in the head of a linked list and a value, removes the first instance of a node
// with that value, and returns the head of the linked list
Node *removeNodeWithValueFromLLHead(Node *head, int val)
{
	Node *prev, *temp;
	
	if (head == NULL)
		return NULL;
	
	if (head->value == val)
		return removeNodeFromHead(head);
	
	prev = head;
	temp = head->next;
	
	while (temp != NULL)
	{
		if (temp->value == val)
		{
			prev->next = temp->next;
			free(temp);
			
			return head;
		}
		
		temp = temp->next;
		prev = prev->next;
	}
	
	return head;
}

// Takes in a linked list and a value and removes the first instance of a node
// with that value
void removeNodeWithValueFromLL(LL *list, int val)
{
	Node *prev, *temp;
	
	if (list == NULL || list->head == NULL)
		return;
	
	if (list->head->value == val)
	{
		removeNodeFromListHead(list);
		
		return;
	}
	
	prev = list->head;
	temp = list->head->next;
	
	while (temp != NULL)
	{
		if (temp->value == val)
		{
			prev->next = temp->next;
			
			if (temp == list->tail)
				list->tail = prev;
				
			free(temp);
			
			return;
		}
		
		temp = temp->next;
		prev = prev->next;
	}
}

// Takes in the head of a linked list and an index, removes the node
// at that index, and returns the head of the linked list
Node *removeNodeInIndexFromLLHead(Node *head, int index)
{
	Node *prev, *temp;
	int curr;
	
	if (head == NULL)
		return NULL;
		
	if (index == 0)
		return removeNodeFromHead(head);
	
	prev = head;
	temp = head->next;
	curr = 1;
	
	while (temp != NULL)
	{
		if (curr == index)
		{
			prev->next = temp->next;
			free(temp);
			
			return head;
		}
		
		temp = temp->next;
		prev = prev->next;
		curr++;
	}
	
	return head;
}

// Takes in a linked list and an index and removes the node at that index
void removeNodeInIndexFromLL(LL *list, int index)
{
	Node *prev, *temp;
	int curr;
	
	if (list == NULL || list->head == NULL)
		return;
		
	if (index == 0)
	{
		removeNodeFromListHead(list);
		
		return;
	}
	
	prev = list->head;
	temp = list->head->next;
	curr = 1;
	
	while (temp != NULL)
	{
		if (curr == index)
		{
			prev->next = temp->next;
			
			if (temp == list->tail)
				list->tail = prev;
				
			free(temp);
			
			return;
		}
		
		temp = temp->next;
		prev = prev->next;
		curr++;
	}
}

// Takes in the head of a linked list and removes all nodes with the value val
Node *removeAllValuesFromLLHead(Node *head, int val)
{
	Node *prev, *temp, *temp_next;

	if (head == NULL)
		return NULL;

	prev = head;
	temp_next = prev->next;

	while (temp_next != NULL)
	{
		if (temp_next->value == val)
		{
			prev->next = temp_next->next;
			temp = temp_next;
			temp_next = prev->next;

			free(temp);
			continue;
		}

		prev = prev->next;
		temp_next = temp_next->next;
	}

	if (head->value == val)
		return removeNodeFromHead(head);
	
	return head;
}

// Takes in a linked list and removes all nodes with the value val
void removeAllValuesFromLL(LL *list, int val)
{
	Node *prev, *temp, *temp_next;

	if (list == NULL || list->head == NULL)
		return;

	prev = list->head;
	temp_next = prev->next;

	while (temp_next != NULL)
	{
		if (temp_next->value == val)
		{
			temp = temp_next;
			prev->next = temp_next->next;
			temp_next = prev->next;

			free(temp);
			continue;
		}

		prev = prev->next;
		temp_next = temp_next->next;
	}

	if (prev != list->tail)
		list->tail = prev;
	
	if (list->head->value == val)
		removeNodeFromListHead(list);
}

// Takes in the head of a linked list and frees all nodes in the linked list
void *freeLLHead(Node *head)
{
	Node *temp, *prev;
	
	if (head == NULL)
		return NULL;
	
	prev = head;
	temp = head;

	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	
	return NULL;
}

// Takes in a linked list and frees the entire linked list
void *freeLL(LL *list)
{
	if (list == NULL)
		return NULL;
		
	if (list->head != NULL)
	{
		list->head = freeLLHead(list->head);
		list->tail = NULL;
	}

	free(list);
	
	return NULL;
}