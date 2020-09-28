#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define pb push_back
#define ll long long
#define ld long double
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i++)

// 跑最短路，建二分圖，做最小路徑覆蓋（m - 最大配對）

int n, m, g[501][501], g1[501][501], de[501], s, f, t;
pair<int, int> a[501], b[501];
bool bg[501][501];
bool used[501];
int rel[501], sum;

bool found(int x) {
    FOR(i, 1, m + 1) {
        if (bg[x][i] && !used[i]) {
            used[i] = 1;
            if (rel[i] == 0 || found(rel[i])) {
                rel[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

signed main() {
    cin >> n >> m;
    FOR(i, 1, n + 1) {
        cin >> de[i];
    }
    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            cin >> g[i][j];

            if (i != j) g[i][j] += de[j];
            g1[i][j] = g[i][j];
        }
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                g1[i][j] = min(g1[i][k] + g1[k][j], g1[i][j]);

    FOR(i, 1, m + 1) {
        cin >> s >> f >> t;
        a[i] = {s, t};
        b[i] = {f, t + g[s][f]};
    }

    memset(rel, 0, sizeof(rel));
    FOR(i, 1, m + 1) {
        memset(bg[i], 0, sizeof(bg[i]));
        FOR(j, 1, m + 1) {
            if (i != j)
                if (b[i].second + g1[b[i].first][a[j].first] <= a[j].second) bg[i][j] = 1;
        }
    }

    for (int i = 1; i < m + 1; i++) {
        memset(used, 0, sizeof(used)); 
        if (found(i))
            sum++;
    }

    cout << m - sum << "\n";

    return 0;
}
