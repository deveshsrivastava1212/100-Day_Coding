#include<iostream>
using namespace std;

int Sum_all(int Arr[], int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    int sum = Arr[0] + Sum_all(Arr+1, n-1);
    return sum;
}

int main()
{
    int Arr[5] = {3,2,5,6,1};
    cout<< Sum_all(Arr, 5);
    return 0;
}