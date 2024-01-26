#include<iostream>
#include<stack>
using namespace std;

string reverseString(string& s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        st.push(s[i]);
    }
    string ans="";
    while(!st.empty()){
        char ch=st.top();
        ans.push_back(ch);
        st.pop();
    }
    return ans;
}

int main()
{
    string s="";
    cout<<"Enter the string : ";
    cin>>s;
    string ans = reverseString(s);
    cout<<"Reversed String: "<<ans<<endl;
    return 0;
}