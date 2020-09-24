#include <bits/stdc++.h>
using namespace std;

// 三分求凹型、凸型極值

// eps為精度乘0.1
#define eps 1e-7
#define MAXN 20

struct func {
    double parameter[MAXN];

    void init() {
        for (int i = 0; i < MAXN; i++)
            parameter[i] = 0;
    }

    double value(double x) {
        // 秦九昭公算法
        double ret = 0;
        for (int i = MAXN - 1; i >= 0; i--)
            ret = ret * x + parameter[i];
        return ret;
    }
};

double threeDiv(func &f, double l, double r) {
    while (fabs(l - r) >= eps) {
        double mid = (l + r) / 2;
        double rMid = (mid + r) / 2;
        if (f.value(mid) > f.value(rMid))
            r = rMid;
        else
            l = mid;
    }
    return l;
}

int main() {
    int n;
    double l, r;
    cin >> n >> l >> r;

    func f;
    f.init();
    for (int i = n; i >= 0; i--)
        cin >> f.parameter[i];

    printf("%.5lf", threeDiv(f, l, r));

    return 0;
}
