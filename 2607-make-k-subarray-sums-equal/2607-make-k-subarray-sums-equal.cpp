#define ll long long
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        ll n = arr.size(), ans = 0;
        vector<bool> vis(n, false);
        for(ll i = 0; i < n; i++) {
            if(vis[i]) continue;
            vector<ll> temp;
            ll cur = i;
            while(cur < n) {
                temp.push_back(arr[cur]);
                vis[cur] = true;
                cur += k;
                if(cur >= n) {
                    cur %= n;
                }
                if(vis[cur]) break;
            }
            sort(temp.begin(), temp.end());
            ll median = temp[temp.size()/2];
            for(ll j = 0; j < temp.size(); j++) {
                ans += abs(temp[j] - median);
            }
        }
        return ans;
    }
};