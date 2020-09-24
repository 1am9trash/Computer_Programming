#include <bits/stdc++.h>
using namespace std;

#define MAXN 500001
int n, m, root, cnt = 0;
int depth[MAXN], father[MAXN][20];
vector<int> edge[MAXN];

void dfs(int node, int fa) {
    if (depth[node]) return;

    depth[node] = depth[fa] + 1;
    father[node][0] = fa;

    for (int i = 1; (1 << i) < depth[node]; i++)
        father[node][i] = father[father[node][i - 1]][i - 1];
    for (int i = 0; i < edge[node].size(); i++)
        if (edge[node][i] != fa)
            dfs(edge[node][i], node);
}

int LCA(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);

    for (int i = 20; i >= 0 && depth[a] > depth[b]; i--)
        if (depth[father[a][i]] >= depth[b])
            a = father[a][i];
    if (a == b) return a;

    for (int i = 20; i >= 0; i--)
        if (father[a][i] != father[b][i]) {
            a = father[a][i];
            b = father[b][i];
        }
    return father[a][0];
}

int main() {
    cin >> n >> m >> root;

    int node1, node2;
    for (int i = 0; i < n; i++) {
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    dfs(root, 0);

    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;
        cout << LCA(node1, node2) << "\n";
    }

    return 0;
}
