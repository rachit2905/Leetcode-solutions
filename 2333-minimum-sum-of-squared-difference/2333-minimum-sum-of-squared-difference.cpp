class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0 ;
        priority_queue<long long> pq ; 
        vector<long long > v(1e5+1  , 0) ;
        for(int i = 0 ; i < nums1.size() ; i++){
            v[abs(nums1[i] - nums2[i])]++ ;
        }
        long long k  = k1 + k2 ;
        for(int i = 1e5 ; i >= 1 ; i--){
            long long val = v[i] ; 
            if(val <= k){
                if(i == 1)return 0 ; 
                // v[i] = 0 ; 
                v[i-1] += v[i] ;
                k -= v[i] ; 
                v[i] = 0 ;
            }
            else{
                if(i == 0)return 0 ;
                v[i] -= k ;
                v[i-1]+= k ;
                break ;
            }
        }
        for(int i = 0 ; i <= 1e5 ; i++){
            ans += (long long )i*i *  (long long)v[i] ;
        }
        return ans ;
    }
};