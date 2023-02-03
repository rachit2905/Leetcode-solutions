//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        int i1=0,j1=1,i=0,j=0;
        while(i<R && j<C && i>=0 && j>=0)
        {
          if(matrix[i][j]==0)
          {
              i+=i1;j+=j1;
          }
          else if(matrix[i][j]==1)
          {
              matrix[i][j]=0;
              if(i1==0 && j1==1)
              {
                  i1=1,j1=0;
              }
              else if(i1==-1 && j1==0)
              {
                  i1=0,j1=1;
              }
              else if(i1==1 && j1==0)
              {
                  i1=0,j1=-1;
              }
              else
              i1=-1,j1=0;
          }
        }
       return {i-i1,j-j1};
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends