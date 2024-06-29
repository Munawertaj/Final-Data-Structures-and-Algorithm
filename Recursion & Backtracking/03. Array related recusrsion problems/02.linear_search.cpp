#include<iostream>
#include<vector>
using namespace std;

bool isContain(int index, vector<int>& arr, int target)
{
    if(index == arr.size())
        return false;
    
    return (arr[index] == target) || isContain(index + 1, arr, target);
}

int findIndex(int index, vector<int>& arr, int target)
{
    if(index == arr.size())
        return -1;
    
    if(arr[index] == target)
        return index;
    
    return findIndex(index + 1, arr, target);
}

int findIndexFromLast(int index, vector<int>& arr, int target)
{
    if(index == -1)
        return -1;

    if(arr[index] == target)
        return index;
    
    return findIndexFromLast(index - 1, arr, target);
}

int main()
{
    vector<int> arr = {1, 2, 4, 4, 5, 8, 10, 12};
    
    int target1 = 5;
    int target2 = 12;
    int target3 = 6;

    cout<< isContain(0, arr, target1) << endl;
    cout<< isContain(0, arr, target2) << endl;
    cout<< isContain(0, arr, target3) << endl;

    cout<< endl;

    cout<< findIndex(0, arr, target1) << endl;
    cout<< findIndex(0, arr, target2) << endl;
    cout<< findIndex(0, arr, target3) << endl;

    cout<< endl;

    cout<< findIndex(0, arr, 4) << endl;
    cout<< findIndexFromLast(arr.size() - 1, arr, 4);

    return 0;
}