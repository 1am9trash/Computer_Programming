#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define pb push_back
#define ll long long
#define ld long double
#define FOR(i, a, b) for(ll i = (a); i < (b); i++)
#define REF(i, a, b) for(ll i = (a); i > (b); i--)

// 皆需要聯通
// 尤拉回路：一條路徑經過所有邊且回到起點
//   無向圖：每個節點度數為偶數
//   有向圖：每個節點出度 = 入度
// 尤拉路徑：一條路徑經過所有邊
//   無向圖：有兩個節點度數為奇數，其他為偶數，此二節點為起點跟終點（或全部為偶數）
//   有向圖：有一個節點出度 = 入度 + 1，一個節點入度 = 出度 + 1，其他相等（或全部相等）

// dfs判聯通，順便紀錄度數，若聯通且度數符合條件，則為尤拉回路/路徑

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    return 0;
}
