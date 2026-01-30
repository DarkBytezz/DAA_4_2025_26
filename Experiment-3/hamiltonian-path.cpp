//Question submitted on GFG in class

class Solution {
  public:
    
    vector<vector<int>>adjList(vector<vector<int>>edges, int n){
        vector<vector<int>>ans(n);
        for (int i = 0; i <edges.size(); ++i){
            ans[edges[i][0]].push_back(edges[i][1]);
            ans[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        return ans;
        
    }
    bool dfs(int it, vector<vector<int>>&adj, vector<bool>vis, int count, int n){
        if(count == n)return true;
        
        for (int temp: adj[it]) {
            if (!vis[temp]) {
                vis[temp] = true;
                if(dfs(temp, adj, vis, count+1, n))return true;
                else vis[temp] = false;
                
            }
        }
        return false;
    }
    
    bool check(int n, int m, vector<vector<int>> edges) {
        vector<vector<int>> adj = adjList(edges, n+1);

        for (int i = 1; i < n+1; i++) {
            vector<bool> visited(n+1, false);
            visited[i] = true;
            if (dfs(i, adj, visited, 1, n))
                return true;
        }
        return false;
        
    }
};
