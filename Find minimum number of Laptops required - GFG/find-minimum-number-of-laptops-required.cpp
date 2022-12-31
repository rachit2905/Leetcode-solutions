//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int n, int start[], int end[]) {
        // Code here
        vector<pair<int,int>>v1;
        for(int i=0;i<n;i++)
        {
            v1.push_back({start[i],1});
            v1.push_back({end[i],-1});
        }
        sort(v1.begin(),v1.end());
        int ans=0,sum=0;
        for(auto it:v1)
        {
            sum+=it.second;
            ans=max(ans,sum);
        
           }
           return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends