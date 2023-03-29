//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        int ans=0;
        for(int i=0;i<S.length();i++)
        {
            int lo=0,hi=0;
            if(S[i]>=65 && S[i]<=90)hi++;
            else lo++;
            for(int j=i+1;j<S.length();j++)
            {
                if(S[j]>=65 && S[j]<=90)hi++;
            else lo++;
            if(hi==lo && hi!=0)
            ans++;
            }
            
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends