//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int ans = 0, len = 0;
           int nc = 0;
           for(int i = 0;i<n;i++)
           {
                nc = nc + (arr[i] < 0);
                len++;
                if(nc%2 == 0 && arr[i] != 0)
                    ans = max(ans, len);
                if(arr[i] == 0)
                {
                    nc = 0;
                    len = 0;
                }
           }
           len = 0;
           nc = 0;
           for(int i = n-1;i>=0;i--)
           {
                nc = nc + (arr[i] < 0);
                len++;
                if(nc%2 == 0 && arr[i] != 0)
                    ans = max(ans, len);
                if(arr[i] == 0)
                {
                    nc = 0;
                    len = 0;
                }
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends