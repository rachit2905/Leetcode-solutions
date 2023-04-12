//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int>m1;
    int i=0,sz=INT_MIN;
    for(int j=0;j<s.length();j++)
    {
        m1[s[j]]++;
        while(m1.size()>k)
        {
            m1[s[i]]--;
            if(m1[s[i]]==0)m1.erase(m1.find(s[i]));
            i++;
            
        }
        if(m1.size()==k)
        sz=max(sz,j-i+1);
    }
    if(sz==INT_MIN)return -1;
    else return sz;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends