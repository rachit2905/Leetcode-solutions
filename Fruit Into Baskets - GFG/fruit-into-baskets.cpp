//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int help(vector<int>&s, int k) {
    // your code here
    unordered_map<int,int>m1;
    int i=0,sz=INT_MIN;
    for(int j=0;j<s.size();j++)
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
    if(sz==INT_MIN)return s.size();
    else return sz;
    }
    int totalFruits(int N, vector<int> &fruits) {
        return help(fruits,2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends