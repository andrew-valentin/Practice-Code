/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <stdio.h>
#include <stdlib.h>

/*
 * When trying to approach recursive problems, there is a very simple format to remember:
 * 
 * recursiveFunction(parameter(s))
 * {
 *     Base case
 *     (optional depending on problem) some code
 *     (return a value if needed) recursive call
 *     (optional depending on problem and if no return is made before) some code
 * }
 *
 * - The base case is the end of your recursive calls
 *   - This is the simplest answer that can be given and can be seen as where you would begin/end (depending on the problem)
 * - The recursive call will involve some change the the argument
 * - You may need to include some code before and/or after the recursive call, but that depends on the problem and solution
 *   - REMEMBER: If you include code after the recursive calls, you CANNOT include a return statement with the recursive call
 *   - All code after a return statement is ignored so if there is code after a return it will never run
 */

void printString(char *str)
{
	// Base case
    if (str[0] == '\0') // <- The end of a string in C is '\0', so once that character
    {					//    is reached we know to stop making recursive calls and return
        printf("\n");
        return;
    }

    printf("%c", str[0]);
    printString(str + 1); // <- Recursive call (we must update str in order to print every
}					      //    character and in this case I am using pointer arithmetic)

// ^
// A return statement is not necessary since once the recursive call is finished,
// there is no more code to execute, so the function will return on its own

void printReverseStringHelper(char *str)
{
	if (str[0] == '\0')
        return;
    
    printReversStringHelper(str + 1);
	printf("%c", str[0]); // <- Since we want to print the string in reverse, we will make
						  //    the recursive calls first and then print each character
}
// ^
// How it works:
//     In printString(), we print as we make the recursive calls until we reach the base case; 
//     however, in printReverseStringHelper(), we make all of the recursive calls until we reach 
//     the base case and then print as we come back up to the original call to the function.

void printReverseString(char *str) // <- The only purpose of this function is to add a new line after
{								   //    printing the string (so I can keep the main() code pretty :P)
    printReverseString(str);
	printf("\n");
}

int fib(int n)
{
    if (n < 3)
        return n - 1;

    return fib(n - 1) + fib(n - 2);
}

int fibIterative(int n)
{
    int i, index = 0;
    int seq[2];

    if (n < 3)
        return n - 1;
    
    seq[0] = 0;
    seq[1] = 1;

    for (i = 3; i <=n; i++)
    {
        seq[index] = seq[0] + seq[1];
        index = (index + 1) % 2;
    }

    return seq[(index + 1) % 2];
}

int main()
{
    char *str = "Hello!";
    int n = 47;

    printString(str); // "Hello!"
	printReverseString(str); // "!olleH"

    printf("fib(%d) = %d\n", n, fib(n));
	//printf("fib(%d) = %d\n", n, fibIterative(n));
	
    return 0;
}