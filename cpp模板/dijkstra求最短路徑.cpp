#include <bits/stdc++.h>
using namespace std;

// dijkstra，鄰接矩陣
// 確保有窮大加無窮大仍為無窮大
const int INF = 0x3f3f3f3f;

struct node {
    int index;
    int distance;

    node(int index, int distance) : index(index), distance(distance) {}

    bool operator<(const node &compare) const {
        return distance > compare.distance;
    }
};

// 每次將還未到達vertex最近者設為已到達，鬆弛
void dijkstra(vector<vector<int>> &data, int start) {
    // q用最小堆優化尋找最小路徑
    int size = data[0].size();

    vector<int> dis(size, INF);
    vector<bool> visited(size, 0);
    priority_queue<node> q;

    dis[start] = 0;
    q.push(node(start, 0));

    while (!q.empty()) {
        node temp = q.top();
        q.pop();

        if (visited[temp.index]) continue;
        visited[temp.index] = 1;

        for (int i = 1; i < size; i++)
            if (!visited[i]) {
                if (dis[i] > dis[temp.index] + data[temp.index][i]) {
                    dis[i] = dis[temp.index] + data[temp.index][i];
                    q.push(node(i, dis[i]));
                }
            }
    }

    for (int i = 1; i < size; i++)
        cout << dis[i] << " ";
    cout << "\n";
}

int main() {
    // n vertex個數，m edge個數，start single source
    int n, m, start;
    cin >> n >> m;

    vector<int> partOfData(n + 1, INF);
    vector<vector<int>> data(n + 1, partOfData);
    for (int i = 1; i <= n; i++)
        data[i][i] = 0;

    for (int i = 1; i <= m; i++) {
        int vertex1, vertex2, weight;
        cin >> vertex1 >> vertex2 >> weight;
        data[vertex1][vertex2] = weight;
    }
    cin >> start;

    dijkstra(data, start);

    return 0;
}
