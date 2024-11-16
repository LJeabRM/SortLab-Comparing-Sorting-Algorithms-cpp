#include <iostream> 
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Function to perform Selection Sort in ascending order (applied on a random array)
void selectionSortRandom(vector<int>& arr) {
    int n = arr.size();
    // Loop through each element of the array
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Assume the current element is the smallest
        // Find the smallest element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Update the index of the smallest element
            }
        }
        // Swap the found minimum element with the current element
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    const int size = 1000;  // Adjust the size of the array here
    vector<int> arr(size);
    
    srand(time(0));  // Use current time as seed for random number generation
    // Initialize the array with random values between 0 and 999
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }

    // Measure the time taken for sorting the array using Selection Sort
    auto start = high_resolution_clock::now();  // Start time
    selectionSortRandom(arr);  // Call selection sort function to sort the array
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);  // Calculate duration

    // Output the time taken to sort the array in microseconds
    cout << "Sorted array (Selection Random): " << duration.count() << " microseconds" << endl;

    return 0;
}