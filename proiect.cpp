#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> R(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        R[i][i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        R[u][v] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (R[i][j] == 0) {
                    R[i][j] = R[i][k] && R[k][j];
                }
            }
        }
    }
    vector<bool> vizitat(n + 1, false);
    cout << "Componentele tare conexe sunt:\n";
    for (int i = 1; i <= n; ++i) {
        if (!vizitat[i]) {
            cout << "{ ";
            for (int j = 1; j <= n; ++j) {
                if (R[i][j] == 1 && R[j][i] == 1) {
                    cout << j << " ";
                    vizitat[j] = true;
                }
            }
            cout << "}\n";
        }
    }
  return 0;
}
