#include <iostream>
#include <vector>
using namespace std;
int n; 
vector<int> father(1001, 0); 

void init() {
    for (int i = 0; i <= n; ++i) {
        father[i] = i;
    }
}
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);
}
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}
void join(int u, int v) {
    u = find(u); 
    v = find(v); 
    if (u == v) return ; 
    father[v] = u;
}

int main() {
    int s, t;
    cin >> n;
    init();
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        if (isSame(s, t)) {
            cout << s << " " << t << endl; //空格 流操纵符，用于插入一个换行符并刷新输出缓冲区。这意味着光标将移到下一行，并确保之前的输出立即显示
            return 0;
        } else {
            join(s, t);
        }
    }
}
