//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool dfs(int node, int vis[], int pathvis[], vector<int> adj[], int check[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;

        // traverse the adjacent nodes
        for (auto it : adj[node])
        {
            // if the node is not visited
            if (!vis[it])
            {
                if (dfs(it, vis, pathvis, adj, check) == true)
                {
                    return true;
                }
            }
            // if the node has been previously visited but it has to be visited on same path
            else if (pathvis[it] == 1)
            {
                return true;
            }
        }

        check[node] = 1; // this ensures that there is no cycle and we are backtracking
        pathvis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        // refer striver utube
        int vis[V] = {0};
        int pathvis[V] = {0};
        int check[V] = {0};

        vector<int> safe;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, pathvis, adj, check);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
            {
                safe.push_back(i);
            }
        }

        return safe;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends