#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cas = 1;
    while (cin >> n && n) {
        vector<int> b(n+1);
        for(int i = 1; i <= n; i++) cin >> b[i];

        vector<vector<int>> g(n+1);
        int r; cin >> r;
        for(int i = 0; i < r; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }


        vector<int> dist(n+1, INT_MAX/2);
        dist[1] = b[1];
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.emplace(dist[1], 1);

        while(!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if(cost > dist[u]) continue;
            for(int v : g[u]) {
                int ncost = cost + b[v];
                if(ncost < dist[v]) {
                    dist[v] = ncost;
                    pq.emplace(ncost, v);
                }
            }
        }

        int q; cin >> q;
        cout << "Set #" << cas++ << "\n";
        for(int i = 0; i < q; i++) {
            int d; cin >> d;
            if(dist[d] < 3) {
                cout << d << "\n";
            }
        }
    }
    return 0;
}
