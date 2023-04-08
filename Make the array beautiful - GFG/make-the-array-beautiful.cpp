//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
          int n=arr.size();
        vector<int> ans;
        int neg=0,pos=0;
       
        for(int i=0;i<n;i++){
           ans.push_back(arr[i]);
           int x=ans.size();
           if(x>1){
               
               if((ans[x-1]<0 and ans[x-2]>=0)  or (ans[x-1]>=0 and ans[x-2]<0)){
               ans.pop_back();
               ans.pop_back();}
               
           }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends