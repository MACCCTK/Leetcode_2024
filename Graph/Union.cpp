并查集主要有三个功能:
寻找根节点，函数：find(int u)，也就是判断这个节点的祖先节点是哪个
将两个节点接入到同一个集合，函数：join(int u, int v)，将两个节点连在同一个根节点上
判断两个节点是否在同一个集合，函数：isSame(int u, int v)，就是判断两个节点是不是同一个根节点

// 将v，u 这条边加入并查集
void join(int u, int v) {
    u = find(u); 
    v = find(v); 
    if (u == v) return; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[v] = u;
    if (rank[u] <= rank[v]) father[u] = v; // rank小的树合入到rank大的树
    else father[v] = u;
    if (rank[u] == rank[v] && u != v) rank[v]++; 
}

// 并查集里寻根的过程
int find(int u) {
    if (u == father[u]) return u; // 如果根就是自己，直接返回
    else return find(father[u]); // 如果根不是自己，就根据数组下标一层一层向下找
}

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 并查集里寻根的过程
int find(int u) {
    if (u == father[u]) return u;
    else return father[u] = find(father[u]); // 路径压缩
}
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);
}

