#include <bits/stdc++.h>
using namespace std;

// 歐拉函數，利用通式解
#define ll long long

ll eular(ll n) {
    ll ret = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)
            ret = ret * (i - 1) / i;
        while (n % i == 0)
            n = n / i;
    }
    if (n > 1) ret = ret * (n - 1) * n;
    return ret;
}

int main() {
    ll num;
    cin >> num;
    cout << eular(num) << "\n";
    return 0;
}
