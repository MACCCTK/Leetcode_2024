#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int l, r, val;
};

int n = 10001;
vector<int> father(n, -1); // 节点编号是从1开始的，n要大一些

void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}

int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]); 
}

void join(int u, int v) {
    u = find(u); 
    v = find(v);
    if (u == v) return ; 
    father[v] = u;
}

int main() {

    int v, e;
    int v1, v2, val;
    vector<Edge> edges;
    int result_val = 0;
    cin >> v >> e;
    while (e--) {
        cin >> v1 >> v2 >> val;
        edges.push_back({v1, v2, val});
    }

    // 执行Kruskal算法按边的权值对边进行从小到大排序
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.val < b.val;
    });
  
    vector<Edge> res; // 存储最小生成树的边

    init();
    for (Edge edge : edges) {
        int x = find(edge.l);
        int y = find(edge.r);
        if (x != y) {
            result_val += edge.val; 
            res.push_back(edge); // 保存最小生成树的边
            join(x, y); 
        }
    }
    cout << result_val << endl;
    return 0;

    for (Edge edge : result) {
        cout << edge.l << " - " << edge.r << " : " << edge.val << endl;// 打印最小生成树的边
    }
}
