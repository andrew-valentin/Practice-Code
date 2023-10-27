/*
 * Question provided by GeeksforGeeks
 * Question and GeeksforGeeks answer available online at https://www.geeksforgeeks.org/print-increasing-sequences-length-k-first-n-natural-numbers/
 * 
 * Answer below provided by Andrew Valentin
 * Available online at https://github.com/andrew-valentin/Practice-Code
 *
 *
 *
 * Question:
 * Given two positive integers n and k, print all increasing sequences of length k such that the elements 
 * in every sequence are from the first n natural numbers.
 *
 * Examples: 

 * Input: k = 2, n = 3
 * Output: 1 2
 *         1 3
 *         2 3 
 *
 * Input: k = 5, n = 5
 * Output: 1 2 3 4 5
 *
 * Input: k = 3, n = 5
 * Output: 1 2 3
 *         1 2 4
 *         1 2 5
 *  	   1 3 4
 *         1 3 5
 *         1 4 5
 *         2 3 4
 *         2 3 5
 *         2 4 5
 *         3 4 5
 */
 
/*
 * As always, try to solve this problem on your own first. My solution may look different from yours, and that's ok!
 * If you can understand my solution and your solution, then that means you can understand a problem from different
 * directions, which is very beneficial! I have provided an explanation for my solution so it will make more sense, but
 * try to come up with your own solution before you look at mine!
 * 
 * 
 * 
 * 
 * 
 * Explanation:
 *
 * Since we know there could be many sequences that are length k, it makes sense to store the value that could be in the
 * sequence until we get the entire sequence, so there will be an array on length k that we will need to use.
 *
 * Furthermore, since every sequence is increasing from 1 to n, we don't have to worry about going back and forth between many
 * values to find arbitrary sequences, so we know that in our function calls we would start at 1 and go up to n.
 *
 * In order to make the sequences, it is already established that they have to be length k and within the range [1, n], so that
 * gives us our base case. If we reach a number greater than n we return; however, we must first check if we have k numbers in our
 * sequence because if we do, then we need to print it and then go back in order to find new sequences.
 *
 * The next thing we need to figure out is how to find the sequences. If we can have sequences that begin with an integer in the range
 * of [1, n-k+1], then how do we get the sequences that start with integers greater than 1? Well, there are probably a few was to go
 * about answering this question, but for my solution, I decided to use n choose k. If you have not taken Intro to Discrete yet then 
 * don't worry about what that means. In short, given n items, choose k items. In the question above, we are given two options:
 * 
 * 1. Add a value to the sequence
 * 2. Don't add a value to the sequence
 *
 * Given two options, choose one.
 *
 * So now, we have our recursive calls! We will just need to make two recursive calls to represent these two options we can make!
 *
 * Let's see what the code would look like now in pseudocode:
 *
 * void function(current index of sequence array, n, current sequence value, sequence array, length of sequence array (which is also k))
 * {
 *     Base case:
 *         If the length of the sequence array is equal to the current index of the sequence array print the sequence and return
 *         If the current sequence value is greater than n then return
 *
 *     Store the value in the array
 *
 *     Recursive call incrementing the index of the array and current sequence value
 *     Recursive call ONLY incrementing the current sequence value
 * }
 *
 * Now that we have the pseudocode, let's code it up!
 */


 
#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int len)
{
	int i;
	
	printf("\t");
	
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	
	printf("\n");
}

// k represents the current index of the array and curr_val represents the current value of the sequence
void printISHelper(int k, int n, int curr_val, int *arr, int len)
{
	// Base cases
    if (k == len) // <- At this point, we have filled up the array to it's capacity, so we have a sequence!
    {
        printArr(arr, len); // <- Print the sequence!
        return;
    }

    if (curr_val == n + 1) // <- Here, we have gone beyond n, which means the previous if statement was false
        return;            //    and we don't have a sequence. Since we have gone beyond n, we need to find
						   //    different sequences

    arr[k] = curr_val;	   // <- Update the sequence

    printISHelper(k + 1, n, curr_val + 1, arr, len); // <- Here, we choose to add a value to the sequence,
													 //    so we must increment the value and the index
    printISHelper(k, n, curr_val + 1, arr, len);     // <- Here, we choose to NOT add a value to the sequence,
													 //    so we will keep the index the same (so in the next
													 //    call we overwrite the value in that index which will
													 //    create a new sequence) and increment the value so that
													 //    a different sequence will be created in the next call
}

void printIncreasingSequences(int k, int n)
{
    int *arr = (int *)calloc(k, sizeof(int)); // <- Create the array to store the sequences

    printISHelper(0, n, 1, arr, k); // <- Print all of the sequences

    free(arr); // <- Free the array so we prevent memory leaks!
}

int main()
{
	printf("k = 2, n = 3:\n");
    printIncreasingSequences(2, 3);
	
	printf("k = 5, n = 5:\n");
	printIncreasingSequences(5, 5);
	
	printf("k = 3, n = 5:\n");
	printIncreasingSequences(3, 5);
	
    return 0;
}