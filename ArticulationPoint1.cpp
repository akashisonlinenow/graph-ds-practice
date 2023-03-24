//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
             vector<int> &mark, vector<int> adj[])
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0; // child count maintained to know that if src node has multiple children or not

        // going through all the adjacent nodes of the node
        for (auto it : adj[node])
        {
            // if adjacent node is parent then dont update anything jst continue
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);

                // if u cannot reach somewhere before me and u are not a source node
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            { // if its visited

                // NOTE - here I will not take low for adjacent node i.e. 'it' instead I will take tin.
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
        { // if src node has more than children then it is articulation point
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<int> adj[])
    {

        // refer striver
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0); // which marks which are articulation point

        // there can be multiple component present so just scrolling through all
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans; // stores articulation point
        for (int i = 0; i < n; i++)
        {
            if (mark[i] == 1)
            { // pushing articulation points to ans
                ans.push_back(i);
            }
        }

        // if no articulation point present
        if (ans.size() == 0)
            return {-1};

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends