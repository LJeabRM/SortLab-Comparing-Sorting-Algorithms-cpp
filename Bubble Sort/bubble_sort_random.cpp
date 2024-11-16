#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Function to perform Bubble Sort (ascending order) on a random array
void bubbleSortRandom(vector<int>& arr) {
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
    
    srand(time(0));  // Use the current time as seed for random number generation
    // Initialize the array with random values between 0 and 39999
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 40000;  // Random numbers between 0 and 39999
    }

    // Measure the time taken for sorting the array using Bubble Sort
    auto start = high_resolution_clock::now();  // Start time
    bubbleSortRandom(arr);  // Call bubble sort function to sort the array
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);  // Calculate duration

    // Output the time taken to sort the array in microseconds
    cout << "Sorted array (Random): " << duration.count() << " microseconds" << endl;

    return 0;
}
