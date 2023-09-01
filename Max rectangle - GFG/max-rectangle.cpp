//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxHist(int row[],int C)
{
    stack<int> result;
 
    int top_val; // Top of stack
 
    int max_area = 0; // Initialize max area in current
    // row (or histogram)
 
    int area = 0; 
    int i = 0;
    while (i < C) {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
 
        else {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
 
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
 
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
 
        max_area = max(area, max_area);
    }
    return max_area;
}
 
int maxArea(int A[1000][1000],int R,int C)
{
    int result = maxHist(A[0],C);
 
    for (int i = 1; i < R; i++) {
 
        for (int j = 0; j < C; j++)
 
            // if A[i][j] is 1 then add A[i -1][j]
            if (A[i][j])
                A[i][j] += A[i - 1][j];
 
        result = max(result, maxHist(A[i],C));
    }
 
    return result;
}
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends