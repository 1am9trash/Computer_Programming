#include <bits/stdc++.h>
using namespace std;

// 單調隊列，維護區間最值
#define MAXN 1000001

// a數組內容, q單調隊列, p下標
// size使用位數
// head, tail紀錄q, p起始結束位置
struct monotoneQueue {
    int a[MAXN];
    int q[MAXN];
    int p[MAXN];
    int size;
    int head, tail;
};

void monotoneQueueInit(monotoneQueue &m, int size) {
    m.head = 1;
    m.tail = 0;
    m.size = size;
}

void monotoneQueueMax(monotoneQueue &m, int len) {
    for (int i = 0; i < m.size; i++) {
        while (m.head <= m.tail) {
            if (m.q[m.tail] <= m.a[i])
                m.tail--;
            else
                break;
        }
        m.tail++;
        m.q[m.tail] = m.a[i];
        m.p[m.tail] = i;

        while (m.head < m.tail) {
            if (m.p[m.tail] - m.p[m.head] >= len)
                m.head++;
            else
                break;
        }
        if (i >= len - 1)
            cout << m.q[m.head] << " ";
    }
    cout << "\n";
    monotoneQueueInit(m, m.size);
}

void monotoneQueueMin(monotoneQueue &m, int len) {
    for (int i = 0; i < m.size; i++) {
        while (m.head <= m.tail) {
            if (m.q[m.tail] >= m.a[i])
                m.tail--;
            else
                break;
        }
        m.tail++;
        m.q[m.tail] = m.a[i];
        m.p[m.tail] = i;

        while (m.head < m.tail) {
            if (m.p[m.tail] - m.p[m.head] >= len)
                m.head++;
            else
                break;
        }
        if (i >= len - 1)
            cout << m.q[m.head] << " ";
    }
    cout << "\n";
    monotoneQueueInit(m, m.size);
}

int main() {
    monotoneQueue mQ;
    int size, len;
    cin >> size >> len;
    for (int i = 0; i < size; i++)
        cin >> mQ.a[i];

    monotoneQueueInit(mQ, size);
    monotoneQueueMin(mQ, len);
    monotoneQueueMax(mQ, len);

    return 0;
}
