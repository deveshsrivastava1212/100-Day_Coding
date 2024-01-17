#include<iostream>
#include<vector>
using namespace std;

int partition (int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++)
    {
        if(arr[i] <= pivot)
            count ++;
    }

    //place pivot element ar right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] < pivot)
            i++;

        while(arr[i] > pivot)
            j--;
        
        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s>=e)
        return;

    //partition
    int pi = partition(arr, s, e);

    //Sort for left
    quickSort(arr, s, pi-1);

    //sort for right part
    quickSort(arr, pi+1, e);

}

int main()
{
    int arr[5] = {64, 25, 12, 22, 11};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    quickSort(arr, 0, 4);

    cout << "\nSorted array: ";
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";

    return 0;

}