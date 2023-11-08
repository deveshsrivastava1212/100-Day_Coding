/*
    Day- 35

    Problem - Longest Subarray with 0 sum
    Problem Link- https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?page=1&sprint=a663236c31453b969852f9ea22507634&sortBy=submissions

    Problem Statement- 
            Given an array having both positive and negative integers. The task is to compute the 
            length of the largest subarray with sum 0.

            Example 1:

            Input:
            N = 8
            A[] = {15,-2,2,-8,1,7,10,23}
            Output: 5
            Explanation: The largest subarray with
            sum 0 will be -2 2 -8 1 7.
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int maxi = 0;
        int sum = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += A[i];
            if(sum == 0)
                maxi = i+1;
            else
            {
                if(mp.find(sum) != mp.end())
                    maxi = max (maxi, i - mp[sum]);
                else
                    mp[sum] = i;
            }
        }
        return maxi;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}