#include <iostream>
using namespace std;

// 歐拉函數打表
#define MAXN 100000
int e[MAXN];

void eular() {
    for (int i = 2; i < MAXN; i++)
        // e[i]仍為0，代表i不是任何質數倍數，i為質數
        if (!e[i])
            for (int j = i; j < MAXN; j += i) {
                // 對所有有i質因數的數做處理
                if (!e[j]) e[j] = j;
                e[j] = e[j] * (i - 1) / i;
            }
}

int main() {
    eular();
    return 0;
}
