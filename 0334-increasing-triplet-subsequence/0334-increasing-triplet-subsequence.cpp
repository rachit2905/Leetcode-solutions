class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n = a.size();

        vector<int>v;
        for (auto p : a) {
            auto it = lower_bound(v.begin(), v.end(), p);
            if (it == v.end()) {
                v.push_back(p);
            }
            else {
                *it = p;
            }
        }

        return v.size()>=3;
    }
};