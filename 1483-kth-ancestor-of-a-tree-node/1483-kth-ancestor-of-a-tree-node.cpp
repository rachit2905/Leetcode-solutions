class TreeAncestor {
public:
    vector<vector<int>> paths;
    unordered_map<int, pair<int, int>> table;
    int n;
public:
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;

        unordered_set<int> inner;
        for (int i = 0; i < n; i++) {
            inner.insert(parent[i]); // insert -1 is ok
        }

        for (int i = 0; i < n; i++) {
            // form path from this leaf node
            if (inner.find(i) == inner.end()) {
                vector<int> path;
                int node = i;
                while (node != -1) {
                    if (table.find(node) == table.end()) {
                        table[node] = {paths.size(), path.size()};
                    }

                    path.push_back(node);
                    node = parent[node];
                }

                paths.push_back(path);
            }
        }

        /*
        for (int i = 0; i < paths.size(); i++) {
            for (int j = 0; j < paths[i].size(); j++) {
                std::cout << paths[i][j] << " ";
            }

            std::cout << std::endl;
        }
        */
    }

   
    int getKthAncestor(int node, int k) {
        auto p = table[node];
        int i = p.first, j = p.second;

        if (j + k < paths[i].size()) {
            return paths[i][j + k];
        }

        return -1;
    }
};
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */