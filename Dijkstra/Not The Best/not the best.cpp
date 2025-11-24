#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n, r;
        cin >> n >> r;

        vector<vector<pii>> graph(n + 1);

        for (int i = 0; i < r; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> dist1(n + 1, INF);
        vector<int> dist2(n + 1, INF);

        dist1[1] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 1});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist2[u]) continue;

            for (auto &edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;
                int nd = d + w;

                if (nd < dist1[v]) {
                    dist2[v] = dist1[v];
                    dist1[v] = nd;
                    pq.push({nd, v});
                } else if (nd > dist1[v] && nd < dist2[v]) {
                    dist2[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        cout << "Case " << tc << ": " << dist2[n] << "\n";
    }

    return 0;
}
