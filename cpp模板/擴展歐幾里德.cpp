#include <iostream>
using namespace std;

// exgcd
// ax + by = gcd(a, b)
#define ll long long

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll ret = exgcd(b, a % b, x, y);

    ll temp = x;
    x = y;
    y = temp - a / b * y;

    return ret;
}

int main() {
    ll a, b, x, y, ret;
    cin >> a >> b;

    ret = exgcd(a, b, x, y);
    cout
        << a << " * " << x
        << " + "
        << b << " * " << y
        << " = " << ret << "\n";

    return 0;
}
