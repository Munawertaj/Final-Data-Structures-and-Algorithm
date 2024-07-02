#include <iostream>
#include <string>
using namespace std;

// Function to count all permutations of the original string
int countPermutations1(int index, string& original, string processed, int count)
{
    if(index == original.size())
    {
        count++;
        return count;
    }

    char ch = original[index];
    int length = processed.size();

    // Insert the current character at each position in the processed string
    for(int i = 0; i <= length; ++i)
    {
        string start = processed.substr(0, i); // Substring before the insertion point
        string end = processed.substr(i, length); // Substring after the insertion point

        // Recursively generate permutations with the new processed string including the current character
        count = countPermutations1(index + 1, original, start + ch + end, count);
    }

    return count; // Return the number of generated permutations
}

// Function to count all permutations of the original string
int countPermutations2(int index, string& original, string processed)
{
    if(index == original.size())
    {
        return 1;
    }

    char ch = original[index];
    int length = processed.size();

    int count = 0;

    // Insert the current character at each position in the processed string
    for(int i = 0; i <= length; ++i)
    {
        string start = processed.substr(0, i); // Substring before the insertion point
        string end = processed.substr(i, length); // Substring after the insertion point

        // Get number of permutations from the recursive call
        count += countPermutations2(index + 1, original, start + ch + end);
    }

    return count;
}



int main()
{
    string original = "abcd";
    string processed = "";
    int count = 0;
    
    // count = countPermutations1(0, original, processed, count);
    count = countPermutations2(0, original, processed);

    cout << count << endl;

    return 0;
}
