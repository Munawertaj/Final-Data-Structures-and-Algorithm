#include <bits/stdc++.h>

using namespace std;

const int PRIME = 101;
const long long MOD = 1e9 + 7;

int hashValue(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return int(ch - 'a' + 1);
    else if (ch >= 'A' && ch <= 'Z')
        return int(ch - 'A' + 27);
    else
        return int(ch - '0' + 53);
}

long long power(int base, int exp)
{
    long long result = 1;
    long long base_mod = base % MOD;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base_mod) % MOD;

        base_mod = (base_mod * base_mod) % MOD;
        exp /= 2;
    }

    return result;
}

long long calculateHash(const string& str, int length)
{
    long long hash = 0;
    for (int i = 0; i < length; ++i)
    {
        hash = (hash + hashValue(str[i]) * power(PRIME, i)) % MOD;
    }
    return hash;
}

long long updateHash(long long prevHash, char oldChar, char newChar, int patternLength)
{
    long long newHash = (prevHash - hashValue(oldChar) + MOD) % MOD;
    newHash = (newHash * power(PRIME, MOD - 2)) % MOD; // Use modular inverse of PRIME
    newHash = (newHash + hashValue(newChar) * power(PRIME, patternLength - 1)) % MOD;
    return newHash;
}

int search(const string& text, const string& pattern)
{
    int patternLength = pattern.length();
    int textLength = text.length();

    if (patternLength > textLength)
        return -1;

    long long patternHash = calculateHash(pattern, patternLength);
    long long textHash = calculateHash(text, patternLength);

    for (int i = 0; i <= textLength - patternLength; ++i)
    {
        if (textHash == patternHash)
        {
            if (text.substr(i, patternLength) == pattern)
                return i;
        }

        if (i < textLength - patternLength)
            textHash = updateHash(textHash, text[i], text[i + patternLength], patternLength);
    }

    return -1;
}

int main()
{
    string text = "fourscoreandsevenyearsagoourfathersbroughtforthuponthiscontinentanewnation";
    string pattern = "ourfathersbroughtforthuponthiscontinentanewnation";

    int index = search(text, pattern);

    if (index < 0)
        cout << "Pattern Not Found" << endl;
    else
        cout << "Pattern Found at INDEX = " << index << endl;

    return 0;
}
