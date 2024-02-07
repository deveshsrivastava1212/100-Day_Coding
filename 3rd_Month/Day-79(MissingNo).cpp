//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& a, int n) {
        // Your code goes here
        long long arraySum = 0;
    for (int num : a) {
        arraySum += num;
    }

    // Calculate the sum of the first N natural numbers
    long long expectedSum = (long long)n * (n + 1) / 2;

    // The missing number is the difference between the expected sum and the actual sum
    return expectedSum - arraySum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends