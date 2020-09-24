#include <bits/stdc++.h>
using namespace std;

// 數論求1-n的模逆元，由前項推後項，O(n)，較快速冪or擴展歐幾里德快O(nlogn)
int main() {
    long long n, p;
    cin >> n >> p;

    long long inv[n + 1];
    inv[0] = 0;
    inv[1] = 1;

    // +p保證為正數
    for (long long i = 2; i <= n; i++)
        inv[i] = ((p - p / i) * inv[p % i] + p) % p;

    for (int i = 1; i <= n; i++)
        printf("%lld\n", inv[i]);
}
