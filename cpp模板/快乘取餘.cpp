#include <iostream>
using namespace std;

// 快乘取餘（避免超限）
#define ll long long

ll mulMod(ll a, ll b, ll p) {
    ll ret = 0;
    a = a % p;
    while (b) {
        if (b % 2) ret = (ret + a) % p;
        a = (a + a) % p;
        b /= 2;
    }
    return ret;
}

int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    cout << mulMod(a, b, p) << "\n";
    return 0;
}
