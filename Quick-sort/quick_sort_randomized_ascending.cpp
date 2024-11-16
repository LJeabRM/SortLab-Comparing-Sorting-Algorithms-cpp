#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>  // สำหรับ rand() และ srand()
#include <ctime>    // สำหรับ time()

using namespace std;
using namespace chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int randomizedPartition(vector<int>& arr, int low, int high) {
    // สุ่มเลือก pivot
    int randomPivotIndex = low + rand() % (high - low + 1);
    swap(arr[randomPivotIndex], arr[high]);  // สลับ pivot สุ่มกับตำแหน่งสุดท้าย
    return partition(arr, low, high);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);  // ใช้ randomizedPartition แทน
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int size = 20000;  // ขนาด array
    vector<int> arr(size);
    
    // กำหนดข้อมูลเรียงจากน้อยไปมาก
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    // ตั้งค่า seed สำหรับ random
    srand(time(0));

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted array (Ascending) in: " << duration.count() << " microseconds" << endl;

    return 0;
}
