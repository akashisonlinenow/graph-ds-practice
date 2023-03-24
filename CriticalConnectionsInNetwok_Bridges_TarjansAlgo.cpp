// leetcode - Critical connections in a network

class Solution
{

private:
    int timer = 1;

private:
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for (auto it : adj[node])
        {
            // if adj node is parent dont do anything
            if (it == parent)
                continue;

            // if its unvisited call dfs
            if (!vis[it])
            {
                dfs(it, node, vis, adj, tin, low, bridges);
                // after dfs of it completes it comes back, then node says whats your lowest step give it to me
                low[node] = min(low[node], low[it]);

                // can this node --> it be a bridge?
                if (low[it] > tin[node])
                { // then it is a bridge
                    bridges.push_back({it, node});
                }
            }

            // if its visited
            else
            { // then it cannot be a bridge just take low of node
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        // refer striver

        // graph creation -> undirected to directed
        vector<int> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};