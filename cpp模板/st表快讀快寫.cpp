#include <bits/stdc++.h>
using namespace std;

// st表，用快讀快寫加速
// 區間最大最小值查詢，不可更改

#define ll long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REFOR(i, a, b) for (int i = (a); i >= (b); i--)

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

// dp[i][j] i為位置，j為長度(2^j)
// lg, pw為預處理
int dp[100001][21], lg[100001], pw[21];
int n, m, a, b;

int main() {
    // n數組長度，m查詢次數
    n = read(), m = read();

    lg[0] = -1, pw[0] = 1;
    FOR(i, 1, n) {
        dp[i][0] = read();
        lg[i] = lg[i / 2] + 1;
    }
    FOR(i, 1, 20)
    pw[i] = pw[i - 1] * 2;

    FOR(i, 1, lg[n])
    FOR(j, 1, n)
    if (j + pw[i] - 1 <= n)
        dp[j][i] = max(dp[j][i - 1], dp[j + pw[i - 1]][i - 1]);

    FOR(i, 1, m) {
        // a到b的最大值
        a = read(), b = read();
        write(max(dp[a][lg[b - a + 1]], dp[b - pw[lg[b - a + 1]] + 1][lg[b - a + 1]]));
        puts("");
    }

    return 0;
}
