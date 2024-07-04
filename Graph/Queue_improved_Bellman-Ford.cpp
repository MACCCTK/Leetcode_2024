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
    int start = 1;  
    int end = n;    

    vector<int> minDist(n + 1 , INT_MAX);
    minDist[start] = 0;

    queue<int> que;
    que.push(start); 

    while (!que.empty()) {
        int node = que.front(); que.pop();
        for (Edge edge : grid[node]) {
            int from = node;
            int to = edge.to;
            int value = edge.val;
            if (minDist[to] > minDist[from] + value) {
                minDist[to] = minDist[from] + value;
                que.push(to);
            }
        }
    }

    if (minDist[end] == INT_MAX) cout << "unconnected" << endl; 
    else cout << minDist[end] << endl; 
}
