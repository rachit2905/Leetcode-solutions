//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        // Code here
        long long ans=0;
        while(N)
        {
            long long rank=N%5;
            N/=5;
            if(rank==0)
            {
                rank=5;
                N--;
            }
            ans=ans*10+(2*rank-1);
        }
        return reverse(ans);
    }
    long long reverse(long long N)
    {
        long long ans=0;
        while(N)
        {
            ans=ans*10+N%10;
            N/=10;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends