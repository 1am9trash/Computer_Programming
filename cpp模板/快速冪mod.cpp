#include <bits/stdc++.h>
using namespace std;

// 對a的b次方取mod p，快速冪計算
long long powMod(long long a, long long b, long long p) {
    a = a % p;
    long long ret = 1 % p, power = a;
    while (b != 0) {
        if (b % 2)
            ret = (ret * power) % p;
        power = (power * power) % p;
        b /= 2;
    }
    return ret;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << powMod(a, b, p) << "\n";
    return 0;
}
