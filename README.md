# Program 1: InfiniteInt

This program is a way to store large integers by utilizing Linked Lists.

## Summary

The "InfiniteInt", which is what the Int gets turned into, will be able to perform regular arithmetic functions like an int would. Each LinkedList node will contain one decimal place of the Int, making it so that there is no limit to the number of decimal places the inputted int has. The input will be a regular int, which gets translated into an InfiniteInt. There are also operator overloads for arithmetic functions such as addition, subtraction, and multiplication that allow the user to perform simple arithmetic operations upon the InfiniteInts. There can also be multiple InfiniteInts that do these functions with each other or you could do these functions with one InfiniteInt and one regular int. These will both work because the InfiniteInt type will act as a regular int that just stores a wider range of numbers with no limitations.

### Sample Output

Here is a sample output of the program given a sample main() function:

$ ./a.exe
Converted 125 (int) to 125 InfiniteInt
125 + 975 (int) = 1100
123
Input 123
Converted 64 (int) to 64 InfiniteInt
1100 + 64 = 1164 1100 - 64 = 1036 1100 \* 64 = 70400
70400 has 5 digits

From this, it is clear that an Int gets converted to an InfiniteInt, which then performs arithmetic functions.
