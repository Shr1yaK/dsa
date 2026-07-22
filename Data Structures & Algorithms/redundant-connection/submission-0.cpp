class Solution {
public:
    int find (int node, vector <int>& parent)
    {
        if (parent[node]==node) return node;
        return parent[node]=find(parent[node], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        vector<int> parent(edges.size() + 1);
        for (int i = 1; i<=edges.size(); i++)
            parent[i]=i;
        
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            int leader_u = find(u, parent);
            int leader_v = find(v, parent);

            if (leader_u == leader_v)
                return edge;

            parent[leader_v] = leader_u; //union operation
        }
        return {};
    }
};