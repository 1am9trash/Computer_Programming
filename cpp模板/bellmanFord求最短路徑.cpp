#include <bits/stdc++.h>
using namespace std;

// bellman ford
// 確保有窮大加無窮大仍為無窮大
const int INF = 0x3f3f3f3f;

struct node {
    int vertex1;
    int vertex2;
    int weight;

    node() {}

    node(int vertex1, int vertex2, int weight)
        : vertex1(vertex1), vertex2(vertex2), weight(weight) {}
};

void bellmanFord(int num, vector<node> &edge, int start) {
    int size = edge.size();
    vector<int> dis(num + 1, INF);
    dis[start] = 0;

    // 若一輪鬆弛沒有改變，代表以為最短路徑
    // 最短路徑最多經過n - 1條邊（不會經過重複的vertex）
    bool flag;
    for (int i = 1; i <= num - 1; i++) {
        flag = 0;
        for (int j = 1; j < size; j++)
            if (dis[edge[j].vertex2] > dis[edge[j].vertex1] + edge[j].weight) {
                flag = 1;
                dis[edge[j].vertex2] = dis[edge[j].vertex1] + edge[j].weight;
            }
        if (!flag) break;
    }

    // 經過n - 1條邊還可鬆弛，代表存在負環
    for (int j = 1; j < size; j++)
        if (dis[edge[j].vertex2] > dis[edge[j].vertex1] + edge[j].weight) {
            cout << "含有負環\n";
            return;
        }

    for (int i = 1; i <= num; i++)
        cout << dis[i] << " ";
    cout << "\n";
}

int main() {
    int n, m, start;
    cin >> n >> m;

    vector<node> edge(m + 1);
    for (int i = 1; i <= m; i++) {
        int vertex1, vertex2, weight;
        cin >> vertex1 >> vertex2 >> weight;
        edge[i] = node(vertex1, vertex2, weight);
    }
    cin >> start;

    bellmanFord(n, edge, start);

    return 0;
}
