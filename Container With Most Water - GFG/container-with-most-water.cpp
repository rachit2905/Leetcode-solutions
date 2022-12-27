//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    long long ans=0;
    int left=0,right=len-1;
    while(left<right)
    {
       long long temp=(right-left)*min(A[right],A[left]);
       ans=max(ans,temp);
       if(A[left]>A[right])right--;
       else left++;
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends