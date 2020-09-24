#include <bits/stdc++.h>
using namespace std;

// 並查集
#define MAXN 10001
int anc[MAXN];

int find(int k) {
    if (anc[k] == k) return anc[k];
    anc[k] = find(anc[k]);
    return anc[k];
}

int main() {
    // n個元素，m個操作
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        anc[i] = i;
    // 1合併，2判斷同不同集合
    for (int i = 1; i <= m; i++) {
        int q, a, b;
        cin >> q >> a >> b;
        int ancA = find(a), ancB = find(b);
        if (q == 1 && ancA != ancB)
            anc[ancA] = ancB;
        else if (q == 2)
            cout << (ancA == ancB ? "Y\n" : "N\n");
    }
    return 0;
}
