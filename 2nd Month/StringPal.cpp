#include<iostream>
#include<vector>
using namespace std;

bool checkPalindrome(char s[], int n)
{
    int beg=0, end = n-1;
    while(beg <= end){
        if(s[beg++] == s[end--])
            continue;
        else{
            return false;
        }
    }
    return true;
}

int getLength(char a[]){
    int count=0;
    for(int i=0; a[i]!='\0';i++)
        count++;
    return count;
}

int main()
{
    char arr[20];
    cout<<"Enter Your name: ";
    cin>>arr;
    int len = getLength(arr);
    bool value = checkPalindrome(arr,len);
    if(value==1)
        cout<<"\nString is Palindrome";
    else    
        cout<<"\nString is not Palindrome";
    return 0;
}