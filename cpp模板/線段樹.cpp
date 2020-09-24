#include <bits/stdc++.h>
using namespace std;

// 線段樹
#define ll long long
#define lId (id << 1)
#define rId (id << 1 | 1)
#define MAXN 100001

// 初始值
ll a[MAXN];

// 儲存1-n的線段樹，節點不多於4n
struct segmentTree {
    int l, r;
    ll lazy;
    ll sum; // 儲存資料，應需要改變
    inline int len() { return r - l + 1; }
} tree[MAXN * 4];

// 向上更新
void pushUp(int id) {
    tree[id].sum = tree[lId].sum + tree[rId].sum;
}

// 向下更新
void pushDown(int id) {
    if (!tree[id].lazy) return;
    tree[lId].lazy += tree[id].lazy;
    tree[rId].lazy += tree[id].lazy;

    // 維護資料
    tree[lId].sum += tree[id].lazy * tree[lId].len();
    tree[rId].sum += tree[id].lazy * tree[rId].len();

    tree[id].lazy = 0;
}

// 建立線段樹
void build(int id, int bl, int br) {
    tree[id].l = bl;
    tree[id].r = br;
    tree[id].lazy = 0;

    if (bl == br) {
        // 維護資料
        tree[id].sum = a[bl];
        return;
    }

    int mid = (bl + br) >> 1;
    build(lId, bl, mid);
    build(rId, mid + 1, br);
    pushUp(id);
}

// 區間更新，更新ul到ur的值
void updateInterval(int id, int ul, int ur, ll value) {
    int l, r;
    l = tree[id].l;
    r = tree[id].r;

    if (ul <= l && r <= ur) {
        tree[id].sum += value * tree[id].len();
        tree[id].lazy += value;
        return;
    }

    pushDown(id);
    int mid = (l + r) >> 1;
    if (ul <= mid) updateInterval(lId, ul, ur, value);
    if (ur > mid) updateInterval(rId, ul, ur, value);

    pushUp(id);
}

// 查詢區間內儲存的資料
ll query(int id, int ql, int qr) {
    int l, r;
    l = tree[id].l;
    r = tree[id].r;

    // 依query回傳值
    if (ql <= l && r <= qr) return tree[id].sum;

    pushDown(id);
    ll ret = 0;
    int mid = (l + r) >> 1;
    if (ql <= mid) ret += query(lId, ql, qr);
    if (qr > mid) ret += query(rId, ql, qr);

    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    for (int i = 1; i <= m; i++) {
        int input;
        cin >> input;
        if (input == 1) {
            int l, r;
            ll value;
            cin >> l >> r >> value;
            updateInterval(1, l, r, value);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, l, r) << "\n";
        }
    }

    return 0;
}
