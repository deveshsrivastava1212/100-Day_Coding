#include<iostream>
#include<vector>
using namespace std;

void Merge (int *arr, int s, int e)
{
    int mid = (s+e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *firstAr = new int[len1];
    int *secondAr = new int[len2];

    //copy the value
    int MainIndex = s;
    for(int i=0; i<len1; i++)
        firstAr[i] = arr[MainIndex++];

    MainIndex = mid+1;
    for(int i=0; i<len2; i++)
        secondAr[i] = arr[MainIndex++];

    //Merge two sorted array
    int index1 = 0, index2 = 0;
    MainIndex = s;
    while(index1 < len1 && index2 < len2)
    {
        if(firstAr[index1] < secondAr[index2])
            arr[MainIndex++] = firstAr[index1++];
        else   
            arr[MainIndex++] = secondAr[index2++];
    }

    while(index1 < len1)
        arr[MainIndex++] = firstAr[index1++];
    
    while(index2 < len2)
        arr[MainIndex++] = secondAr[index2++];
}

void MergeSort(int *arr, int s, int e){
    
    if(s>=e)
        return;
    
    int mid = (s+e)/2;

    //sort the left part
    MergeSort(arr, s, mid);
    
    //sort the right part
    MergeSort(arr, mid+1, e);

    //Merge
    Merge(arr, s, e);
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    MergeSort(arr, 0, 4);

    cout << "\nSorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;

}