/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
} Node;

// Creates a node and returns the address
Node *createNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

// Bottom Left Most Node
int BLMN(Node *head)
{
	if (head == NULL)
		return 0;
	if (head->left == NULL)
		return head->data;
	
	return BLMN(head->left);
}

// Bottom Right Most Node
int BRMN(Node *head)
{
	if (head == NULL)
		return 0;
	if (head->right == NULL)
		return head->data;
	
	return BRMN(head->right);
}

// Creates a node with a passed in value and inserts that node into the BST
Node *insert(Node *head, int value)
{
	if (head == NULL)
		return createNode(value);
	
	if (value < head->data)
		head->left = insert(head->left, value);
	else
		head->right = insert(head->right, value);
	
	return head;
}

// Inserts a node into the BST
Node *insertNode(Node *head, Node *node)
{
	if (node == NULL)
		return head;
	
	if (head == NULL)
		return node;

	if (node->data < head->data)
		head->left = insertNode(head->left, node);
	else
		head->right = insertNode(head->right, node);
	
	return head;
}

// Deletes the first instance of a node with the passed in value if the node exists
Node *delete(Node *head, int value)
{
	Node *temp;
	
	if (head == NULL)
		return NULL;
	
	if (head->data == value)
	{
		if (head->left == NULL)
		{
			temp = head->right;
			free(head);
			head = temp;
		}
		else if (head->right == NULL)
		{
			temp = head->left;
			free(head);
			head = temp;
		}
		else
		{
			//temp = BLMN(head->right);
			temp = createNode(BRMN(head->left));
			head = delete(head, temp->data);
			temp = insertNode(temp, head->left);
			temp = insertNode(temp, head->right);
			
			free(head);
			head = temp;
		}		
	}
	else if (head->data > value)
	{
		head->left = delete(head->left, value);
	}
	else
	{
		head->right = delete(head->right, value);
	}
	
	return head;
}

// Returns 1 if the value passed through is in the BST; otherwise, return 0
int contains(Node *head, int value)
{
	if (head == NULL)
		return 0;
	if (head->data == value)
		return 1;
	/*
	if (value < head->data)
		return contains(head->left, value);
	return contains(head->right, value);
	*/
	return (value < head->data) ? contains(head->left, value) : contains(head->right, value);
}

// Performs a preorder traversal of a BST
void preorder(Node *head)
{
	if (head == NULL)
		return;
	
	printf("%d ", head->data);
	preorder(head->left);
	preorder(head->right);
}

// Performs an inorder traversal of a BST
void inorder(Node *head)
{
	if (head == NULL)
		return;
	
	inorder(head->left);
	printf("%d ", head->data);
	inorder(head->right);
}

// Performs a postorder traversal of a BST
void postorder(Node *head)
{
	if (head == NULL)
		return;
	
	postorder(head->left);
	postorder(head->right);
	printf("%d ", head->data);
}

// Frees an entire BST
void *forestFire(Node *head)
{
	if (head == NULL)
		return NULL;
	
	head->left = forestFire(head->left);
	head->right = forestFire(head->right);
	
	free(head);
	return NULL;
}

void preorderTraversal(Node *head)
{
	if (head == NULL)
		printf("NULL");
	
	preorder(head);
	printf("\n");
}

void inorderTraversal(Node *head)
{
	if (head == NULL)
		printf("NULL");
	
	inorder(head);
	printf("\n");
}

void postorderTraversal(Node *head)
{
	if (head == NULL)
		printf("NULL");
	
	postorder(head);
	printf("\n");
}

int main()
{
	Node *head = NULL;
	
	head = insert(head, 5);
	head = insert(head, 7);
	head = insert(head, 2);
	head = insert(head, 1);
	head = insert(head, 4);
	head = insert(head, 8);
	head = insert(head, 10);
	head = insert(head, 6);
	head = insert(head, 3);
	
	/*
	
			     5
			 2	     7
		  1     4  6   8
		       3        10
			   
	*/
	
	inorderTraversal(head);
	preorderTraversal(head);
	printf("\n");
	
	head = delete(head, 5);
	
	/*
	
			     4
			 2	     7
		  1     3  6   8
		                10
			   
	*/
	
	inorderTraversal(head);
	preorderTraversal(head);
	printf("\n");
	
	head = delete(head, 7);
	
	/*
	
			     4
			 2	     6
		  1     3      8
		                10
			   
	*/
	
	inorderTraversal(head);
	preorderTraversal(head);
	printf("\n");
	
	head = delete(head, 2);
	
	/*
	
			     4
			 1	     6
		        3      8
		                10
			   
	*/
	
	inorderTraversal(head);
	preorderTraversal(head);
	printf("\n");
	
	head = delete(head, 4);
	
	/*
	
			     3
			 1	     6
		               8
		                10
			   
	*/
	
	inorderTraversal(head);
	preorderTraversal(head);
	printf("\n");
	
	head = delete(head, 6);
	
	/*
	
			     3
			 1	     8
		               10
			   
	*/
	
	inorderTraversal(head);
	preorderTraversal(head);
	printf("\n");
	
	head = delete(head, 10);
	
	/*
	
			     3
			 1	     8
			   	
	*/
	
	inorderTraversal(head);
	preorderTraversal(head);
	printf("\n");
	
	head = freeBST(head);
	
	inorderTraversal(head);
	preorderTraversal(head);
	printf("\n");
	
	return 0;
}