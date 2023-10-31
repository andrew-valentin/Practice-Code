#define ALPHABET 26
#define BUFFER 1098

typedef struct Trie
{
	int counter;
	struct Trie **letters;
} Trie;

void printTrieHelper(Trie *trie, char *str, int index)
{
	int i;
	
	if (trie == NULL || trie->letters == NULL)
		return;
	
	if (trie->counter != 0)
		printf("%d\t%s\n", trie->counter, str);
	
	for (i = 0; i < ALPHABET; i++)
	{
		str[index] = 'a' + i;
		str[index + 1] = '\0';
		
		printTrieHelper(trie->letters[i], str, index + 1);
		
		str[index] = '\0';
	}
}

void printTrie(Trie *trie)
{
	char *str = NULL;
	
	if (trie == NULL || trie->letters == NULL)
	{
		printf("Trie is empty!\n");
		return;
	}
	
	str = (char *)malloc(BUFFER * sizeof(char));
	str[0] = '\0';
	
	printf("\nTrie:\n");
	printTrieHelper(trie, str, 0);
	printf("\n");
	
	free(str);
}

// Dynamically creates a trie and returns the address
Trie *createTrie()
{
	// your code here
}

// Frees the trie
void *freeTrie(Trie *trie)
{
	// your code here
}

// Returns 1 if the trie is empty; otherwise, return 0
int isArrEmpty(Trie **arr)
{
	// your code here
}

// Returns the lowercase instance of a letter
char lowercase(char letter)
{
	// your code here
}

// Inserts an instance of a word into the trie
Trie *insert(Trie *trie, char *str)
{
	// your code here
}

// Deletes an instance of a word in the trie
// If only one instance exists, remove the word from the trie
Trie *delete(Trie *trie, char *str)
{
	// your code here
}

// Returns 1 if the string exists in the trie; otherwise, return 0
int contains(Trie *trie, char *str)
{
    // your code here
}