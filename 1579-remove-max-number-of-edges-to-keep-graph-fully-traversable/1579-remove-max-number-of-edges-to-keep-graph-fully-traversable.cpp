class Solution {
 int _find(int x, vector<int>& parent){
        return parent[x] == x? x: parent[x] = _find(parent[x], parent);
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> alice(n+1), bob(n+1);
        for(int i=1;i<=n;i++) alice[i] = bob[i] = i;
        sort(begin(edges), end(edges), [](auto& e1, auto& e2){
            return e1[0]>e2[0];
        });
        int count = 0;
        for(vector<int>& edge: edges){
            bool skip = true;
            if(edge[0] == 3 || edge[0] == 1){
                int pa = _find(edge[1], alice);
                int pb = _find(edge[2], alice);
                if(pa!=pb){
                    alice[pb] = pa;
                    skip = false;
                }
            }
            if(edge[0] == 3 || edge[0] == 2){
                int pa = _find(edge[1], bob);
                int pb = _find(edge[2], bob);
                if(pa!=pb){
                    bob[pb] = pa;
                    skip = false;
                }
            }
            count += skip;
        }
        int aliceSet = _find(1, alice);
        int bobSet = _find(1, bob);
        for(int i=2;i<=n;i++){
            if(_find(i, alice) != aliceSet || _find(i, bob) != bobSet)
                return -1;
        }
        return count;
    }
};
