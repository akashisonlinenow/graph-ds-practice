//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        // Code here
        // refer striver
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // traverse first row and last row
        for (int i = 0; i < m; i++)
        {
            // first row
            if (!vis[0][i] && grid[0][i] == 1)
            {
                vis[0][i] = 1;
                q.push({0, i});
            }
            // last row
            if (!vis[n - 1][i] && grid[n - 1][i] == 1)
            {
                vis[n - 1][i] = 1;
                q.push({n - 1, i});
            }
        }

        // traverse first and last col
        for (int i = 0; i < n; i++)
        {
            // first col
            if (!vis[i][0] && grid[i][0] == 1)
            {
                vis[i][0] = 1;
                q.push({i, 0});
            }
            // last col
            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
            {
                vis[i][m - 1] = 1;
                q.push({i, m - 1});
            }
        }

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++)
            { // making the nieghbors connected to boundary 1s visited and pushing to q
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        int land = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            { // counting the no. of 1s in middle which is land
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    land++;
                }
            }
        }

        return land;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends