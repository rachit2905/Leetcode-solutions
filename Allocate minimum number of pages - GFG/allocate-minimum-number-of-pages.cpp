//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
        bool isvalid(int A[], int N, int M, int m)
        {

            int stucount=1, pages=0;

            for(int i=0;i<N;i++){

            if(A[i]>m) return false;

            if(pages+A[i]>m){

                stucount++;

                if(stucount>M) return false;

                pages=A[i];

            }else pages += A[i];

        }return true;

        }

 

    int findPages(int A[], int N, int M) 

    {

        // CODE

        if(M>N) return -1;

 

        long long ans=INT_MAX;

        // stl fucntion to find the sum of array

         int sum=accumulate(A,A+N,sum); 

        long long int l=A[N-1], h=sum, m;

        

        while(l<=h){

            m=l+(h-l)/2;

            if(isvalid(A, N, M, m)){ 

            ans=m;

            h=m-1;}

            else{

                l=m+1;

            }

        }

        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends