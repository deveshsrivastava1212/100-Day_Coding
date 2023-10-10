// Day-4

// Problem- Subarray with given sum

// Problem Link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&difficulty[]=0&category[]=Arrays&sprint=a663236c31453b969852f9ea22507634&sortBy=submissions

// Problem Statement- 
//     Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array 
//     that adds to a given number S and return the left and right index(1-based indexing) of that subarray.
//     In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

//     Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray 
//     exists return an array consisting of element -1.

//     Example 1:

//     Input:
//     N = 5, S = 12
//     A[] = {1,2,3,7,5}
//     Output: 2 4
//     Explanation: The sum of elements 
//     from 2nd position to 4th position 
//     is 12.  

//code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> ans;
        int l = 0;
        int r = 0;
        int sum = arr[0];
        bool isFound = false;
        
        
        while(r<n)
        {
            if(sum == s){
                isFound = true;
                break;
            }
            else if(sum<s)
            {
                r++;
                if(r<n)
                    sum += arr[r];
            }
            else{
                sum -= arr[l];
                l++;
            }
        }
        if(s==0 || !isFound){
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(l+1);
        ans.push_back(r+1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int n;
    long long s;
    cin>>n>>s;
    vector<int>arr(n);
    // int arr[n];
    const int mx = 1e9;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Solution ob;
    vector<int>res;
    res = ob.subarraySum(arr, n, s);
    
    for(int i = 0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
    
return 0;
}
