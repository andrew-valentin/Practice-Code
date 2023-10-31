#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tries.h"

int main()
{
	Trie *trie = NULL;
	
	char *str = "cat";
	
	if (contains(trie, str))
		printf("Trie contains \"%s\"!\n", str);
	else
		printf("Trie does not contain \"%s\".\n", str);
	// Trie does not contain "cat".
	
	printTrie(trie);
	// Trie is empty!
	
	trie = delete(trie, str);
	
	printTrie(trie);
	// Trie is empty!
	
	trie = insert(trie, str);
	
	if (contains(trie, str))
		printf("Trie contains \"%s\"!\n", str);
	else
		printf("Trie does not contain \"%s\".\n", str);
	// Trie contains "cat"!
	
	printTrie(trie);
	// 1    cat

	trie = delete(trie, str);
	
	trie = insert(trie, "alpha");
	trie = insert(trie, "ant");
	trie = insert(trie, "ants");
	trie = insert(trie, "cats");
	trie = insert(trie, "cat");
	trie = insert(trie, "catastrophe");
	trie = insert(trie, "tree");
	trie = insert(trie, "trees");
	trie = insert(trie, "alpha");
	trie = insert(trie, "cats");
	trie = insert(trie, "catastrophe");
	trie = insert(trie, "catastrophe");
	trie = insert(trie, "straw");
	trie = insert(trie, "strawberry");
	trie = insert(trie, "strawberries");
	
	str = "food";
	
	if (contains(trie, str))
		printf("Trie contains \"%s\"!\n", str);
	else
		printf("Trie does not contain \"%s\".\n", str);
	// Trie does not contain "food".
	
	printTrie(trie);
	/*
	2	alpha
	1	ant
	1	ants
	1	cat
	3	catastrophe
	2	cats
	1	straw
	1	strawberries
	1	strawberry
	1	tree
	1	trees
	*/
	
	trie = delete(trie, "alpha");
	trie = delete(trie, "catastrophe");
	trie = delete(trie, "catastrophe");
	trie = delete(trie, "cats");
	trie = delete(trie, "straw");
	trie = delete(trie, "strawberry");
	trie = delete(trie, "food");
	trie = delete(trie, "a");
	trie = delete(trie, "tree");
	trie = delete(trie, "trees");
	
	printTrie(trie);
	/*
	1	alpha
	1	ant
	1	ants
	1	cat
	1	catastrophe
	1	cats
	1	strawberries
	*/
	
	trie = freeTrie(trie);
	
	printTrie(trie);
	// Trie is empty!
	
	return 0;
}