#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define pb push_back
#define ll long long
#define ld long double
#define FOR(i, a, b) for(ll i = (a); i < (b); i++)
#define REF(i, a, b) for(ll i = (a); i > (b); i--)

// floyd求多源最短路，可處理負權回路

int n, m, a, b, dis[1000][1000];

// 初始化鄰接矩陣
void init() {
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            dis[i][j] = INT_MAX / 2;
            if(i == j) dis[i][j] = 0;
        }
    }
}

void floyd() {
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            FOR(k, 0, n) {
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> n >> m;
    init();
    FOR(i, 0, m) {
        cin >> a >> b >> dis[a - 1][b - 1];
    }
    floyd();

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

