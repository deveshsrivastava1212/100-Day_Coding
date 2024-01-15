#include<iostream>
using namespace std;

bool reverseString(string& str, int i, int j)
{
    if(i>j)
        return 0;
    swap(str[i], str[j]);
    i++;
    j--;
    reverseString(str, i, j);
}

int main()
{
    string name = "DEVESH";
    reverseString(name, 0, name.length()-1);
    cout<<name<<endl;
    return 0;
}