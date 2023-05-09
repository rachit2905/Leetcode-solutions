class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
    if (matrix.empty()) {
        return result;
    }
    
    int m = matrix.size(); 
    int n = matrix[0].size(); 
    
    int top = 0; 
    int bottom = m - 1; 
    int left = 0;
    int right = n - 1; 
    
    int totalElements = m * n; 
    int count = 0; 
    
    while (count < totalElements) {
        for (int i = left; i <= right && count < totalElements; ++i) {
            result.push_back(matrix[top][i]);
            count++;
        }
        top++;
        
        
        for (int i = top; i <= bottom && count < totalElements; ++i) {
            result.push_back(matrix[i][right]);
            count++;
        }
        right--;
        
        
        for (int i = right; i >= left && count < totalElements; --i) {
            result.push_back(matrix[bottom][i]);
            count++;
        }
        bottom--;
        
        
        for (int i = bottom; i >= top && count < totalElements; --i) {
            result.push_back(matrix[i][left]);
            count++;
        }
        left++;
    }
    
    return result;

    }
};