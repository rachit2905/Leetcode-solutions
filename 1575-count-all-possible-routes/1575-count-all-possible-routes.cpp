const int mod = 1e9 + 7;
class Solution {
public:
    long dp[101][201];
    long fun(int city, int fuel, int start, int finish, vector<int>& locations, int n){
        if(dp[city][fuel] != -1) return dp[city][fuel];
        long res = city == finish;
        for(int nextCity = 0; nextCity < n; nextCity++){
            if(nextCity == city or fuel < abs(locations[nextCity] - locations[city])) continue;
            res = (res + fun(nextCity, fuel-abs(locations[nextCity]-locations[city]), start, finish, locations, n)) % mod;
        }
        return dp[city][fuel] = res % mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        int n = locations.size();
        return (int)fun(start, fuel, start, finish, locations, n);
    }
};