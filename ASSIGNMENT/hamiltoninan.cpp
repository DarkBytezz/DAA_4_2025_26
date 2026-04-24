#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if(graph[path[pos-1]][v] == 0) return false;

    for(int i = 0; i < pos; i++)
        if(path[i] == v) return false;

    return true;
}

bool solve(vector<vector<int>>& graph, vector<int>& path, int pos, int V) {
    if(pos == V) {
        return graph[path[pos-1]][path[0]] == 1;
    }

    for(int v = 1; v < V; v++) {
        if(isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if(solve(graph, path, pos + 1, V)) return true;

            path[pos] = -1;
        }
    }

    return false;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> path(V, -1);
    path[0] = 0;

    if(!solve(graph, path, 1, V)) {
        cout << "No Hamiltonian Cycle exists (false)\n";
        return 0;
    }

    cout << "Hamiltonian Cycle:\n";
    for(int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;

    return 0;
}