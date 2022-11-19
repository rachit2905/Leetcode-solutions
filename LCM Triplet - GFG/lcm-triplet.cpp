//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long lcmTriplets(long long N) {
        // code here
        if(N==2)return 2;
        else if(N==1)return 1;
        if(N%2==0)
        {
            long long lcm1=(N)*(N-1)/__gcd(N,N-1);
            long long lcm2=(N-1)*(N-2)/__gcd(N-1,N-2);
            return max((N-3)*lcm1/__gcd(N-3,lcm1),(N-3)*lcm2/__gcd(N-3,lcm2));
        }
        else
        {
             long long lcm1=(N)*(N-1)/__gcd(N,N-1);
             return (N-2)*lcm1/__gcd(lcm1,N-2);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends