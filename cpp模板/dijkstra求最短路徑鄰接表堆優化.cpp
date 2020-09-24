#include <bits/stdc++.h>
using namespace std;

// dijkstra，鄰接表，堆優化
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

void dijkstra(int num, vector<vector<node>> &edge, int start) {
    vector<int> dis(num, INF);
    vector<bool> visited(num, 0);

    dis[start] = 0;
    priority_queue<node> q;

    q.push(node(start, 0));

    while (!q.empty()) {
        node temp = q.top();
        q.pop();

        if (visited[temp.index]) continue;
        visited[temp.index] = 1;

        for (int i = 0; i < int(edge[temp.index].size()); i++)
            if (!visited[edge[temp.index][i].index]) {
                if (dis[edge[temp.index][i].index] > dis[temp.index] + edge[temp.index][i].distance) {
                    dis[edge[temp.index][i].index] = dis[temp.index] + edge[temp.index][i].distance;
                    q.push(node(edge[temp.index][i].index, dis[edge[temp.index][i].index]));
                }
            }
    }

    for (int i = 0; i < num; i++)
        cout << dis[i] << " ";
    cout << "\n";
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    vector<node> partOfEdge;
    vector<vector<node>> edge(n, partOfEdge);

    for (int i = 0; i < m; i++) {
        int vertex1, vertex2, weight;
        cin >> vertex1 >> vertex2 >> weight;
        edge[vertex1].push_back(node(vertex2, weight));
    }

    dijkstra(n, edge, start);

    return 0;
}
