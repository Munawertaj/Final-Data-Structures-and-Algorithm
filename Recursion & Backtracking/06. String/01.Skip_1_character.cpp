/*
    Problem Description: You are given a string and a escape character.You have to skip that character
    and return the remaining charcters by maintaining the order.
*/

#include<iostream>
#include<string>

using namespace std;

string skipCharacter1(int index, string& original, char skipChar, string& ans)
{
    if(index == original.size())
        return ans;
    
    if(original[index] != skipChar)
        ans.push_back(original[index]);
    
    return skipCharacter1(index + 1, original, skipChar, ans);
}

string skipCharacter2(int index, string& original, char skipChar)
{
    if(index == original.size())
        return "";
    
    if(original[index] == skipChar)
        return skipCharacter2(index + 1, original, skipChar);
    else
        return original[index] + skipCharacter2(index + 1, original, skipChar);
}

void printString(string& st)
{
    for(char ch: st)
    {
        cout << ch;
    }
    cout << endl;
}

int main()
{
    string st = "bcabdacaadcga", ans = "";
    char skipChar = 'a';

    ans = skipCharacter1(0, st, skipChar, ans);
    printString(ans);

    ans = skipCharacter2(0, st, skipChar);
    printString(ans);

    return 0;

}
