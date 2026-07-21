class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited)
    {
        visited[node] = true;

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
                dfs(neighbor, graph, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> graph(n);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool>visited(n,false);
        int count = 0;
        for (int i = 0; i<n; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, graph, visited);
            }
        }

        return count;
    }
};
