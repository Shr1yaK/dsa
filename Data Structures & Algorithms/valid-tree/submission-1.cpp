class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited)
    {
        visited[node] = true;

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, node, graph, visited))
                    return true;
            }

            else if (neighbor!=parent)
                return true;    //visited but not parent->cycle
        }
        
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> graph(n);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        if (dfs(0, -1, graph, visited)) return false; //i.e. cycle exists -> not valid tree

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])    return false; //not connected -> not valid tree
        }
        
        return true;
    }
};
