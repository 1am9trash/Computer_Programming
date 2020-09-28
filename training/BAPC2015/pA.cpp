#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define pb push_back
#define ll long long
#define int ll
#define ld long double
#define FOR(i, a, b) for(ll i = (a); i < (b); i++)
#define REF(i, a, b) for(ll i = (a); i > (b); i--)

int t, n, w, l, lef, rig, temp, mid;
vector<int> tra;

bool check(int lim) {
    
    int cnt = 0, cur = 1;
    // cout << lim << ":\n";
    FOR(i, 0, w) {
        if(tra[i] < cur) continue;
        
        cnt++;
        if(tra[i] - cur + 1 > lim) cur = tra[i], i--;
        else cur += lim;
        
        if(cnt > l) return 0;
        // cout << tra[i] << " " << cnt << " " << cur << "\n";
    }
    // cout << cur << " " << n << " " << l << "\n";
    // cout << ((cur > n && cnt <= l) || cnt < l) << "\n";
    if((cur > n && cnt <= l) || cnt < l) return 1;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> t;
    while(t--) {
        tra.clear();
        cin >> n >> w >> l;
        FOR(i, 0, w) {
            cin >> temp;
            tra.pb(temp);
        }
        lef = 0, rig = n;
        while(lef < rig) {
            // cout << lef << " " << rig << "\n";
            mid = (lef + rig) / 2;
            if(check(mid)) rig = mid;
            else lef = mid + 1;
        }
        // cout << check(50000);
        // cout << check(998) << "\n";
        cout << lef << "\n";
    }
    return 0;
}
 rss feed for new problems | powered by kattis | support kattis on patreon!
