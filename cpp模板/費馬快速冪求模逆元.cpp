#include <bits/stdc++.h>
using namespace std;

// 費馬小定理快速冪求模逆元
long long fMMod(long long a, long long p) {
    a = a % p;
    long long ret = 1 % p, power = a, b = p - 2;

    while (b != 0) {
        if (b % 2)
            ret = (ret * power) % p;
        power = (power * power) % p;
        b /= 2;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, p;
    cin >> n >> p;

    for (long long i = 1; i <= n; i++)
        cout << fMMod(i, p) << "\n";

    return 0;
}
