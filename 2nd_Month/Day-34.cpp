/* Day-34

    Problem- Maximum Occuring Character
    Problem Link- https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

    Problem Statement- 
    Given a string str of lowercase alphabets. The task is to find 
    the maximum occurring character in the string str. If more than 
    one character occurs the maximum number of time then print the 
    lexicographically smaller character.

    Example 1:

    Input:
    str = testsample
    Output: e
    Explanation: e is the character which
    is having the highest frequency.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        map<char,int> mp;
        char ans=' ';
        int count=0;
        
        if(str.length()==1)
        {
            ans = str[0];
            return ans;
        }
        
        for(int i=0; i<str.length(); i++)
        {
            mp[str[i]]++;
            
            if(mp[str[i]] > count)
            {
                count = mp[str[i]];
                ans = str[i];
            }
        }
        // for(auto i: mp)
        //     std::cout<<i.first<<": "<<i.second<<" ,";
        for (auto i : mp)
        {
            if (i.second == count)
            {
                ans = i.first;
                break;
            }
        }
        
        return ans;
    }
};

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}