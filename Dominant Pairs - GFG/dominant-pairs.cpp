//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        int ans=0;
       sort(arr.begin(),arr.begin()+n/2);
       sort(arr.begin()+(n/2),arr.end());
       int i=0,j=n/2,k=0;
       while(i<n/2 && j<n)
       {
           if(i>0)ans+=k;
           while(j<n && arr[i]>=5*arr[j])
           {
               j++;k++;
               ans++;
           }
          
          
           i++;
       }
       //cout<<k<<" "<<i;
       while(i<n/2)
       {
           ans+=k;
           i++;
       }
      // for(auto it:arr)cout<<it<<" ";
       return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends