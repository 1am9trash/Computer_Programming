#include <bits/stdc++.h>
using namespace std;

// 樹狀數組求單點更新、區間和問題
// 樹狀數組可用於求區間極值、區間和
#define MAXN 500001
#define lowBit(x) ((x) & (-x))

struct binaryIndexTree {
    int a[MAXN];
    int tree[MAXN];
    int capacity;

    void init(int size) {
        capacity = size;
        for (int i = 1; i <= size; i++) {
            a[i] = 0;
            tree[i] = 0;
        }
    }

    void update(int index, int addValue) {
        a[index] += addValue;
        while (index <= capacity) {
            tree[index] += addValue;
            index += lowBit(index);
        }
    }

    int query(int index) {
        int ret = 0;
        while (index >= 1) {
            ret += tree[index];
            index -= lowBit(index);
        }
        return ret;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    binaryIndexTree bit;
    bit.init(n);

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        bit.update(i, temp);
    }

    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        if (input == 1) {
            int index, addValue;
            cin >> index >> addValue;
            bit.update(index, addValue);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.query(r) - bit.query(l - 1) << "\n";
        }
    }

    return 0;
}
