//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
          int res =0;

        int target = 0;

        int sum =0;

        vector<int> ps;

        for(int i=0;i<n;i++){

            sum += A[i];

            if(sum == 0)

            res = i+1;

            ps.push_back(sum);

        }

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){

            

            if(mp.find(ps[i]) != mp.end()){

                res = max( i - (mp.find(ps[i])->second), res);

            }

            

            mp.insert(make_pair(ps[i],i));

        }

        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends