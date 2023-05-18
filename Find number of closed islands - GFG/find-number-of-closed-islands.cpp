//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
     vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};
    void dfs(int i, int j, vector<vector<int>> &matrix, int &n, int &m){
        
        matrix[i][j]=-1;
        
        for(int k=0;k<4;k++){
            
            int x = i+dx[k];
            int y = j+dy[k];
            
            if(x>=0 and y>=0 and x<n and y<m and matrix[x][y]==1){
                dfs(x,y,matrix,n,m);
            }
            
        }
        
        
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
       
        int count=0;
        vector<vector<int>> vis(N+1, vector<int>(M+1,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                
                if(i==0 or j==0 or i==N-1 or j==M-1){
                    if(matrix[i][j]==1){
                        dfs(i,j,matrix,N,M);
                    }            
                }
                
            }
        }
        
        for(int i=1;i<N;i++){
            for(int j=1;j<M;j++){
                
                if(matrix[i][j]==1){
                    dfs(i,j,matrix,N,M);
                    count++;
                }
                
            }
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends