#include <bits/stdc++.h>
using namespace std;

// 數組最大堆
#define MAXN 1000001

struct maxHeap {
    int heap[MAXN];
    int size;
    int maxSize;
};

void maxHeapDown(maxHeap &h, int pos) {
    h.heap[0] = h.heap[pos];
    while (pos <= h.size / 2) {
        if (h.size == pos * 2) {
            if (h.heap[0] < h.heap[pos * 2]) {
                h.heap[pos] = h.heap[pos * 2];
                pos *= 2;
            } else
                break;
        } else {
            int maxValue, maxPos;
            if (h.heap[pos * 2] >= h.heap[pos * 2 + 1]) {
                maxValue = h.heap[pos * 2];
                maxPos = pos * 2;
            } else {
                maxValue = h.heap[pos * 2 + 1];
                maxPos = pos * 2 + 1;
            }

            if (h.heap[0] < maxValue) {
                h.heap[pos] = h.heap[maxPos];
                pos = maxPos;
            } else
                break;
        }
    }
    h.heap[pos] = h.heap[0];
}

void maxHeapUp(maxHeap &h, int pos) {
    h.heap[0] = h.heap[pos];
    while (pos > 1) {
        if (h.heap[0] > h.heap[pos / 2]) {
            h.heap[pos] = h.heap[pos / 2];
            pos /= 2;
        } else
            break;
    }
    h.heap[pos] = h.heap[0];
}

// 隨機數組構建最大堆
void maxHeapInit(maxHeap &h) {
    for (int i = h.size / 2; i >= 1; i--)
        maxHeapDown(h, i);
}

// 插入元素，維護最大堆
void maxHeapInsert(maxHeap &h, int num) {
    h.heap[++h.size] = num;
    maxHeapUp(h, h.size);
}

// 刪除頂點（最大點），維護最大堆
void maxHeapDelete(maxHeap &h) {
    if (h.size == 0) return;

    h.heap[1] = h.heap[h.size--];
    maxHeapDown(h, 1);
}

int main() {
    maxHeap h;
    h.maxSize = MAXN - 1;

    // 輸入最大堆大小，輸入n個數，構建最大堆
    int size;
    cin >> size;
    h.size = size;
    for (int i = 0; i < size; i++)
        cin >> h.heap[i + 1];

    maxHeapInit(h);
    for (int i = 0; i < size; i++) {
        cout << h.heap[1] << "\n";
        maxHeapDelete(h);
    }

    return 0;
}
