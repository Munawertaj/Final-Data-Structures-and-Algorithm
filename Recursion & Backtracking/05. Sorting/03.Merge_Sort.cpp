#include<iostream>
#include<vector>
using namespace std;

// Approach - 1 (creating new array at every recursion call)

// Function to merge two sorted arrays into one sorted array
vector<int> merge(vector<int>& first, vector<int>& second) {
    int length1 = first.size();
    int length2 = second.size();
    int index1 = 0, index2 = 0;
    int mergeIndex = 0;
    
    vector<int> mergedArray(length1 + length2);

    // Merge elements from both arrays in sorted order
    while(index1 < length1 && index2 < length2) {

        if(first[index1] < second[index2])
            mergedArray[mergeIndex++] = first[index1++];
        else
            mergedArray[mergeIndex++] = second[index2++];
    }

    // Copy remaining elements from the first array, if any
    while(index1 < length1) {
        mergedArray[mergeIndex++] = first[index1++];
    }

    // Copy remaining elements from the second array, if any
    while(index2 < length2) {
        mergedArray[mergeIndex++] = second[index2++];
    }

    return mergedArray;
}

// Recursive merge sort function that creates new arrays at each recursion call
vector<int> mergeSort(vector<int> arr) {
    // Base case: if the array has only one element, it is already sorted
    if(arr.size() == 1)
        return arr;

    int mid = arr.size() / 2;
    
    // Copy the first half into the start vector and remaining half into the end vector
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    // Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    vector<int> mergedArray = merge(left, right);

    return mergedArray;
}

// Approach - 2 (More efficient) (Updating the array instead of creating new array at every recursion call)

// Function to merge two sorted segments of the array in place
void mergeInPlace(vector<int>& arr, int start, int mid, int end) {

    vector<int> temp(end - start + 1); // Temporarily stores merged vector

    int index1 = start, index2 = mid + 1, tempIndex = 0;

    // Merge elements from both segments in sorted order
    while(index1 <= mid && index2 <= end) {

        if(arr[index1] <= arr[index2])
            temp[tempIndex++] = arr[index1++];
        else
            temp[tempIndex++] = arr[index2++];
    }

    // Copy remaining elements from the first segment, if any
    while(index1 <= mid) {
        temp[tempIndex++] = arr[index1++];
    }

    // Copy remaining elements from the second segment, if any
    while(index2 <= end) {
        temp[tempIndex++] = arr[index2++];
    }

    // Copy the merged elements back to the original array
    for(int i = 0; i < temp.size(); ++i) {
        arr[start + i] = temp[i];   // Since the original array will be updated from the start position
    }
}

// Recursive merge sort function that updates the array in place
void mergeSortInPlace(vector<int>& arr, int start, int end) {
    // Base case: if the segment has one or no elements, it is already sorted
    if(start >= end)
        return;
    
    int mid = (start + end) / 2;

    // Recursively sort both halves
    mergeSortInPlace(arr, start, mid);
    mergeSortInPlace(arr, mid + 1, end);

    // Merge the sorted halves
    mergeInPlace(arr, start, mid, end);
}

// Function to print the elements of an array
void printArray(vector<int>& nums) {

    for(int val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {

    vector<int> nums = {8, 7, 4, 6, 5, 1, 3, 2};
    // vector<int> nums = {5, 4, 3, 2, 1};
    
    // Sort using the first approach (creating new array at each recursion call)
    vector<int> sortedArray = mergeSort(nums);
    printArray(sortedArray);
    
    // Sort using the second approach (updating the array in place)
    mergeSortInPlace(nums, 0, nums.size() - 1);
    printArray(nums);

    return 0;
}
