#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to perform Insertion Sort in descending order
void insertionSortDesc(vector<int>& arr) {
    int n = arr.size();
    // Traverse the array starting from the second element
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // The current element to be inserted
        int j = i - 1;
        
        // Move elements of arr[0..i-1], that are smaller than key, one position ahead
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert the key at the correct position
        arr[j + 1] = key;
    }
}

int main() {
    const int size = 40000;  // Adjust the size of the array here
    vector<int> arr(size);
    
    // Initialize the array with values from size-1 to 0 (sorted in descending order)
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;  // Numbers in descending order from size-1 to 0
    }

    // Measure the time taken for sorting the array using Insertion Sort
    auto start = high_resolution_clock::now();  // Start time
    insertionSortDesc(arr);  // Call insertion sort function to sort the array
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);  // Calculate duration

    // Output the time taken to sort the array in microseconds
    cout << "Sorted array (Insertion Descending): " << duration.count() << " microseconds" << endl;

    return 0;
}
