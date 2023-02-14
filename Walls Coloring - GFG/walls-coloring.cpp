//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        int x=colors[0][0],y=colors[0][1],z=colors[0][2];
        for(int i=1;i<N;i++)
        {
            int x1=colors[i][0]+min(y,z);
            int y1=colors[i][1]+min(x,z);
            int z1=colors[i][2]+min(x,y);
            x=x1,y=y1,z=z1;
        }
        return min({x,y,z});
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends