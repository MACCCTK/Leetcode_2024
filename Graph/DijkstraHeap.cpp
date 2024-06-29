#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std; 

class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;// 小顶堆
    }
};

struct Edge {
    int to;  // 邻接顶点
    int val; // 边的权重

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

    int start = 1;  // 起点
    int end = n;    // 终点

    std::vector<int> minDist(n + 1, INT_MAX);
    std::vector<bool> visited(n + 1, false); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;

    pq.push(pair<int, int>(start, 0)); 
    
    minDist[start] = 0;  

    while (!pq.empty()) {
        // 第一步，选源点到哪个节点近且该节点未被访问过 
        pair<int, int> cur = pq.top(); pq.pop();
        if (visited[cur.first]) continue;

        // 第二步，该最近节点被标记访问过
        visited[cur.first] = true;

        // 第三步，更新非访问节点到源点的距离
        for (Edge edge : grid[cur.first]) {
            if (!visited[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to]) {
                minDist[edge.to] = minDist[cur.first] + edge.val;
                pq.push(pair<int, int>(edge.to, minDist[edge.to]));
            }
        }

    }

    if (minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl; 
}
