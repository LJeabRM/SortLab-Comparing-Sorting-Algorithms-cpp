#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to perform Selection Sort in descending order
void selectionSortDesc(vector<int>& arr) {
    int n = arr.size();
    // Loop through each element of the array
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;  // Assume the current element is the largest
        // Find the largest element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;  // Update the index of the largest element
            }
        }
        // Swap the found maximum element with the current element
        swap(arr[i], arr[maxIndex]);
    }
}

int main() {
    const int size = 1000;  // Adjust the size of the array here
    vector<int> arr(size);
    
    // Initialize the array with values from size-1 down to 0 (sorted in descending order)
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;  // Numbers in descending order from size-1 to 0
    }

    // Measure the time taken for sorting the array using Selection Sort
    auto start = high_resolution_clock::now();  // Start time
    selectionSortDesc(arr);  // Call selection sort function to sort the array
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);  // Calculate duration

    // Output the time taken to sort the array in microseconds
    cout << "Sorted array (Selection Descending): " << duration.count() << " microseconds" << endl;

    return 0;
}
