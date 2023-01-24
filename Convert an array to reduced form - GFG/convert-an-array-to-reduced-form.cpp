//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	multimap<int,int>m1;
	void convert(int arr[], int n) {
	    // code here
	    for(int i=0;i<n;i++)
	    {
	        m1.insert({arr[i],i});
	    }
	    int k=0;
	    for(auto it:m1)
	    {
	        arr[it.second]=k;
	        k++;
	    }
	    //return arr;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends