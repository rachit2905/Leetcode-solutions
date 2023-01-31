//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        // Your code here
     vector<vector<int>> ans;

        int i=0;

        

        for(int j=0;j<n && i<n;j++){

            vector<int> temp;

            int k=0;

            

            while(k<pow(2,j) && i<n){

                temp.push_back(arr[i]);

                i++;

                

                k++;

            }

            sort(temp.begin(),temp.end());

            ans.push_back(temp);

            

        }

        return ans;

    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;
        
		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends