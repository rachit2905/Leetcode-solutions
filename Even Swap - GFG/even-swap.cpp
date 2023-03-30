//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            vector<int>ans;
            vector<int>v1;
            v1.push_back(a[0]);
            for(int i=1;i<n;i++)
            {
                if(a[i]%2==v1[v1.size()-1]%2)
                v1.push_back(a[i]);
                else
                {
                    sort(v1.rbegin(),v1.rend());
                    for(auto it:v1)
                    ans.push_back(it);
                    v1.clear();
                    v1.push_back(a[i]);
                }
            }
            if(v1.size()>0)
            {
                sort(v1.rbegin(),v1.rend());
                for(auto it:v1)
                    ans.push_back(it);
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends