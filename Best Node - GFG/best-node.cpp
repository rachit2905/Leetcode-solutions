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
    long long bestNode(int n, vector<int> &A, vector<int> &P) {
        // code here
        set<int>s1;vector<int>leaves;
        for(auto it:P)
        s1.insert(it);
       long long int ans=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(s1.find(i)==s1.end())
            {
             leaves.push_back(i);
            }
        }
        for(auto it:leaves)
        {
            int curr=it;long long sum=0;
            while(curr!=-1)
            {
                sum=-sum;
                sum+=A[curr-1];
                ans=max(ans,sum);
                 curr=P[curr-1];
            }
        }
        return ans;
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
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends