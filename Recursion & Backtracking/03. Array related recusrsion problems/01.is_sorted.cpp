#include<iostream>
#include<vector>
using namespace std;

bool isSorted(int index, vector<int>& arr)
{
    if(index == arr.size())
        return true;
    
    return (arr[index] >= arr[index-1]) && isSorted(index + 1, arr);
}

int main()
{
    vector<int> arr1 = {1, 2, 4, 5, 8, 10, 12};
    vector<int> arr2 = {1, 2, 4, 5, 3, 8, 10, 12};

    cout<< isSorted(1, arr1) << endl;
    cout<< isSorted(1, arr2) << endl;

    return 0;
}