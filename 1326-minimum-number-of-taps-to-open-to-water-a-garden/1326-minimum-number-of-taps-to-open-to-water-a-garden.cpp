class Solution {
public:
    int minTaps(int n, std::vector<int>& ranges) {
        std::vector<int> maxReach(n + 1, 0);
        
        for (int i = 0; i < ranges.size(); ++i) {
            int s = std::max(0, i - ranges[i]);
            int e = i + ranges[i];
            maxReach[s] = e;
        }
        
        int tap = 0;
        int currEnd = 0;
        int nextEnd = 0;
        
        for (int i = 0; i <= n; ++i) {
            if (i > nextEnd) {
                return -1;
            }
            if (i > currEnd) {
                tap++;
                currEnd = nextEnd;
            }
            nextEnd = std::max(nextEnd, maxReach[i]);
        }
        
        return tap;
    }
};