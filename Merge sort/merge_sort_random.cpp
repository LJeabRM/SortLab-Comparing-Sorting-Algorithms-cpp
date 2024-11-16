#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Function to merge two halves of the array during merge sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left half
    int n2 = right - mid;     // Size of the right half
    vector<int> L(n1), R(n2); // Temporary arrays for left and right halves

    // Copy data into temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    
    // Merge the two halves back into the original array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {  // Sort in ascending order
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement the merge sort algorithm
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively divide the array into two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
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

    // Measure the time taken for sorting the array using merge sort
    auto start = high_resolution_clock::now();  // Start time
    mergeSort(arr, 0, arr.size() - 1);  // Call mergeSort function to sort the array
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);  // Calculate duration

    // Output the time taken to sort the array in microseconds
    cout << "Sorted array (Random): " << duration.count() << " microseconds" << endl;

    return 0;
}
