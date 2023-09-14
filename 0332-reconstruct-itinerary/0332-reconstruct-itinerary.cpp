class Solution {
public:
     bool buildItinerary(unordered_map <string, vector <pair<string, bool>>> &g, string currAirport, vector <string> &path, int tickets, vector <string> &itinerary) 
     {
                 path.push_back(currAirport);
        
        if(path.size() == tickets + 1) {
            itinerary = path;
            return true;
        }
        
        for(auto &item : g[currAirport]) {
            if(!item.second) {
                string nextAirport = item.first;
                
                item.second = true;
                
                if(buildItinerary(g, nextAirport, path, tickets, itinerary)) {
                    return true;
                }
            
                item.second = false;
            }
        }
        
        path.pop_back();
        
        return false;

     }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>ans;
         unordered_map <string, vector <pair<string, bool>>> g;
        
        for(const vector<string> &ticket : tickets)
        {
            string from = ticket[0], to = ticket[1];
            
            g[from].push_back({ to, false });
        }
        
        for(auto &item : g) {
            sort(item.second.begin(), item.second.end());
        }
        
        string startAirport = "JFK";
        vector <string> path, itinerary;
        
        buildItinerary(g, startAirport, path, tickets.size(), itinerary);
        
        return itinerary;
        
    }
};