class Solution {
public:
    static bool myCmp(vector<int> &v1, vector<int> &v2){
        return v1[1]<v2[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),myCmp);
        vector<int> timeline(1001,0);
        int passengers=0;
        int startTime=0;
        for(int i=0;i<trips.size();i++){
            int endTime=trips[i][1];
            for(int i=startTime;i<=endTime;i++){
                passengers-=timeline[i];
                timeline[i]=0;
            }
            if(passengers+trips[i][0]>capacity) return false;
            passengers+=trips[i][0];
            timeline[trips[i][2]]+=trips[i][0];
            startTime=endTime;
        }
        return true;
    }
};