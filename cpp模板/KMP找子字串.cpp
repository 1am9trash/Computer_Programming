#include <bits/stdc++.h>
using namespace std;

// KMP找子字串
#define MAXN 1000000

int KMPNext[MAXN];

// 遞迴思想找next
void findNext(string &pattern) {
    // i為next下標，j為重複位數
    int i = 0, j = -1;
    KMPNext[0] = -1;

    // 找1-pattern長度的next
    while (i < pattern.size()) {
        // 已經退回最前或該項後綴與前綴相等，則next賦值，否則繼續退
        if (j == -1 || pattern[i] == pattern[j])
            KMPNext[++i] = ++j;
        else
            j = KMPNext[j];
    }
}

void KMP(string &s, string &pattern) {
    int sLen = s.size(), patternLen = pattern.size();

    // i為s下標，j為patten下標
    int i = 0, j = 0;
    while (i < sLen) {
        if (j == -1 || s[i] == pattern[j])
            i++, j++;
        else
            j = KMPNext[j];

        if (j == patternLen) {
            cout << i - patternLen << "\n";
            j = KMPNext[j];
        }
    }
}

int main() {
    string s, pattern;
    cin >> s >> pattern;

    findNext(pattern);
    KMP(s, pattern);

    for (int i = 1; i <= pattern.size(); i++)
        cout << KMPNext[i] << " ";
    cout << "\n";

    return 0;
}
