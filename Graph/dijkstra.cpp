#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }

    int start = 1;
    int end = n;

    std::vector<int> minDist(n + 1, INT_MAX);
    std::vector<bool> visited(n + 1, false);

    minDist[start] = 0; 

    for (int i = 1; i <= n; i++) {

        int minVal = INT_MAX;
        int cur = 1;

        // 选距离源点最近且未访问过的节点
        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && minDist[v] < minVal) {
                minVal = minDist[v];
                cur = v;
            }
        }

        visited[cur] = true;  // 标记该节点已被访问

        // 更新非访问节点到源点的距离
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v]) {
                minDist[v] = minDist[cur] + grid[cur][v];
            }
        }

    }

    if (minDist[end] == INT_MAX) cout << -1 << endl; 
    else cout << minDist[end] << endl;

}


#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }

    int start = 1;
    int end = n;

    std::vector<int> minDist(n + 1, INT_MAX);

    std::vector<bool> visited(n + 1, false);

    minDist[start] = 0; 
    vector<int> parent(n + 1, -1);

    for (int i = 1; i <= n; i++) {

        int minVal = INT_MAX;
        int cur = 1;

        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && minDist[v] < minVal) {
                minVal = minDist[v];
                cur = v;
            }
        }

        visited[cur] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v]) {
                minDist[v] = minDist[cur] + grid[cur][v];
                parent[v] = cur; // 记录边
            }
        }

    }
    // 输出最短情况
    for (int i = 1; i <= n; i++) {
        cout << parent[i] << "->" << i << endl;
    }
}
