#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to generate all subsequences(Not pass by references) and store them in allSubSequences
void generatingSubSequences1(int index, string& original, string& SubSequence, vector<string>& allSubSequences)
{
    if(index == original.size())
    {
        allSubSequences.push_back(SubSequence);
        return;
    }

    // Exclude the current character
    generatingSubSequences1(index + 1, original, SubSequence, allSubSequences);

    // Include the current character
    SubSequence.push_back(original[index]);
    generatingSubSequences1(index + 1, original, SubSequence, allSubSequences);

    // Remove the character which is added
    SubSequence.pop_back();
}

// Function to generate all subsequences and store them in allSubSequences (MOSTLY USED)
void generatingSubSequences2(int index, string& original, string& SubSequence, vector<string>& allSubSequences)
{
    if(index == original.size())
    {
        allSubSequences.push_back(SubSequence);
        return;
    }

    // Include the current character
    SubSequence.push_back(original[index]);
    generatingSubSequences2(index + 1, original, SubSequence, allSubSequences);
    
    // Exclude the current character
    SubSequence.pop_back();
    generatingSubSequences2(index + 1, original, SubSequence, allSubSequences);
}


// Function to generate all subsequences and return them
vector<string> generatingSubSequences3(int index, string& original, string& SubSequence, vector<string>& allSubSequences)
{
    if(index == original.size())
    {
        allSubSequences.push_back(SubSequence);
        return allSubSequences;
    }

    // Include the current character
    SubSequence.push_back(original[index]);
    allSubSequences = generatingSubSequences3(index + 1, original, SubSequence, allSubSequences);

    // Exclude the current character
    SubSequence.pop_back();
    allSubSequences = generatingSubSequences3(index + 1, original, SubSequence, allSubSequences);

    return allSubSequences;
}

// Function to generate all subsequences and return them, using concatenation
vector<string> generatingSubSequences4(int index, string& original, string& SubSequence)
{
    if(index == original.size())
    {
        return {SubSequence};
    }

    // Include the current character and recurse
    vector<string> allSubSequencesFromLeft;
    SubSequence.push_back(original[index]);
    allSubSequencesFromLeft = generatingSubSequences4(index + 1, original, SubSequence);

    // Exclude the current character and recurse
    vector<string> allSubSequencesFromRight;
    SubSequence.pop_back();
    allSubSequencesFromRight = generatingSubSequences4(index + 1, original, SubSequence);
    
    // Combine results from both recursions
    allSubSequencesFromLeft.insert(allSubSequencesFromLeft.end(), allSubSequencesFromRight.begin(), allSubSequencesFromRight.end());

    return allSubSequencesFromLeft;
}

// Function to print all generated subsequences
void printAllSubSequences(vector<string>& allSubSequences)
{
    for(auto& SubSequence: allSubSequences)
    {
        for(char ch: SubSequence)
        {
            cout << ch;
        }
        cout << ", ";
    }
    cout << endl;
}

int main()
{
    string original = "abc";
    string SubSequence = "";

    vector<string> allSubSequences;

    // generatingSubSequences1(0, original, SubSequence, allSubSequences);
    generatingSubSequences2(0, original, SubSequence, allSubSequences);
    // allSubSequences = generatingSubSequences3(0, original, SubSequence, allSubSequences);
    // allSubSequences = generatingSubSequences4(0, original, SubSequence);


    printAllSubSequences(allSubSequences);
    return 0;
}
