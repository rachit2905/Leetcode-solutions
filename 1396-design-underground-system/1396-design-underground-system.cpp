class UndergroundSystem {
public:
    map<int,pair<string,int>>m1;
    map<pair<string,string>,vector<int>>m2;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m1[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        m2[{m1[id].first,stationName}].push_back(t-m1[id].second);
        m1[id]={};
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans=0.0,n=m2[{startStation,endStation}].size();
        for(auto it:m2[{startStation,endStation}])
        {
            ans+=it;
        }
        ans=(ans)/(n*1.0);
            return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */