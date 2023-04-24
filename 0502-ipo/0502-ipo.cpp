class Solution {
public:
    static bool comp(pair<int,int>& a,pair<int,int>& b){
        if(a.first<b.first) return true;
        else if(a.first==b.first){
            if(a.second>b.second) return true;
        }
        return false;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int res = 0, n = profits.size();
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; ++i){
            v[i] = {capital[i], profits[i]};
        }
        sort(v.begin(), v.end(), comp);

        priority_queue<int> pq;
        int i = 0;
        while(k>0){
            while(i<n && v[i].first<=w) {
                pq.push(v[i].second);
                i++;
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};