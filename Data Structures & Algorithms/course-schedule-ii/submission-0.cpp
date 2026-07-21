class Solution {
public:
    vector<int> order;
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited)
    {
        visited[node] = true;
        pathVisited[node] = true;

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, graph, visited, pathVisited))
                    return true;
            }

            else if (pathVisited[neighbor])
                return true;
        }
        pathVisited[node] = false;
        order.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites)
        {
            int course = edge[0];
            int prereq = edge[1];

            graph[prereq].push_back(course);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, graph, visited, pathVisited))
                    return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};