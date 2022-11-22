//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool check(int x){
       for (int i=2; i<x/2; i++){
           if (x%i==0){
               return false;
           }
       }
       return true;
   }

    vector<int> primeDivision(int n){
        // code here
        for (int i=2; i<n; i++){
            if (check(i)){
                if (check(n-i)){
                    return {i,n-i};
                }
            }
        }
        return {-1,-1};
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends