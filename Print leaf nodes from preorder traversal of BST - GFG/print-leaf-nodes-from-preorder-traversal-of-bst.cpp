//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int in[],int N) {
        // code here

        
           vector<int> ans;
         if(N == 1){
             ans.push_back(in[0]);
             return ans;
         }
        vector<int> pre;
        
        unordered_map<int, int> hash;
        
        for(int i = 0; i<N; i++){
            pre.push_back(in[i]);
        }
        
        sort(in, in+N);
        
        for(int i = 0; i<N; i++)
            hash[in[i]] = i;
        
        for(int i = 0; i<N; i++){
            if(hash[pre[i]] == 0 and in[hash[pre[i]]+1] == -1){
                ans.push_back(in[hash[pre[i]]]);
            }
            else if(hash[pre[i]] == N-1 and in[hash[pre[i]]-1] == -1){
                ans.push_back(in[hash[pre[i]]]);
            }
            else if(in[hash[pre[i]]+1] == -1 && in[hash[pre[i]]-1] == -1){
                ans.push_back(in[hash[pre[i]]]);
            }
            else
                in[hash[pre[i]]] = -1;
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends