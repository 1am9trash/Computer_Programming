#include <bits/stdc++.h>
using namespace std;

// 最小生成數路徑長
int anc[5001];
int mstAnc[5001];

int find(int *anc, int k) {
    if (*(anc + k) == k) return *(anc + k);
    *(anc + k) = find(anc, *(anc + k));
    return *(anc + k);
}

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // n個點，m個測資
    int n, m;
    cin >> n >> m;
    vector<int> t(3, 0);
    vector<vector<int>> edge(m, t);

    for (int i = 1; i <= n; i++)
        anc[i] = i;

    // 輸入a, b點聯通，加權c
    for (int i = 0; i < m; i++) {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
        int ancA = find(anc, edge[i][0]), ancB = find(anc, edge[i][1]);
        if (ancA != ancB) anc[ancA] = ancB;
    }

    int graph = 0;
    for (int i = 1; i <= n && graph < 2; i++)
        if (anc[i] == i)
            graph++;
    if (graph >= 2) {
        cout << "orz\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
        mstAnc[i] = i;

    sort(edge.begin(), edge.end(), compare);

    int mst = 0;
    for (int i = 0; i < m; i++) {
        int mstAncA = find(mstAnc, edge[i][0]), mstAncB = find(mstAnc, edge[i][1]);
        if (mstAncA != mstAncB) {
            mstAnc[mstAncA] = mstAncB;
            mst += edge[i][2];
        }
    }

    cout << mst << "\n";
    return 0;
}
