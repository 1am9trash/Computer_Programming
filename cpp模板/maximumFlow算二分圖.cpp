#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize(2, 3, fast, unroll - loops)

#define pb push_back
#define ll long long

// maximum flow算二分圖

int n, m, k, graph[1002][1002], u, v, path[1002], flow[1002], a, b;

int hasPath(int s, int t) {
    queue<int> q;
    memset(path, -1, sizeof(path));
    path[s] = 0;
    flow[s] = INT_MAX;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = s; i < t + 1; i++) {
            if (path[i] == -1 && graph[cur][i] > 0) {
                flow[i] = min(flow[cur], graph[cur][i]);
                path[i] = cur;
                q.push(i);

                if (i == t)
                    return flow[i];
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t) {
    int ret = 0;
    while (1) {
        int w = hasPath(s, t), cur = t, pre;
        if (!w)
            break;
        while (cur != s) {
            pre = path[cur];
            graph[pre][cur] -= w;
            graph[cur][pre] += w;
            cur = pre;
        }
        ret += w;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        graph[0][1 + i] = 1;
    for (int i = 0; i < m; i++)
        graph[1 + n + i][1 + n + m] = 1;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        graph[a][n + b] = 1;
    }
    cout << maxFlow(0, 1 + n + m) << "\n";
    return 0;
}