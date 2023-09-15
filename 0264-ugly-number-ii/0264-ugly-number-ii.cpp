class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long int> set;
        set.insert(1);

        for(int i = 2; i <= n; i++){
            long long int cur = *set.begin();
            set.erase(set.find(cur));

            set.insert(2*cur);
            set.insert(3*cur);
            set.insert(5*cur);
        }

        return *set.begin();
        
    }
    
};