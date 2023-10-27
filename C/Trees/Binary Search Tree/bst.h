typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
} Node;

// Creates a node and returns the address
??? createNode(???)
{
	// your code goes here
}

// Creates a node with a passed in value and inserts that node into the BST
??? insert(???)
{
	// your code goes here
}

// Inserts a node into the BST
??? insertNode(???)
{
	// your code goes here
}

// Deletes the first instance of a node with the passed in value if the node exists
??? delete(???)
{
	// your code goes here
}

// Returns 1 if the value passed through is in the BST; otherwise, return 0
??? contains(???)
{
	// your code goes here
}

// Performs a preorder traversal of a BST
??? preorder(???)
{
	// your code goes here
}

// Performs an inorder traversal of a BST
??? inorder(???)
{
	// your code goes here
}

// Performs a postorder traversal of a BST
??? postorder(???)
{
	// your code goes here
}

// Frees an entire BST
??? forestFire(???)
{
    // your code goes here
}

void preorderTraversal(Node *head)
{
	preorder(head);
	printf("\n");
}

void inorderTraversal(Node *head)
{
	inorder(head);
	printf("\n");
}

void postorderTraversal(Node *head)
{
	postorder(head);
	printf("\n");
}