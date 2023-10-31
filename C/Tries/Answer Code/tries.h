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
	int i;
	
	Trie *trie = (Trie *)malloc(sizeof(Trie));
	
	trie->counter = 0;
	trie->letters = (Trie **)malloc(ALPHABET * sizeof(Trie *));
	
	for (i = 0; i < ALPHABET; i++)
		trie->letters[i] = NULL;
	
	return trie;
}

// Frees the trie
void *freeTrie(Trie *trie)
{
	int i;
	
	if (trie == NULL)
		return NULL;
	
	if (trie->letters != NULL)
		for (i = 0; i < ALPHABET; i++)
			trie->letters[i] = freeTrie(trie->letters[i]);
	
	free(trie->letters);
	free(trie);
	
	return NULL;
}

// Returns 1 if the trie is empty; otherwise, return 0
int isArrEmpty(Trie **arr)
{
	int i;
	
	for (i = 0; i < ALPHABET; i++)
		if (arr[i] != NULL)
			return 0;
		
	return 1;
}

// Returns the lowercase instance of a letter
char lowercase(char letter)
{
	if (letter >= 'a' && letter <= 'z')
		return letter;
	return letter + 32;
}

// Inserts an instance of a word into the trie
Trie *insert(Trie *trie, char *str)
{
	Trie *t = NULL;
	Trie *root = NULL;
	int i;

	if (trie == NULL)
	{
		t = createTrie();
		root = t;

		// for each character in string to to index in trie
		for (i = 0; i < strlen(str); i++)
		{
			t->letters[str[i] - 'a'] = createTrie();
			t = t->letters[str[i] - 'a'];
		}
		
		t->counter++;

		return root;
	}

	root = trie;

	for (i = 0; i < strlen(str); i++)
	{
		if (trie->letters[str[i] - 'a'] == NULL)
			trie->letters[str[i] - 'a'] = createTrie();
		trie = trie->letters[str[i] - 'a'];
	}
	
	trie->counter++;

	return root;
}

// Deletes an instance of a word in the trie
// If only one instance exists, remove the word from the trie
Trie *delete(Trie *trie, char *str)
{
	if (trie == NULL || str == NULL)
		return trie;
	
	if (str[0] == '\0' && trie->counter > 0)
		trie->counter--;
	else
		trie->letters[lowercase(str[0]) - 'a'] = delete(trie->letters[lowercase(str[0]) - 'a'], str + 1);


	if (trie->counter == 0 && isArrEmpty(trie->letters))
		trie = freeTrie(trie);
	
	return trie;
}

// Returns 1 if the string exists in the trie; otherwise, return 0
int contains(Trie *trie, char *str)
{
	if (trie == NULL || trie->letters == NULL)
		return 0;
	if (str == NULL || str[0] == '\0')
		return 1;
	
	return contains(trie->letters[lowercase(str[0]) - 'a'], str + 1);
}