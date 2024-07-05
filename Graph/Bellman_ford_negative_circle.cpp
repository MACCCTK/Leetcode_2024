#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid;

    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid.push_back({p1, p2, val});

    }
    int start = 1; 
    int end = n;   

    vector<int> minDist(n + 1 , INT_MAX);
    minDist[start] = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) { // 这里我们松弛n次，最后一次判断负权回路
        for (vector<int> &side : grid) {
            int from = side[0];
            int to = side[1];
            int price = side[2];
            if (i < n) {
                if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price) minDist[to] = minDist[from] + price;
            } else { 
                if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price) flag = true;
            }
        }
    }

    if (flag) cout << "circle" << endl;
    else if (minDist[end] == INT_MAX) {
        cout << "unconnected" << endl;
    } else {
        cout << minDist[end] << endl;
    }
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
    int start = 1;  
    int end = n;   

    vector<int> minDist(n + 1 , INT_MAX);
    minDist[start] = 0;
    queue<int> que;
    que.push(start);
    vector<int> count(n+1, 0); 
    count[start]++;

    bool flag = false;
    while (!que.empty()) {
        int node = que.front(); 
        que.pop();
        for (Edge edge : grid[node]) {
            int from = node;
            int to = edge.to;
            int value = edge.val;
            if (minDist[to] > minDist[from] + value) {
                minDist[to] = minDist[from] + value;
                que.push(to);
                count[to]++; 
                if (count[to] == n) {// 如果加入队列次数超过 n-1次 就说明该图与负权回路
                    flag = true;
                    while (!que.empty()) que.pop();
                    break;
                }
            }
        }
    }
    if (flag) cout << "circle" << endl;
    else if (minDist[end] == INT_MAX) {
        cout << "unconnected" << endl;
    } else {
        cout << minDist[end] << endl;
    }
}
