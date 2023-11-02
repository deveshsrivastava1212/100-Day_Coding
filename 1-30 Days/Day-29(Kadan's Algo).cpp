/*

Day- 29

Problem- Kadane's Algorithm

Problem Link- https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1?page=1&sortBy=submissions

Problem Statement-
                Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) 
                which has the maximum sum and return its sum.

                Example 1:

                Input:
                N = 5
                Arr[] = {1,2,3,-2,5}
                Output:
                9
                Explanation:
                Max subarray sum is 9
                of elements (1, 2, 3, -2, 5) which 
                is a contiguous subarray.


Function - */

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        long long int currSum = 0, maxSum= INT_MIN;
        for(int i=0;i<n;i++)
        {
            currSum += arr[i];
            maxSum = max(currSum, maxSum);
            if(currSum < 0)
                currSum = 0;
        }
        return maxSum;
    }
};

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
