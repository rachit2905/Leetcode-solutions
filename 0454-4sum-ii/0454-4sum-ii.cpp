class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       int ans = 0;
        int n = nums1.size();
        unordered_map <int,int> umap;
        
        for(auto iter : nums4){
            for(auto it : nums3){
                umap[iter+it]++;
            }
        }
        
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(umap.find(-nums1[i]-nums2[j])!=umap.end()){
                    ans+=umap[-nums1[i]-nums2[j]];
                }
            }
        }
        
        return ans;   
    }
};