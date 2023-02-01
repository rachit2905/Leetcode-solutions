//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
   static bool cmp(vector<int>&v,vector<int>&v2)
    {
        if(v[0]!=v2[0])return v[0]<v2[0];
        else if(v[1]!=v2[1])return v[1]>v2[1];
        else return v[2]<v2[2];
    }
    void customSort (int phy[], int chem[], int math[], int N)
    {
        // your code here
        vector<vector<int>>v1;
        for(int i=0;i<N;i++)
        {
            v1.push_back({phy[i],chem[i],math[i]});
        }
        sort(v1.begin(),v1.end(),cmp);
        for(int i=0;i<N;i++)
        {
           phy[i]=v1[i][0];
           chem[i]=v1[i][1];
           math[i]=v1[i][2];
        }
    } 
};

//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i] >> chem[i] >> math[i];
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends