//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int columnNumber)
    {
        // your code here
          map<int,char>m1;
        char c='A';
        for(int i=1;i<=26;i++)
        {
            m1[i]=c;
            c++;
        }
        string ans="";
        while(columnNumber)
        {
            int x=columnNumber%26;
            if(x==0)
            {
                ans=m1[26]+ans;columnNumber--;
            }
            else
            ans=m1[x]+ans;
            columnNumber/=26;
            
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
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends