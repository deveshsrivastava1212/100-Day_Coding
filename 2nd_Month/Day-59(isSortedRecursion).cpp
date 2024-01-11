#include<iostream>
using namespace std;

bool isSorted(int *ar, int n)
{
    if(n == 0 || n == 1)
        return true;
    
    if( ar[0] > ar[1] )
        return false;

    else{
        bool remainingPart = isSorted(ar+1, n-1);
        return remainingPart;
    }
}

int main()
{
    int Ar[8] = {3,6,8,10,12,15,20,25};
    bool ans = isSorted(Ar, 8);
    if(ans)
        cout<<"Array is Sorted"<<endl;
    else
        cout<<"Array is not Sorted"<<endl;

    return 0;
}