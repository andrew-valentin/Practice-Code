/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <stdio.h>

#include "bst.h"

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