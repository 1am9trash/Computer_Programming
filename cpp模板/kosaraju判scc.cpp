#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define pb push_back
#define ll long long
#define ld long double
#define PI acosl(-1)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i > (b); i--)
#define all(x) x.begin(), x.end()

// kosaraju求非單點的scc數，有像圖不一定聯通
// 兩次dfs，一次求出逆後序，一次對反向圖求scc

int n, m, a, b, cnt, ans;
bool vis[10001];
int scc[10001], num[10001];
vector<int> g[10001], reG[10001], v;

void dfs(int cur) {
    vis[cur] = 1;
    FOR(i, 0, g[cur].size()) {
        if (!vis[g[cur][i]]) {
            dfs(g[cur][i]);
        }
    }
    v.pb(cur);
}

void reDfs(int cur, int cnt) {
    scc[cur] = cnt;
    FOR(i, 0, reG[cur].size()) {
        if (scc[reG[cur][i]]) {
            reDfs(reG[cur][i], cnt);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, m) {
        cin >> a >> b;
        g[a].pb(b);
        reG[b].pb(a);
    }
    FOR(i, 1, n + 1) {
        if (!vis[i])
            dfs(i);
    }
    REF(i, v.size() - 1, -1) {
        if (!scc[v[i]]) {
            cout << "  " << v[i] << "\n";
            cnt++;
            reDfs(v[i], cnt);
        }
    }
    FOR(i, 1, n + 1) {
        cout << i << " " << scc[i] << "\n";
        num[scc[i]]++;
    }
    FOR(i, 1, cnt + 1) {
        if (num[i] > 1)
            ans++;
    }
    cout << ans << "\n";

    return 0;
}