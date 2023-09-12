//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
         if (N <= 1) {

        return 0; // Perfect numbers are always greater than 1.

    }

    

    long long sum = 1; // Start with 1 as a divisor.

    

    for (long long i = 2; i * i <= N; i++) {

        if (N % i == 0) {

            sum += i; // Add the divisor to the sum.

            if (i * i != N) {

                sum += N / i; // Add the corresponding divisor.

            }

        }

    }

    

    return sum == N;


    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends