//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        int x=1,y=1;
        if(n==1)return x;
        else if(n==2)return y;
        int z=0;
        for(int i=3;i<=n;i++)
        {
             z=(x%1000000007+y%1000000007)%1000000007;
            x=y;
            y=z;
        }
        return z;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends