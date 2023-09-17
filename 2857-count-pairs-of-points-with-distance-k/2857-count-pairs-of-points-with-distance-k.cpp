class Solution {
public:
    int countPairs(vector<vector<int>>& c, int k) {
        map<pair<int,int>,int>mp;
        int n = c.size();

        for(int i=0;i<n;i++){
                mp[{c[i][0],c[i][1]}]++;
        }
        long res = 0;
        for(int i=0;i<n;i++){
            for(int j= 0;j<=k;j++){
                int a = c[i][0] ^ j;
                int b =  c[i][1] ^ (k-j);
                if(mp.find({a,b})!=mp.end()){
                    if(a==c[i][0] && b==c[i][1]){
                        res--;
                    }
                    res += mp[{a,b}];
                    
                }
            }
        }
        return res/2;
    }
};