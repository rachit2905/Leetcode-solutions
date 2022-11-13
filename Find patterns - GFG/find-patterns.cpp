//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool isSub(string W, string S, vector <int> &arr){
        int n = W.size(), m=S.size(), i=0, j=0;
        if(n>m)
            return 0;
        while(W[i]!='\0' && S[j]!='\0'){
            if(W[i]==S[j] && arr[j] == 0){
                arr[j] = 1;
                i++;
                j++;
            }
            else
                j++;
        }
        return W[i]=='\0';
    }
    int numberOfSubsequences(string S, string W){
        int n = S.size(), cnt = 0;
        vector <int> arr(n, 0);
        while(isSub(W, S, arr))
            cnt += 1;
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends