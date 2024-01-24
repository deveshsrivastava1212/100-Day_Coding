#include <iostream>
#include <vector>

void swap(std::vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Recursive function to find the index of the minimum element in the unsorted part
int findMinIndex(std::vector<int>& arr, int start, int size) {
    if (start == size - 1) {
        return start;
    }

    int minIndex = findMinIndex(arr, start + 1, size);

    return (arr[start] < arr[minIndex]) ? start : minIndex;
}

// Recursive function to perform selection sort
void selectionSortHelper(std::vector<int>& arr, int start, int size) {
    if (start == size) {
        return; // Base case: array is sorted
    }

    int minIndex = findMinIndex(arr, start, size);

    if (minIndex != start) {
        swap(arr, start, minIndex);
    }

    selectionSortHelper(arr, start + 1, size);
}

void selectionSort(std::vector<int>& arr) {
    selectionSortHelper(arr, 0, arr.size());
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    selectionSort(arr);

    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
