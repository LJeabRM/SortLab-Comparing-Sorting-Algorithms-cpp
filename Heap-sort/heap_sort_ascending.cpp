#include <iostream>
#include <vector>
#include <algorithm>  // For std::make_heap, std::pop_heap, std::push_heap
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Function to perform Heap Sort
void heapSort(vector<int>& arr) {
    // Convert the array into a heap
    make_heap(arr.begin(), arr.end());
    
    // Extract the smallest elements from the heap one by one
    for (int i = arr.size() - 1; i >= 0; --i) {
        // Move the root (smallest element) to the end of the array
        pop_heap(arr.begin(), arr.begin() + i + 1);
    }
}

int main() {
    const int size = 20000;  // Array size
    vector<int> arr(size);
    
    // Initialize the array with values from 1 to 40000 (inclusive)
    srand(time(0));  // Seed for random number generation
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;  // Assign values from 1 to 40000
    }

    // Measure the time taken for sorting the array using Heap Sort
    auto start = high_resolution_clock::now();  // Start time
    heapSort(arr);  // Call heapSort function to sort the array
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);  // Calculate duration

    // Output the time taken to sort the array in microseconds
    cout << "Sorted array (Ascending): " << duration.count() << " microseconds" << endl;

    return 0;
}
