#include<iostream>
#include<vector>
using namespace std;

// Function to partition the array 
int partition(vector<int> &nums, int low, int high) {

    // ---------------Considering First element as pivot------------------
    // int pivot = nums[low]; // Choosing the first element as the pivot
    // swap(nums[low], nums[high]); // Move pivot to the end to use the rest of the array for comparison

    // ---------------Considering Last element as pivot------------------
    // int pivot = nums[high]; // Choosing the last element as the pivot

    // ---------------Considering Middle element as pivot------------------
    int mid = low + (high - low) / 2;
    int pivot = nums[mid]; // Choosing the middle element as the pivot
    swap(nums[mid], nums[high]); // Move pivot to the end to use the rest of the array for comparison

    int pivotIndex = low; // Initialize the pivot index to the start of the segment

    for (int i = low; i < high; i++) {
        // Swap with pivot if the current element is less than or equal to the pivot
        if (nums[i] <= pivot) {
            swap(nums[i], nums[pivotIndex]); 
            pivotIndex++;
        }
    }

    swap(nums[pivotIndex], nums[high]); // Move the pivot element back to its correct position
    return pivotIndex; // Return the pivot index
}

// A different approach where pivot is the middle element and iteration occurs from both ends
// Function to partition the array and return the pivot index using the middle element as the pivot
int partitionMiddle(vector<int>& nums, int low, int high) {
    
    int mid = low + (high - low) / 2;  // Choosing the middle element as the pivot
    int pivot = nums[mid];
    
    // Initializing pointers for partitioning
    int left = low;
    int right = high;

    while (left <= right) {

        // Finding an element on the left side that is greater than or equal to the pivot
        while (left <= right && nums[left] < pivot) {
            left++;
        }

        // Finding an element on the right side that is less than or equal to the pivot
        while (left <= right && nums[right] > pivot) {
            right--;
        }

        // If elements are out of order, swap them
        if (left <= right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    
    return right + 1;
}


// Function to perform quicksort on the array
void quickSort(vector<int>& nums, int low, int high) {

    // Base case: if the segment has one or no elements, it is already sorted
    if(low >= high)
        return;

    int pivotIndex = partition(nums, low, high);  // Partitioning the array
    // int pivotIndex = partitionMiddle(nums, low, high);  // Partitioning considering middle element as pivot

    quickSort(nums, low, pivotIndex - 1);   // Recursively sorting the left half
    quickSort(nums, pivotIndex + 1, high);  // Recursively sorting the right half
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

    // Perform quicksort on the array
    quickSort(nums, 0, nums.size() - 1);

    // Print the sorted array
    printArray(nums);

    return 0;
}
