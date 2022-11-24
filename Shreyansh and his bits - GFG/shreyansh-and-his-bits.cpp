//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
class Solution{
public:
    long long k(int x, int y)
{
    if(x<y)return 0;
    int diff = x-y;
    long long res = 1;
    for(int i=1; i<=diff; i++)
    {
        res=(x-i+1)*res/i;
    }
    return res;
}
long long count(long long a){
    long long co=0;
    string s;
    bitset<64>x(a);
    s=x.to_string();
    int ones=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            ones++;
            co+=k(s.size()-i-1,ones);
        }
    }
    return co;
}
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends