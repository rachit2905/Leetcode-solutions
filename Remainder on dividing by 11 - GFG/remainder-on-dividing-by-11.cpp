//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
       int rem=0;
       int i=0;
       while(i!=x.length())
       {
           string s1;
           if(rem==0)
            s1="";
            else
            s1=to_string(rem);
           s1+=x[i];
          while(stoi(s1)<11 && i<x.length()-1)
          {
              s1+=x[++i];
          }
          rem=stoi(s1)%11;
          
         // cout<<s1<<" ";
         i++;
       }
       return rem;
       
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends