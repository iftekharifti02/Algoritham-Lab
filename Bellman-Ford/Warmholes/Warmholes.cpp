#include <bits/stdc++.h>
using namespace std;

struct Wormhole {
    int from, to, time;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    for (int cas = 0; cas < c; ++cas) {
        int n, m;
        cin >> n >> m;

        vector<Wormhole> edges;
        edges.reserve(m);

        for (int i = 0; i < m; ++i) {
            int x, y, t;
            cin >> x >> y >> t;
            edges.push_back({x, y, t});
        }


        vector<long long> dist(n, 1e18);
        dist[0] = 0;


        for (int i = 0; i < n - 1; ++i) {
            for (auto& e : edges) {
                if (dist[e.from] != 1e18) {
                    dist[e.to] = min(dist[e.to], dist[e.from] + e.time);
                }
            }
        }


        bool hasNegativeCycle = false;
        for (auto& e : edges) {
            if (dist[e.from] != 1e18 && dist[e.from] + e.time < dist[e.to]) {
                hasNegativeCycle = true;
                break;
            }
        }

        if (hasNegativeCycle) {
            cout << "possible\n";
        } else {
            cout << "not possible\n";
        }
    }

    return 0;
}
