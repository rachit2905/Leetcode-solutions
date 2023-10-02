class Solution {
public:
    int minOperations(vector<int>& nums) {
         int count = 0;
        unordered_map <int, int> mp;
        for(auto i : nums) {
            mp[i]++;
        }
        for(auto i : mp) {
            if(i.second % 3 == 0) {
                count += i.second/3;
            }
            else if (i.second % 3 == 2) {
                count += i.second/3+1;
            }
            else if(i.second % 3 == 1 && i.second/3 > 1) {
                count += i.second/3+1;
            }
            else if (i.second % 2 == 0) {
                count += i.second/2;
            }
            else {
                return -1;
            }
        }
        return count;
    }
};