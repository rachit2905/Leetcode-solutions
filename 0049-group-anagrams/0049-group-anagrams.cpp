class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> M;
        string t;
        
        for(auto str: strs) {
            t = str;
            sort(t.begin(), t.end());
            M[t].push_back(str);
        }

        for(auto m: M)
            res.push_back(m.second);
        
        return res;
    }
};