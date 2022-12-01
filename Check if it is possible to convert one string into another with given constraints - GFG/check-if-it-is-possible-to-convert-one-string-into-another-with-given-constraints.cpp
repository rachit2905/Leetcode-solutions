//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
         if(N != M)return 0;
        int i = 0,j = 0;
        while(i < N)
        {
            if(S[i] != '#')
            {
                while(j < N and T[j] == '#')j++;
                if(j == N or T[j] != S[i])return 0;
                j++;
            }
            i++;
        }
        while(j < N and T[j] == '#')j++;
        return j < N ? 0 : 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends