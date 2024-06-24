// DFS
class Solution {
private:
    int count;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; 
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue; 
            if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) { // 
                visited[nextx][nexty] = true;
                count++;
                dfs(grid, visited, nextx, nexty);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    count = 1; 
                    visited[i][j] = true;
                    dfs(grid, visited, i, j); // 将与其链接的陆地都标记上 true
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};

// BFS
class Solution {
private:
    int count;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; 
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<int> que;
        que.push(x);
        que.push(y);
        visited[x][y] = true; // 加入队列就意味节点是陆地可到达的点
        count++;
        while(!que.empty()) {
            int xx = que.front();que.pop();
            int yy = que.front();que.pop();
            for (int i = 0 ;i < 4; i++) {
                int nextx = xx + dir[i][0];
                int nexty = yy + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue; 
                if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {
                    visited[nextx][nexty] = true;
                    count++;
                    que.push(nextx);
                    que.push(nexty);
                }
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    count = 0;
                    bfs(grid, visited, i, j);
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};
