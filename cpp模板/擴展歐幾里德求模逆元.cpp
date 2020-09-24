#include <bits/stdc++.h>
using namespace std;

// 拓展歐幾里德算法求模逆元
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long t, ret = exgcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return ret;
}

long long invMod(long long a, long long b) {
    long long x, y, d;
    d = exgcd(a, b, x, y);
    return (d == 1) ? (x + b) % b : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 輸出1-n mod p的模逆元
    long long n, p;
    cin >> n >> p;

    for (long long i = 1; i <= n; i++)
        cout << invMod(i, p) << "\n";
    return 0;
}
