//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
            int arr[]={1,2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int>ans;
        int i=9; // I will traverse from backside
        while(N){
            if(arr[i]<=N){ //whenever I find a coin is equal or less than remaining money
                N-=arr[i]; // I will deduct it
                ans.push_back(arr[i]); //I will push the coin
            }
            else // move to the next coin (previous as backside)
                i--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends