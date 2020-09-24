#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000001
bool prime[MAXN];
int nthPrime[MAXN];

// 歐拉線性篩素數
void isPrime(long long n) {
    // 0代表素數，因為初始化為0
    long long index = 1;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) nthPrime[index++] = i;
        for (int j = 1; j < index && i * nthPrime[j] <= n; j++) {
            prime[i * nthPrime[j]] = 1;
            if (i % nthPrime[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // size範圍，q查詢次數
    long long size, q;
    cin >> size >> q;
    isPrime(size);

    for (int i = 0; i < q; i++) {
        long long p;
        cin >> p;
        cout << nthPrime[p] << "\n";
    }
    return 0;
}
