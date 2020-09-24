#include <bits/stdc++.h>
using namespace std;

// Rabin-Karp找子字串，效率低於KMP，容易實作
#define BASE 256
#define MOD 101

// 比對子字串是否符合模式
bool match(string &pattern, string &s, int start) {
    int len = pattern.size();
    for (int i = 0; i < len; i++)
        if (pattern[i] != s[start + i])
            return false;
    return true;
}

int main() {
    string pattern, s;
    cin >> pattern >> s;

    int patternLen = pattern.size(), sLen = s.size();
    if (patternLen == 0 || patternLen > sLen)
        return 0;

    int patternHash = 0, sHash = 0, powMod = 1;

    for (int i = 0; i < patternLen - 1; i++)
        powMod = powMod * BASE % MOD;

    // 用hash判斷是否可能為同一字串
    for (int i = 0; i < patternLen; i++) {
        patternHash = (patternHash * BASE + pattern[i]) % MOD;
        sHash = (sHash * BASE + s[i]) % MOD;
    }
    if (patternHash == sHash)
        if (match(pattern, s, 0))
            cout << 0 << " ";

    for (int i = 1; i < sLen - patternLen + 1; i++) {
        sHash = ((sHash - powMod * (s[i - 1])) * BASE + s[patternLen - 1 + i]) % MOD;
        if (sHash < 0) sHash += MOD;

        if (patternHash == sHash)
            if (match(pattern, s, i))
                cout << i << " ";
    }
    cout << "\n";
    return 0;
}
