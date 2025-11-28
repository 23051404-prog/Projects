#include <bits/stdc++.h>
using namespace std;

int dxA[4] = {1, -1, 0, 0};
int dyA[4] = {0, 0, 1, -1};

bool valid(int x, int y, int n, int m, const vector<vector<int>>& grid) {
    return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0);
}

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid (0 = empty, 1 = blocked):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    int sx, sy, dx, dy;
    cout << "Enter source (row col): ";
    cin >> sx >> sy;
    cout << "Enter destination (row col): ";
    cin >> dx >> dy;

    // basic validation
    if (!valid(sx, sy, n, m, grid)) {
        cout << "Source is invalid or blocked\n";
        return 0;
    }
    if (!valid(dx, dy, n, m, grid)) {
        cout << "Destination is invalid or blocked\n";
        return 0;
    }

    queue<pair<int,int>> q;
    q.push(make_pair(sx, sy));

    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dxA[k];
            int ny = y + dyA[k];

            if (valid(nx, ny, n, m, grid) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    cout << "\nShortest Distance = " << dist[dx][dy] << "\n";
    if (dist[dx][dy] == -1)
        cout << "Destination is NOT reachable\n";
    else
        cout << "Destination is reachable\n";

    return 0;
}
