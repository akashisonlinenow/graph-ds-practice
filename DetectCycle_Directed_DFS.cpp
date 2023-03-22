//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int node, int vis[], int pathvis[], vector<int> adj[])
    {
        vis[node] = 1;
        pathvis[node] = 1;

        // traverse for adjacent nodes
        for (auto it : adj[node])
        {
            // when the node is not visited
            if (!vis[it])
            {
                if (dfs(it, vis, pathvis, adj) == true)
                {
                    return true;
                }
            }
            // if the node has been previously visited but it has to be visited on the same path
            else if (pathvis[it] == 1)
            {
                return true;
            }
        }
        pathvis[node] = 0; // when we reach the end to path and never found a cycle then while backtrack make all node of pathvis as 0
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        // refer striver
        int vis[V] = {0};
        int pathvis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, pathvis, adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends