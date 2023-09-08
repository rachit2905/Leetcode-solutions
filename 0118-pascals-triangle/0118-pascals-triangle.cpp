class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> result;

       for(int row=1;row<=numRows;row++){
            vector<int> ans;
            ans.push_back(1);
            long long prod=1;
           for(int col=1;col<row;col++){
               prod=prod*(row-col);
               prod=prod/(col);
               ans.push_back(prod);
           }
           result.push_back(ans);
       }
       return result;
    }
};