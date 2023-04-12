//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int nums[], int n, int k) {
        // code here
           int ans=0,i=0,j=0,ze=0,sz=INT_MIN;
        for(j=0;j<n;j++)
        {
           if(nums[j]==1)ze++;
           if(j-i+1-ze>k)
           {
               if(nums[i]==1)
                   ze--;
               i++;
           }
            sz=max(sz,j-i+1);
            
            
        }
        return sz;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends