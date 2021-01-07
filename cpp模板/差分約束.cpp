#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define pb push_back
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()

const ll INF = LLONG_MAX / 3;

struct edge {
    ll v1, v2, w;
    edge() {}
    edge(ll v1, ll v2, ll w) : v1(v1), v2(v2), w(w) {}
};

// n 未知數數量, m 條件數量
ll n, m, a, b, l;
vector<edge> g;
vector<ll> dis;

bool bellmanFord() {
    dis = vector<ll>(n + 1);
    dis[0] = 0;
    for (int i = 1; i < n + 1; i++)
        dis[i] = INF;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < g.size(); j++)
            if (dis[g[j].v2] > dis[g[j].v1] + g[j].w)
                dis[g[j].v2] = dis[g[j].v1] + g[j].w;
    for (int j = 1; j < g.size(); j++)
        if (dis[g[j].v2] > dis[g[j].v1] + g[j].w)
            return 0;
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i < n + 1; i++)
        g.pb(edge(0, i, 0));
    for (int i = 0; i < m; i++) {
        // f(a) - f(b) <= l
        cin >> a >> b >> l;
        g.pb(edge(b, a, l));
    }
    if (bellmanFord())
        for (int i = 1; i < n + 1; i++)
            cout << dis[i] << " ";
    else
        cout << "NO";

    return 0;
}
