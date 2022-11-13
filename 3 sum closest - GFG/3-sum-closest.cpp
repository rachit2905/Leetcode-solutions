//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int a[], int n, int r)
    {
        // code here
        sort(a,a+n);
        int mx=INT_MAX;
        int sum, re;
        for(int i=0;i<n;i++){
            int s=i+1;int e=n-1;
            while(s<e){
                sum=a[s]+a[e]+a[i];
                if(mx>abs(sum-r)){
                       mx=min(abs(sum-r),mx);
                       re=(sum-r);
                }
                if((sum-r)>0){
                    e--;   
                }
                else{
                 s++;   
                }   
            }
        }
        return re+r;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends