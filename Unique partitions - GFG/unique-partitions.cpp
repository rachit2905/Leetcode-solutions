//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	 vector<vector<int>>ans;
	 vector<int>curr;
	void help(int n,int i)
	{
	    if(n==0)
	    {
	    ans.push_back(curr);return;}
	    if(i<1)return;
	    if(i<=n)
	    {
	        curr.push_back(i);
	        help(n-i,i);
	        curr.pop_back();
	        help(n,i-1);
	    }
	    else
	    {
	        help(n,i-1);
	    }
	}
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
       
        help(n,n);return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends