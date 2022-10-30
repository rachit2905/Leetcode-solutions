//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	     long long int dp[n + 1];

     dp[0] = 0;

     dp[1] = 1;

     int pre = 0;

     long long int sum = 1;

     for(int i = 2; i <= n; i++){

         if(i >= 6) sum -= dp[pre++];

         dp[i] = sum * 2;

         sum += dp[i];

     }

     return sum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends