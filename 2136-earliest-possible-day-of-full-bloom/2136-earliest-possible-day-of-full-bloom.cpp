class Solution {
public:
  static bool cmp (const pair<int,int>& p1, const pair<int,int>& p2) {
        return (max(p1.first+p1.second,p1.first+p2.first+p2.second)) < (max(p2.first+p2.second,p2.first+p1.first+p1.second));
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> plant;
        int N = plantTime.size();
        
        for (int i = 0; i < N; i++) {
            plant.push_back({plantTime[i], growTime[i]});
        }
        
        sort(plant.begin(), plant.end(), cmp);
        
        int lastGloomtime = 0, time = 0;
        
        for (int i = 0; i < N; i++) {
            time += plant[i].first;
            lastGloomtime = max(lastGloomtime,time+plant[i].second);
        }
        
        return lastGloomtime;
    }
};