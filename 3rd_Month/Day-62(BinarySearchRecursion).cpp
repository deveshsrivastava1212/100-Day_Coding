#include<iostream>
using namespace std;

bool BinarySearch(int Arr[], int s, int e, int k)
{
    if(s>e)
        return false;
    int mid = s + (e-s)/2;
    if(Arr[mid] == k)
        return true;
    else if(Arr[mid] > k)
        return BinarySearch(Arr, s, mid-1, k);
    else
        return BinarySearch(Arr, mid+1, e, k);
}

int main()
{
    int Arr[8] = {3,2,5,6,1,7,10,9};
    bool ans = BinarySearch(Arr, 0, 7, 11);
    if(ans)
        cout<<"Element Found "<<endl;
    else
        cout<<"Element Not Found" << endl;
    return 0;
}