//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool checker(string temp){
      int i=0,j=temp.length()-1;
      while(i<=j){
          if(temp[i]!=temp[j]){
              return 0;
          }
          i++;
          j--;
      }
      return 1;
  }
  void helper(int ind,string &s,vector<vector<string>>&res,vector<string>&t1){
      int n=s.length();
      if(ind==n){
          res.push_back(t1);
          return;
      }
      for(int i=ind ; i<n ; i++){
          string temp=s.substr(ind,i-ind+1);
          if(checker(temp)){
              t1.push_back(temp);
              helper(i+1,s,res,t1);
              t1.pop_back();
          }
      }
      return ;
  }
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<vector<string>>res;
        vector<string>t1;
        helper(0,s,res,t1);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends