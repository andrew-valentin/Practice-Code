/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Review-Code/tree/main/Review-Code/Linked-Lists
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */
 


#include <stdio.h>
#include <stdlib.h>

#include "linkedlists.h"

#define LOOP 3

int main()
{
	int i;
	Node *head = NULL;
	printLLHead(head);
	// NULL
	
	for (i = 0; i < LOOP; i++)
		head = insertEmptyNodeToHead(head);
	printLLHead(head);
	// 0->0->0->NULL

	for (i = 1; i <= LOOP; i++)
		head = insertNodeWithValueToHead(head, i);
	printLLHead(head);
	// 3->2->1->0->0->0->NULL

	for (i = 1; i <= LOOP; i++)
		head = insertNodeWithValueToTail(head, i);
	printLLHead(head);
	// 3->2->1->0->0->0->1->2->3->NULL

	for (i = 0; i < LOOP; i++)
		head = insertEmptyNodeToTail(head);
	printLLHead(head);
	// 3->2->1->0->0->0->1->2->3->0->0->0->NULL

	head = insertEmptyNodeToLLHead(head, 0);
	head = insertEmptyNodeToLLHead(head, 3);
	head = insertEmptyNodeToLLHead(head, 7);
	printLLHead(head);
	// 0->3->2->0->1->0->0->0->0->1->2->3->0->0->0->NULL

	head = insertNodeWithValueToLLHead(head, 10, 7);
	head = insertNodeWithValueToLLHead(head, 10, 0);
	head = insertNodeWithValueToLLHead(head, 10, 2);
	printLLHead(head);
	// 10->0->10->3->2->0->1->0->0->10->0->0->1->2->3->0->0->0->NULL
	
	if (containsNodeHead(head, 20))
		printf("\nList contains the value %d :D\n\n", 20);
	else
		printf("\nList does not contain the value %d :(\n\n", 20);
	// List does not contain the value 20 :(

	if (containsNodeHead(head, 0))
		printf("List contains the value %d :D\n\n", 0);
	else
		printf("List does not contain the value %d :(\n\n", 0);
	// List contains the value 0 :D

	for (i = 0; i < LOOP; i++)
		head = removeNodeFromHead(head);
	printLLHead(head);
	// 3->2->0->1->0->0->10->0->0->1->2->3->0->0->0->NULL

	for (i = 0; i < LOOP; i++)
		head = removeNodeFromTail(head);
	printLLHead(head);
	// 3->2->0->1->0->0->10->0->0->1->2->3->NULL

	head = removeNodeWithValueFromLLHead(head, 1);
	printLLHead(head);
	// 3->2->0->0->0->10->0->0->1->2->3->NULL

	head = removeNodeWithValueFromLLHead(head, 100);
	printLLHead(head);
	// 3->2->0->0->0->10->0->0->1->2->3->NULL

	head = removeNodeInIndexFromLLHead(head, 0);
	printLLHead(head);
	// 2->0->0->0->10->0->0->1->2->3->NULL

	head = removeNodeInIndexFromLLHead(head, 4);
	printLLHead(head);
	// 2->0->0->0->0->0->1->2->3->NULL

	head = removeNodeInIndexFromLLHead(head, 8);
	printLLHead(head);
	// 2->0->0->0->0->0->1->2->NULL

	insertBetweenAllNodesLLHead(head, 9);
	printLLHead(head);
	// 2->9->0->9->0->9->0->9->0->9->0->9->1->9->2->NULL

	head = removeAllValuesFromLLHead(head, 0);
	printLLHead(head);
	// 2->9->9->9->9->9->9->1->9->2->NULL

	head = removeAllValuesFromLLHead(head, 2);
	printLLHead(head);
	// 9->9->9->9->9->9->1->9->NULL

	head = removeAllValuesFromLLHead(head, 9);
	printLLHead(head);
	// 1->NULL
	
	insertBetweenAllNodesLLHead(head, 9);
	printLLHead(head);
	// 1->NULL

	head = removeAllValuesFromLLHead(head, 1);
	printLLHead(head);
	// NULL
	
	head = freeLLHead(head);
	printLLHead(head);
	// NULL

	
	LL *list = NULL;
	printLL(list);
	// List does not exist!
	
	list = createLL();
	initLL(list);
	printLL(list);
	// NULL
	
	for (i = 0; i < LOOP; i++)
		insertNodeToListHead(list);
	printLL(list);
	// 0->0->0->NULL

	for (i = 1; i <= LOOP; i++)
		insertNodeWithValueToListHead(list, i);
	printLL(list);
	// 3->2->1->0->0->0->NULL

	for (i = 1; i <= LOOP; i++)
		insertNodeWithValueToListTail(list, i);
	printLL(list);
	// 3->2->1->0->0->0->1->2->3->NULL

	for (i = 0; i < LOOP; i++)
		insertNodeToListTail(list);
	printLL(list);
	// 3->2->1->0->0->0->1->2->3->0->0->0->NULL

	insertEmptyNodeToLL(list, 0);
	insertEmptyNodeToLL(list, 3);
	insertEmptyNodeToLL(list, 7);
	printLL(list);
	// 0->3->2->0->1->0->0->0->0->1->2->3->0->0->0->NULL

	insertNodeWithValueToLL(list, 10, 7);
	insertNodeWithValueToLL(list, 10, 0);
	insertNodeWithValueToLL(list, 10, 2);
	printLL(list);
	// 10->0->10->3->2->0->1->0->0->10->0->0->1->2->3->0->0->0->NULL
	
	if (containsNodeLL(list, 20))
		printf("\nList contains the value %d :D\n\n", 20);
	else
		printf("\nList does not contain the value %d :(\n\n", 20);
	// List does not contain the value 20 :(

	if (containsNodeLL(list, 0))
		printf("List contains the value %d :D\n\n", 0);
	else
		printf("List does not contain the value %d :(\n\n", 0);
	// List contains the value 0 :D

	for (i = 0; i < LOOP; i++)
		removeNodeFromListHead(list);
	printLL(list);
	// 3->2->0->1->0->0->10->0->0->1->2->3->0->0->0->NULL

	for (i = 0; i < LOOP; i++)
		removeNodeFromListTail(list);
	printLL(list);
	// 3->2->0->1->0->0->10->0->0->1->2->3->NULL

	removeNodeWithValueFromLL(list, 1);
	printLL(list);
	// 3->2->0->0->0->10->0->0->1->2->3->NULL

	removeNodeWithValueFromLL(list, 100);
	printLL(list);
	// 3->2->0->0->0->10->0->0->1->2->3->NULL

	removeNodeInIndexFromLL(list, 0);
	printLL(list);
	// 2->0->0->0->10->0->0->1->2->3->NULL

	removeNodeInIndexFromLL(list, 4);
	printLL(list);
	// 2->0->0->0->0->0->1->2->3->NULL

	removeNodeInIndexFromLL(list, 8);
	printLL(list);
	// 2->0->0->0->0->0->1->2->NULL

	insertBetweenAllNodesLL(list, 9);
	printLL(list);
	// 2->9->0->9->0->9->0->9->0->9->0->9->1->9->2->NULL

	removeAllValuesFromLL(list, 0);
	printLL(list);
	// 2->9->9->9->9->9->9->1->9->2->NULL

	removeAllValuesFromLL(list, 2);
	printLL(list);
	// 9->9->9->9->9->9->1->9->NULL

	removeAllValuesFromLL(list, 9);
	printLL(list);
	// 1->NULL
	
	insertBetweenAllNodesLL(list, 9);
	printLL(list);
	// 1->NULL

	removeAllValuesFromLL(list, 1);
	printLL(list);
	// NULL
	
	list = freeLL(list);
	printLL(list);
	// List does not exist!
	
	return 0;
}