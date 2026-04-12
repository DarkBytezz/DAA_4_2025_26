#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    for(int i = 0; i <= k; i++) {
        vector<int> temp = dist;

        for(auto &f : flights) {
            int u = f[0];
            int v = f[1];
            int cost = f[2];

            if(dist[u] == 1e9) continue;

            if(dist[u] + cost < temp[v]) {
                temp[v] = dist[u] + cost;
            }
        }
        dist = temp;
    }

    return (dist[dst] == 1e9) ? -1 : dist[dst];
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100},
        {2,3,100},
        {0,2,500}
    };

    int src = 0, dst = 3, k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k);
}




//Time complexity: O(K * E)
// Space Complexity: O(N)

/*Algo: 
Steps:
    Initialize distance array with infinity.
    Set dist[src] = 0.
    Repeat relaxation process k+1 times:
        Copy current distances into a temp array.
        For each flight (u → v):
            If reaching u is possible, try updating v.
    Return distance of destination if reachable, else -1.
*/