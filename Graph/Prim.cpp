#include<iostream>
#include<vector>
#include <climits>

using namespace std;
int main() {
    int v, e;
    int x, y, k;
    cin >> v >> e;
    vector<vector<int>> grid(v + 1, vector<int>(v + 1, 10001));
    while (e--) {
        cin >> x >> y >> k;
        grid[x][y] = k;
        grid[y][x] = k;

    }
  
    vector<int> minDist(v + 1, 10001);
    vector<bool> isInTree(v + 1, false);

    for (int i = 1; i < v; i++) {
        // 第一步：选距离生成树最近节点
        int cur = -1; // 选中哪个节点 加入最小生成树
        int minVal = INT_MAX;
        for (int j = 1; j <= v; j++) {
            if (!isInTree[j] &&  minDist[j] < minVal) {
                minVal = minDist[j];
                cur = j;
            }
        }
        // 第二步：最近节点（cur）加入生成树
        isInTree[cur] = true;
        // 第三步：更新非生成树节点到生成树的距离（即更新minDist数组）
        for (int j = 1; j <= v; j++) {
            if (!isInTree[j] && grid[cur][j] < minDist[j]) {// 只需要关心与cur相连的非生成树节点的距离
                minDist[j] = grid[cur][j];
            }
        }
    }
    
    int result = 0;
    for (int i = 2; i <= v; i++) { // 不计第一个顶点，因为统计的是边的权值(v-1)
        result += minDist[i];
    }
    cout << result << endl;

}


int main() {
    int v, e;
    int x, y, k;
    cin >> v >> e;
    vector<vector<int>> grid(v + 1, vector<int>(v + 1, 10001));
    while (e--) {
        cin >> x >> y >> k;
        grid[x][y] = k;
        grid[y][x] = k;
    }

    vector<int> minDist(v + 1, 10001);
    vector<bool> isInTree(v + 1, false);
    vector<int> parent(v + 1, -1);

    for (int i = 1; i < v; i++) {
        int cur = -1;
        int minVal = INT_MAX;
        for (int j = 1; j <= v; j++) {
            if (!isInTree[j] &&  minDist[j] < minVal) {
                minVal = minDist[j];
                cur = j;
            }
        }

        isInTree[cur] = true;
        for (int j = 1; j <= v; j++) {
            if (!isInTree[j] && grid[cur][j] < minDist[j]) {
                minDist[j] = grid[cur][j];

                parent[j] = cur; // 记录边
            }
        }
    }
    // 输出 最小生成树边的链接情况
    for (int i = 1; i <= v; i++) {
        cout << i << "->" << parent[i] << endl;
    }
}

