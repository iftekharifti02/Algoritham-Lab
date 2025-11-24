#include <bits/stdc++.h>
using namespace std;

pair<int, int> pos(string s) {
    return {s[0] - 'a', s[1] - '1'};
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string A, B;
        ss >> A >> B;

        if (A == B) {
            cout << "To get from " << A << " to " << B << " takes 0 knight moves." << endl;
            continue;
        }

        pair<int, int> start = pos(A);
        pair<int, int> goal = pos(B);

        queue<pair<int, int>> q;
        map<pair<int, int>, int> dist;

        q.push(start);
        dist[start] = 0;

        int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
        int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (make_pair(x, y) == goal) {
                cout << "To get from " << A << " to " << B
                     << " takes " << dist[{x, y}] << " knight moves." << endl;
                break;
            }

            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                pair<int, int> np = {nx, ny};

                if (dist.find(np) == dist.end()) {
                    dist[np] = dist[{x, y}] + 1;
                    q.push(np);
                }
            }
        }
    }
    return 0;
}
