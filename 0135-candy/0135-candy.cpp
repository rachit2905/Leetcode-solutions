class Solution {
public:
    int candy(vector<int>& ratings) {
         vector<int> allocation(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++) {
            if(i > 0 && ratings[i] > ratings[i-1]) {
                allocation[i] = allocation[i-1] + 1;
            }
        }
        for(int i = ratings.size()-1; i >= 0; i--) {
            if((i < ratings.size() - 1 && ratings[i] > ratings[i+1]) && (allocation[i] <= allocation[i+1])) {
                allocation[i] = allocation[i+1] + 1;
            }
        }
        return accumulate(allocation.begin(), allocation.end(), 0);
    
    }
};