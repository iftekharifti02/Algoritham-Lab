#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testSet = 1;

    while (true) {
        int k;


        if (!(cin >> k)) break;
        if (k == 0) break;

        vector<vector<int>> adj(21);


        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            adj[1].push_back(v);
            adj[v].push_back(1);
        }


        for (int i = 2; i <= 19; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                int v;
                cin >> v;
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
        }

        int N;
        cin >> N;

        cout << "Test Set " << testSet++ << "\n";

        while (N--) {
            int s, t;
            cin >> s >> t;

            vector<int> dist(21, -1);
            queue<int> q;

            dist[s] = 0;
            q.push(s);

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            cout << setw(2) << s
                 << " to "
                 << setw(2) << t
                 << " : "
                 << dist[t] << "\n";
        }

        cout << "\n";
    }

    return 0;
}
