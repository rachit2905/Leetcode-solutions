class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
         int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0, maxH = 0;
        
        // Add boundary cells to priority queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    pq.push({heightMap[i][j], i * n + j});
                    visited[i][j] = true;
                }
            }
        }
        
        while(!pq.empty()) {
            auto [h, idx] = pq.top();
            pq.pop();
            int i = idx / n, j = idx % n;
            maxH = max(maxH, h);
            
            // Check neighboring cells
            if(i > 0 && !visited[i - 1][j]) {
                visited[i - 1][j] = true;
                if(heightMap[i - 1][j] < maxH) 
                    ans += maxH - heightMap[i - 1][j];
                pq.push({heightMap[i - 1][j], (i - 1) * n + j});
            }
            if(j > 0 && !visited[i][j - 1]) {
                visited[i][j - 1] = true;
                if(heightMap[i][j - 1] < maxH) 
                    ans += maxH - heightMap[i][j - 1];
                pq.push({heightMap[i][j - 1], i * n + j - 1});
            }
            if(i < m - 1 && !visited[i + 1][j]) {
                visited[i + 1][j] = true;
                if (heightMap[i + 1][j] < maxH) 
                    ans += maxH - heightMap[i + 1][j];
                pq.push({heightMap[i + 1][j], (i + 1) * n + j});
            }
            if(j < n - 1 && !visited[i][j + 1]) {
                visited[i][j + 1] = true;
                if(heightMap[i][j + 1] < maxH) 
                    ans += maxH - heightMap[i][j + 1];
                pq.push({heightMap[i][j + 1], i * n + j + 1});
            }
        }
        
        return ans;
    }
};