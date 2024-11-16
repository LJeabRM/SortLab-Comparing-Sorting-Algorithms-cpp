#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to perform Bubble Sort in descending order
void bubbleSortDesc(vector<int>& arr) {
    int n = arr.size();
    // Loop through the array to perform bubble sort
    for (int i = 0; i < n - 1; i++) {
        // Traverse through the array from the start to the unsorted part
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is smaller than the next element, swap them
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int size = 40000;  // Adjust the size of the array here
    vector<int> arr(size);
    
    // Initialize the array with values from size-1 down to 0 (sorted in descending order)
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;  // Numbers in descending order from size-1 to 0
    }

    // Measure the time taken for sorting the array using Bubble Sort
    auto start = high_resolution_clock::now();  // Start time
    bubbleSortDesc(arr);  // Call bubble sort function to sort the array
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);  // Calculate duration

    // Output the time taken to sort the array in microseconds
    cout << "Sorted array (Descending): " << duration.count() << " microseconds" << endl;

    return 0;
}
