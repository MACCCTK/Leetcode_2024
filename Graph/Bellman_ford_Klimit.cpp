#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

int main() {
    int src, dst,k ,p1, p2, val ,m , n;
    cin >> n >> m;
    vector<vector<int>> grid;

    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid.push_back({p1, p2, val});
    }

    cin >> src >> dst >> k;

    vector<int> minDist(n + 1 , INT_MAX);
    minDist[src] = 0;
    vector<int> minDist_copy(n + 1); // 用来记录上一次遍历的结果
    for (int i = 1; i <= k + 1; i++) {
        minDist_copy = minDist; // 获取上一次计算的结果
        for (vector<int> &side : grid) {
            int from = side[0];
            int to = side[1];
            int price = side[2];
            // 注意使用 minDist_copy 来计算 minDist 
            if (minDist_copy[from] != INT_MAX && minDist[to] > minDist_copy[from] + price) {  
                minDist[to] = minDist_copy[from] + price;
            }
        }
    }
    if (minDist[dst] == INT_MAX) cout << "unreachable" << endl;
    else cout << minDist[dst] << endl; 

}

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
using namespace std;

struct Edge { 
    int to; 
    int val; 
    Edge(int t, int w): to(t), val(w) {} 
};


int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<list<Edge>> grid(n + 1); 
    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid[p1].push_back(Edge(p2, val));
    }
    int start, end, k;
    cin >> start >> end >> k;

    k++;

    vector<int> minDist(n + 1 , INT_MAX);
    vector<int> minDist_copy(n + 1); 

    minDist[start] = 0;

    queue<int> que;
    que.push(start);
    int que_size;
    while (k-- && !que.empty()) {
        vector<bool> visited(n + 1, false); // 每一轮松弛中，控制节点不用重复入队列
        minDist_copy = minDist; 
        que_size = que.size(); 
        while (que_size--) { 
            int node = que.front(); que.pop();
            for (Edge edge : grid[node]) {
                int from = node;
                int to = edge.to;
                int price = edge.val;
                if (minDist[to] > minDist_copy[from] + price) {
                    minDist[to] = minDist_copy[from] + price;
                    if(visited[to]) continue; // 不用重复放入队列，但需要重复松弛，所以放在这里位置
                    visited[to] = true;
                    que.push(to);
                }
            }

        }
    }
    if (minDist[end] == INT_MAX) cout << "unreachable" << endl;
    else cout << minDist[end] << endl;
}
