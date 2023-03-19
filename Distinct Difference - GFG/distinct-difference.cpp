//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
       vector<int>res(N,0);
        
        unordered_set<int>st1;
        unordered_map<int,int>mp1;
        for(int i = 0;i<N;i++){
            mp1[i] = st1.size();
            st1.insert(A[i]);
            
        }
        
        unordered_set<int>st2;
        unordered_map<int,int>mp2;
          for(int i = N-1;i>=0;i--){
            mp2[i] = st2.size();
            st2.insert(A[i]);
            
        }
          for(int i = 0;i<N;i++){
           res[i] = mp1[i]-mp2[i];
            
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends