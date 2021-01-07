#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

struct edge {
    int v;
    double l;
    edge() {}
    edge(int v, double l) : v(v), l(l) {}
    bool operator<(const edge &t) const {
        return l > t.l;
    }
};

int n, m, u, v, w, h[3001], dis[3001];
edge temp;
bool vis[3001];
ll ans;
vector<edge> g[3001];
priority_queue<edge> p;

bool bellmanFord() {
    for (int i = 1; i < n + 1; i++) {
        g[0].pb(edge(i, 0));
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            for (int k = 0; k < g[j].size(); k++)
                if (h[g[j][k].v] > h[j] + g[j][k].l)
                    h[g[j][k].v] = h[j] + g[j][k].l;
    for (int j = 0; j < n + 1; j++)
        for (int k = 0; k < g[j].size(); k++)
            if (h[g[j][k].v] > h[j] + g[j][k].l)
                return 0;
    // for (int i = 1; i < n + 1; i++)
    // cout << h[i] << " ";
    // cout << "\n";
    for (int j = 1; j < n + 1; j++)
        for (int k = 0; k < g[j].size(); k++)
            g[j][k].l += h[j] - h[g[j][k].v];
    return 1;
}

void dijkstra(int st) {
    for (int i = 1; i < n + 1; i++) {
        vis[i] = 0;
        dis[i] = 1e9;
    }
    dis[st] = 0;
    p.push(edge(st, 0));

    while (!p.empty()) {
        temp = p.top();
        p.pop();

        if (vis[temp.v])
            continue;
        vis[temp.v] = 1;

        for (int i = 0; i < g[temp.v].size(); i++)
            if (dis[g[temp.v][i].v] > dis[temp.v] + g[temp.v][i].l) {
                dis[g[temp.v][i].v] = dis[temp.v] + g[temp.v][i].l;
                p.push(edge(g[temp.v][i].v, dis[g[temp.v][i].v]));
            }
    }
    for (int i = 1; i < n + 1; i++)
        if (dis[i] != 1e9)
            dis[i] += -h[st] + h[i];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].pb(edge(v, w));
    }
    if (!bellmanFord())
        cout << "-1";
    else {
        for (int i = 1; i < n + 1; i++) {
            dijkstra(i);
            ans = 0;
            for (int j = 1; j < n + 1; j++)
                ans += (ll)(j)*dis[j];
            cout << ans << "\n";
        }
    }

    return 0;
}