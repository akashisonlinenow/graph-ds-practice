//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // refer striver
        set<pair<int, int>> st;
        vector<int> dist(V);
        for (int i = 0; i < V; i++)
        {
            dist[i] = 1e9;
        }

        dist[S] = 0;
        st.insert({0, S}); // {dist,node}

        while (!st.empty())
        {
            auto it = *(st.begin()); // 'it' will point to address of st.begin() and * will give the value
            int node = it.second;
            int d = it.first;
            st.erase(it);

            for (auto it : adj[node])
            {
                // edgeweight and adjNode is taken here becos "it" here is not in int datatype its in vector<int> type
                int edgeWeight = it[1];
                int adjNode = it[0];
                if (d + edgeWeight < dist[adjNode])
                {
                    // erase if it existed
                    if (dist[adjNode] != 1e9)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = d + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends