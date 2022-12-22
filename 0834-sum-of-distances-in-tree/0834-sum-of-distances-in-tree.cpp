
class Solution {
private:
    void calcPN(int u, vector<vector<int>> &g, vector<int> &P, vector<int> &N, int parent = -1) {
        N[u] = 1;
        P[u] = 0;
        for (int v : g[u]) {
            if (v == parent) continue;
            calcPN(v,g,P,N,u);
            N[u] += N[v];
            P[u] += P[v] + N[v];
        }
    }
    void calcS(int u, vector<vector<int>> &g, vector<int> &N, vector<int> &S, int n, int parent = -1) {
        if (u != 0) {
            S[u] = S[parent] + n - 2 * N[u];
        }
        for (int v : g[u]) {
            if (v != parent) calcS(v,g,N,S,n,u);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (vector<int> e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> S(n,0), P(n,0), N(n,0);
        calcPN(0,g,P,N);
        S[0] = P[0];
        calcS(0,g,N,S,n);
        return S;
    }
};
