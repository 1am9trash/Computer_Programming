#include <bits/stdc++.h>
using namespace std;

// 數組最小堆
#define MAXN 1000001

struct minHeap {
    int heap[MAXN];
    int size;
    int maxSize;
};

void minHeapDown(minHeap &h, int pos) {
    h.heap[0] = h.heap[pos];
    while (pos <= h.size / 2) {
        if (h.size == pos * 2) {
            if (h.heap[0] > h.heap[pos * 2]) {
                h.heap[pos] = h.heap[pos * 2];
                pos *= 2;
            } else
                break;
        } else {
            int minValue, minPos;
            if (h.heap[pos * 2] <= h.heap[pos * 2 + 1]) {
                minValue = h.heap[pos * 2];
                minPos = pos * 2;
            } else {
                minValue = h.heap[pos * 2 + 1];
                minPos = pos * 2 + 1;
            }

            if (h.heap[0] > minValue) {
                h.heap[pos] = h.heap[minPos];
                pos = minPos;
            } else
                break;
        }
    }
    h.heap[pos] = h.heap[0];
}

void minHeapUp(minHeap &h, int pos) {
    h.heap[0] = h.heap[pos];
    while (pos > 1) {
        if (h.heap[0] < h.heap[pos / 2]) {
            h.heap[pos] = h.heap[pos / 2];
            pos /= 2;
        } else
            break;
    }
    h.heap[pos] = h.heap[0];
}

// 隨機數組構建最小堆
void minHeapInit(minHeap &h) {
    for (int i = h.size / 2; i >= 1; i--)
        minHeapDown(h, i);
}

// 插入元素，維護最小堆
void minHeapInsert(minHeap &h, int num) {
    h.heap[++h.size] = num;
    minHeapUp(h, h.size);
}

// 刪除頂點（最小點），維護最小堆
void minHeapDelete(minHeap &h) {
    if (h.size == 0) return;

    h.heap[1] = h.heap[h.size--];
    minHeapDown(h, 1);
}

int main() {
    minHeap h;
    h.maxSize = MAXN - 1;

    // 輸入最小堆大小，輸入n個數，構建最小堆
    int size;
    cin >> size;
    h.size = size;
    for (int i = 0; i < size; i++)
        cin >> h.heap[i + 1];

    minHeapInit(h);
    for (int i = 0; i < size; i++) {
        cout << h.heap[1] << "\n";
        minHeapDelete(h);
    }

    return 0;
}
