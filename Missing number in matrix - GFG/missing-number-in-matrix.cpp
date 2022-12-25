//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
             int n=matrix.size(),x,y;
        vector<long long int> r(n,0),c(n,0);
        long long int d1=0,d2=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                r[i]+=matrix[i][j];
                c[i]+=matrix[j][i];
                if(j==i) {
                    d1+=matrix[i][j];
                }
                if(j==n-i-1) {
                    d2+=matrix[i][j];
                }
                if(matrix[i][j]==0) {
                    x=i;
                    y=j;
                }
            }
        }
        
        map<long long int , int> mpr;
        for(int i=0;i<n;i++)mpr[r[i]]++;
        map<long long int , int> mpc;
        for(int i=0;i<n;i++)mpc[c[i]]++;
        
        auto itr = mpr.begin();
        auto itc = mpc.begin();
        if((*itr).second != 1 or mpr.size()!=2)return -1;
        if((*itc).second != 1 or mpc.size()!=2)return -1;
        itr++;
        long long int res = (*itr).first - (*itc).first; 
        
        if( x==y and (n%2==1 and x==n/2 )){
            if(d1==d2  and d1==(*itc).first)
            return res;
            else return -1;
        }
        else if( x==y){
            if(d1==(*itc).first and d2==(*itr).first)
                return res;
            else return -1;
            
        }
        else if( x==n-y-1){
            if(d1==(*itr).first and d2==(*itc).first)
                return res;
            else return -1;
        }
        else return res;   
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends