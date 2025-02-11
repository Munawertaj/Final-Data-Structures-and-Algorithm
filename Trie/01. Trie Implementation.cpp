#include <iostream>
#include <string>
using namespace std;

struct TrieNode
{
    TrieNode *links[26]; // Array of pointers to store links to child nodes, corresponding 'a' to 'z'
    bool end = false;    // A Flag indicating the end of a word

    TrieNode()
    {
        // Initialize all child nodes pointers to nullptr
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
    }

    // Checks if the current node contains a child node corresponding to the given character
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    // Creates a new child node corresponding to the given character
    void setKey(char ch)
    {
        links[ch - 'a'] = new TrieNode;
    }

    // Retrieves the child node corresponding to the given character
    TrieNode *getKey(char ch)
    {
        return links[ch - 'a'];
    }

    // Checks if the current node is end of a word
    bool isEnd()
    {
        return end;
    }

    // Marks the current node as the end of a word
    void setEnd()
    {
        end = true;
    }
};

class Trie
{

private:
    TrieNode *root;
    TrieNode *node;

public:
    // Constructor to initialize the Trie with an empty root node
    Trie()
    {
        root = new TrieNode;
    }

    // Inserts a word into the Trie
    void insert(string word)
    {
        node = root;

        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->setKey(ch); // Create a new child node for the character if it is not present
            }
            node = node->getKey(ch); // Move to the child node
        }

        node->setEnd(); // Mark the end of the word
    }

    // Search for an exact match of the word in the Trie
    bool search(string word)
    {
        node = root;

        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                return false; // If a character is not found, the word is not in the Trie
            }
            node = node->getKey(ch); // Move to the child node
        }

        return node->isEnd(); // Check if the last node is the end of a word
    }

    // Checks if there is any word in the trie that starts with the given prefix
    bool startsWith(string word)
    {
        node = root;

        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                return false; // If a character is not found, the word is not in the Trie
            }
            node = node->getKey(ch); // Move to the child node
        }

        return true; // Means all characters are found
    }
};

int main()
{
    Trie trie; // An object of the Trie class

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << "Search 'apple': " << trie.search("apple") << endl;     // true
    cout << "Search 'app': " << trie.search("app") << endl;         // true
    cout << "Search 'bat': " << trie.search("bat") << endl;         // true
    cout << "Search 'batman': " << trie.search("batman") << endl;   // false
    cout << "StartsWith 'ap': " << trie.startsWith("ap") << endl;   // true
    cout << "StartsWith 'bat': " << trie.startsWith("bat") << endl; // true
    cout << "StartsWith 'cat': " << trie.startsWith("cat") << endl; // false

    return 0;
}