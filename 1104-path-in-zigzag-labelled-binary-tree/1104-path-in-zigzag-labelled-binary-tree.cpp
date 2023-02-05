class Solution {
private:
    vector<int> ans;  
    bool solve(int node,vector<int> &vec,int target,vector<int> &temp){
        if(node >= vec.size()) return false;
        if(vec[node] == target){
            temp.push_back(target);
            ans = temp;
            return true;
        }

        temp.push_back(vec[node]);
        if(solve(node*2+1,vec,target,temp)) return true;
        if(solve(node*2+2,vec,target,temp)) return true;
        temp.pop_back();
        return false;
    }
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> vec;
        bool f = true;
        int layer = 1, node = 1;
        while(node <= label){
            int temp = layer;
            vector<int> v;
            while(temp--){
                v.push_back(node++);
            }
            if(!f) reverse(v.begin(),v.end());
            vec.insert(vec.end(),v.begin(),v.end());
            layer *= 2;
            f = !f;
        }
        solve(0,vec,label,vector<int> () = {});
        return ans;
    }
};
