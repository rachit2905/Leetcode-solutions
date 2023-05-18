class Solution {
public:
    vector<int> ans;
    void tSort(int i, vector<vector<int>>& gr, stack<int>& st, vector<bool>& v) {
        v[i] = true;

        for (auto& x : gr[i]) {
            if (!v[x])
                tSort(x, gr, st, v);
        }

        st.push(i);
    }

    void dfs(int i, vector<vector<int>>& gr, vector<bool>& v, int& N) {
        if (v[i])
            return;

        v[i] = true;
        N++;

        for(auto& x : gr[i])
            if (!v[x])
                dfs(x, gr, v, N);
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> v(n, false);
        stack<int> st;
        vector<vector<int>> gr(n);
        for (auto& v : edges) 
            gr[v[0]].push_back(v[1]);

        for (int i = 0; i < n; i++) {
            if (!v[i])
                tSort(i, gr, st, v);
        }

        for(int i = 0; i < v.size(); i++)
            v[i] = false;

        int N = 0;
        while (st.size() && N < n) {
            int x = st.top();
            st.pop();
            if(!v[x]) {
                ans.push_back(x);
                dfs(x, gr, v, N);
            }
        }

        return ans;
    }
};