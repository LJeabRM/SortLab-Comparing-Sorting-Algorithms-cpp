#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Partition function that uses a randomly chosen pivot
int partition(vector<int>& arr, int low, int high) {
    // Randomly select a pivot from the range [low, high]
    int random_pivot = low + rand() % (high - low + 1);
    
    // Swap the randomly chosen pivot with the last element
    swap(arr[random_pivot], arr[high]);

    int pivot = arr[high];  // Use the last element as pivot after swapping
    int i = (low - 1);

    // Rearrange the array by moving elements smaller than pivot to the left
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  // Move the pivot to its correct position
    return (i + 1);
}

// QuickSort function that calls partition with a random pivot
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Get the partition index
        quickSort(arr, low, pi - 1);  // Recursively sort the left subarray
        quickSort(arr, pi + 1, high);  // Recursively sort the right subarray
    }
}

int main() {
    const int size = 20000;  // Array size
    vector<int> arr(size);
    
    srand(time(0));  // Use current time as seed for random number generation
    // Initialize the array with random values between 0 and 19999
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 20000;  // Random numbers between 0 and 19999
    }

    // Measure the time taken for sorting the array using QuickSort with a random pivot
    auto start = high_resolution_clock::now();  // Start time
    quickSort(arr, 0, arr.size() - 1);  // Call quickSort function to sort the array
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);  // Calculate duration

    // Output the time taken to sort the array in microseconds
    cout << "Sorted array (Randomized Pivot): " << duration.count() << " microseconds" << endl;

    return 0;
}
