// CPP program to find all combination of numbers
// from a given string of digits
#include <iostream>
#include <cstring>
using namespace std;

// function to print combinations of numbers
// in given input string
void printCombinations(char* input, int index,
					char* output, int outLength)
{
	// no more digits left in input string
	if (input[index] == '\0')
	{
		// print output string & return
		output[outLength] = '\0';
		cout << output << endl;
		return;
	}
	
	// place current digit in input string
	output[outLength] = input[index];
	
	// separate next digit with a space
	output[outLength + 1] = ' ';
	
	printCombinations(input, index + 1, output,
								outLength + 2);
	
	// if next digit exists make a
	// call without including space
	if(input[index + 1] != '\0')
	printCombinations(input, index + 1, output,
									outLength + 1);
	
}

// driver function to test above function
int main()
{
	char input[] = "1214";
	char *output = new char[100];

	// initialize output with empty string
	output[0] = '\0';
	
	printCombinations(input, 0, output, 0);
	return 0;
}
