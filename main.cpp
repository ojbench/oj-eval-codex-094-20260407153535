#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<vector<int>> g(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    // Precompute A-class and B-class center coordinates for each subcell (dx,dy)
    // dx,dy in {0,1,2}
    vector<pair<int,int>> A[3][3];
    vector<pair<int,int>> B[3][3];
    for (int dx = 0; dx < 3; ++dx) {
        for (int dy = 0; dy < 3; ++dy) {
            // Position inside the 3x3 block with center at (1,1)
            int x = dx - 1;
            int y = dy - 1;
            for (int cx = -1; cx <= 1; ++cx) {
                for (int cy = -1; cy <= 1; ++cy) {
                    if (cx == 0 && cy == 0) continue; // exclude self center to classify neighbors
                    int dist = abs(x - 0 - 3*cx) + abs(y - 0 - 3*cy); // but simpler: classify by |x-3cx|+|y-3cy|
                }
            }
        }
    }
    // However classification above by direct centers is cumbersome; use simpler approach per output cell.

    auto get_value = [&](int i, int j, int dx, int dy) -> int {
        // i in [0,m), j in [0,n), dx,dy in [0,2]
        // Center point if dx==1 && dy==1
        if (dx == 1 && dy == 1) return g[i][j];

        // Collect A and B class centers around this subcell.
        // A: Manhattan distance 1, B: Manhattan distance 2, in the refined grid of centers spaced at 3.
        // The contribution centers are the 3x3 neighbors of center (i,j) with offsets in {-1,0,1}.
        double sumA = 0.0, sumB = 0.0; int cntA = 0, cntB = 0;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                int ci = i + di;
                int cj = j + dj;
                if (ci < 0 || ci >= m || cj < 0 || cj >= n) continue;
                // The center (i+di,j+dj) has refined-grid coordinate at (3*i+1+3*di, 3*j+1+3*dj)
                int cx = 1 + 3*di;
                int cy = 1 + 3*dj;
                int dist = abs(dx - cx) + abs(dy - cy);
                if (dist == 1) { sumA += g[ci][cj]; cntA++; }
                else if (dist == 2) { sumB += g[ci][cj]; cntB++; }
            }
        }
        if (cntA == 0 && cntB == 0) return 0; // should not happen
        if (cntA == 0) return (int)floor(sumB / cntB + 1e-9);
        if (cntB == 0) return (int)floor(sumA / cntA + 1e-9);
        double val = (sumA / cntA) * 0.8 + (sumB / cntB) * 0.2;
        int res = (int)floor(val + 1e-9);
        if (res < 0) res = 0;
        if (res > 100) res = 100;
        return res;
    };

    int H = 3 * m, W = 3 * n;
    for (int i = 0; i < m; ++i) {
        for (int dx = 0; dx < 3; ++dx) {
            // build row
            for (int j = 0; j < n; ++j) {
                for (int dy = 0; dy < 3; ++dy) {
                    int val = get_value(i, j, dx, dy);
                    cout << val << ' ';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}

