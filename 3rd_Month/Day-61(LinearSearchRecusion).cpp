#include<iostream>
using namespace std;

bool LinearSearch(int Arr[], int n, int k)
{
    if(n == 0)
        return false;
    if(Arr[0] == k)
        return true;

    bool ans = LinearSearch(Arr+1, n-1, k);
    return ans;
}

int main()
{
    int Arr[8] = {3,2,5,6,1,7,10,9};
    bool ans = LinearSearch(Arr, 8, 12);
    if(ans)
        cout<<"Element Found "<<endl;
    else
        cout<<"Element Not Found" << endl;
    return 0;
}