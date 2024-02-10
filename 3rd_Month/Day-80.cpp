//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            map<char,int> mp1;
            map<char,int> mp2;
            string ans;
            
            for(int i=0; i<A.length(); i++)
                mp1[A[i]]++;
                
            for(int i=0; i<B.length(); i++)
                mp2[B[i]]++;
                
            for(int i=0; i<B.length(); i++)
            {
                if(mp1.find(B[i]) == mp1.end())
                    ans.push_back(B[i]);
            }
            for(int i=0;i<A.length(); i++)
            {
                if(mp2.find(A[i]) == mp2.end())
                    ans.push_back(A[i]);
            }
            if(ans.length() > 0){
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end());
            return ans;
            }
            return "-1";
        } 
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends