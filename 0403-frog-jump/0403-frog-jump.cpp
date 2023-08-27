class Solution {
public:
    bool solve(vector<int> &stones, int index, unordered_map<int,int> &mp, int prev, vector< vector<int> > &dp){
        if(index == stones.size()-1){
            return true;
        }
        if(index > stones.size()) return false;

        if(dp[index][prev] != -1) return dp[index][prev];

        bool one = false, two = false, three = false;
        int p = stones[index] - stones[prev];

        if(index == 0){
          
          one = solve(stones, 1, mp, 0 , dp);
        }
        else{
            if(mp.find(stones[index] + p) != mp.end())
            one = solve(stones, mp[stones[index]+p], mp, index, dp);

            if(mp.find(stones[index] + p + 1) != mp.end()){
                two  = solve(stones, mp[stones[index] + p + 1],mp, index ,dp);
            }

            if(mp.find(stones[index] + p -1) != mp.end() && p-1 != 0){
                three  = solve(stones, mp[stones[index] + p -1], mp,index, dp);
            }
        }

        return dp[index][prev] = one || two || three;

    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        unordered_map<int,int> mp;
        for(int i = 0; i<stones.size(); i++){
            mp[stones[i]] = i;
        }

        vector< vector<int> > dp(stones.size(), vector<int> (stones.size() + 1, -1));


        return solve(stones, 0, mp, 0, dp);
    }
};