/*
    Day - 58

    Problem Link - https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1?page=1&sprint=94ade6723438d94ecf0c00c3937dad55&sortBy=submissions

    Problem Statement - 

    Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. There can be duplicate elements.

    Example 1:

    Input:
    a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
    a2[] = {11, 3, 7, 1, 7}
    Output:
    Yes
    Explanation:
    a2[] is a subset of a1[]

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++)
    {
        mp[a1[i]]++;
    }
    
    for(int i=0; i<m; i++)
    {
        if(mp[a2[i]] <=0)
            return "No";
        mp[a2[i]]--;
    }
    return "Yes";
}