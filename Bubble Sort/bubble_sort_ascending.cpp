#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to perform Bubble Sort in ascending order
void bubbleSortAsc(vector<int>& arr) {
    int n = arr.size();
    // Loop through the array to perform bubble sort
    for (int i = 0; i < n - 1; i++) {
        // Traverse through the array from the start to the unsorted part
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int size = 40000;  // Adjust the size of the array here
    vector<int> arr(size);
    
    // Initialize the array with values from 0 to size-1 (sorted in ascending order)
    for (int i = 0; i < size; i++) {
        arr[i] = i;  // Numbers in ascending order from 0 to size-1
    }

    // Measure the time taken for sorting the array using Bubble Sort
    auto start = high_resolution_clock::now();  // Start time
    bubbleSortAsc(arr);  // Call bubble sort function to sort the array
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);  // Calculate duration

    // Output the time taken to sort the array in microseconds
    cout << "Sorted array (Ascending): " << duration.count() << " microseconds" << endl;

    return 0;
}
