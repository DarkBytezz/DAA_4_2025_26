#include <bits/stdc++.h>
using namespace std;

bool solve(int pos, vector<int>& path, vector<vector<int>>& adj, int n) {

    if (pos == n) {

        for (int x : adj[path[n - 1]]) {
            if (x == path[0])
                return true;
        }
        return false;
    }

    for (int v = 0; v < n; v++) {

        bool used = false;
        for (int i = 0; i < pos; i++) {
            if (path[i] == v)
                used = true;
        }
        if (used) continue;
        bool edge = false;
        for (int x : adj[path[pos - 1]]) {
            if (x == v)
                edge = true;
        }
        if (!edge) continue;

        path[pos] = v;

        if (solve(pos + 1, path, adj, n))
            return true;

        path[pos] = -1;
    }

    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 2, 3};
    adj[2] = {0, 1, 3};
    adj[3] = {1, 2};

    vector<int> path(n, -1);
    path[0] = 0;

    if (solve(1, path, adj, n)) {
        cout << "Hamiltonian Cycle:\n";
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << path[0];
    } else {
        cout << "No Hamiltonian Cycle";
    }
}
