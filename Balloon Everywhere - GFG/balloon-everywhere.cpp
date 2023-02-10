//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        string s1="balloon";
        map<char,int>m1;
        for(auto it:s)
        {
            m1[it]++;
        }
        int ans=0;
        while(true)
        {
            for(auto it:s1)
            {
                if(m1.find(it)==m1.end())
                {
                    return ans;
                }
                else
                {
                    if(m1[it]==0)return ans;
                    m1[it]--;
                    
                }
            }
            ans++;
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends