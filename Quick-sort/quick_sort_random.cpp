#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Partition function for QuickSort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Pivot element is chosen as the last element
    int i = (low - 1);  // Index of the smaller element

    // Traverse the array to rearrange elements such that elements smaller than pivot are on the left
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {  // If the current element is smaller than the pivot
            i++;
            swap(arr[i], arr[j]);  // Swap the elements
        }
    }
    swap(arr[i + 1], arr[high]);  // Swap the pivot element to its correct position
    return (i + 1);  // Return the index of the pivot
}

// Function to implement the QuickSort algorithm
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);
        
        // Recursively sort the left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int size = 40000;  // Array size
    vector<int> arr(size);
    
    srand(time(0));  // Use current time as seed for random number generation
    // Initialize the array with random values between 0 and 39999
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 40000;  // Random numbers between 0 and 39999
    }

    // Measure the time taken for sorting the array using QuickSort
    auto start = high_resolution_clock::now();  // Start time
    quickSort(arr, 0, arr.size() - 1);  // Call quickSort function to sort the array
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);  // Calculate duration

    // Output the time taken to sort the array in microseconds
    cout << "Sorted array (Random): " << duration.count() << " microseconds" << endl;

    return 0;
}
