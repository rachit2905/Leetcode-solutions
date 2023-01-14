class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
         vector<int>vist(x+y+1,0);
        if(z>x+y)return false;
        int direction[]={x,-x,y,-y};
        queue<int>q;
        q.push(0);
        vist[0]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:direction){
                int total=curr+it;
                if(total==z)return true;
                if(total<0||total>x+y)continue;
                if(vist[total]==0){
                    q.push(total);
                    vist[total]=1;
                }
            }

        }
        return false;
    }
};