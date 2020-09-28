#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define pb push_back
#define ll long long
#define FOR(i, a, b) for(ll i = (a); i < (b); i++)
#define REF(i, a, b) for(ll i = (a); i > (b); i--)

int t, n, x1, y11, x2, y2;
int vis[5001][5001];

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x1 >> y11 >> x2 >> y2;
        
        if(x1 > x2) swap(x1, x2);
        if(y11 > y2) swap(y11, y2);
        if(abs(x2 - x1) > abs(y2 - y11)) {
            swap(x1, y11);
            swap(x2, y2);
        }
        
        memset(vis, 0, sizeof(vis));
        
        vis[x1][y11] = 1;
        FOR(i, y11, y2) {
            FOR(j, 1, n + 1) {
                vis[j][i] %= 5318008;
                if(j - 1 >= 1) vis[j - 1][i + 1] = (vis[j - 1][i + 1] + vis[j][i]);
                vis[j][i + 1] = (vis[j][i + 1] + vis[j][i]);
                if(j + 1 <= n) vis[j + 1][i + 1] = (vis[j + 1][i + 1] + vis[j][i]);
            }
        }
        cout << vis[x2][y2] % 5318008 << "\n";
    }
    
    return 0;
}
