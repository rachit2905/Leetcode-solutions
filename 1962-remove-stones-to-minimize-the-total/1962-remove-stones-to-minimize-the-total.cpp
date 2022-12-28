class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        const int max = piles.size() - 1;
        int index = max, out = 0;
        std::sort(piles.begin(), piles.end());
        piles[index]++; piles[index]>>=1;
        while (--k) {
            if (piles[(index == 0) ? 0 : --index] < piles[max]) {
                index = max;
                std::sort(piles.begin(), piles.end());
            }
            piles[index]++; piles[index]>>=1;
        }
        for (const auto& r : piles) {
            out += r;
        }
        return out;}
};