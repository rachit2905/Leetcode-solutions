//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    static  bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
 
        return a.first/(1.0*a.second) <= b.first/(1.0*b.second);
    }
    int countFractions(int n, int numerator[], int denominator[])
    {
   
        map<pair<int,int>,int> mp;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int t=__gcd(numerator[i],denominator[i]);
            int a=numerator[i]/t,b=denominator[i]/t;
            mp[{a,b}]++;

        }
        
        for(auto &it:mp)
        {
            int u=it.first.first,v=it.first.second;
          
            if(u!=v)
            {
                
            int a=v-u,b=v;
              if(a==u)
                  ans+=((mp[{a,v}]-1)*mp[{a,b}]);
                else
                ans+=(mp[{a,v}]*mp[{u,v}]);
            }
        }
        return ans/2;
        
        
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends