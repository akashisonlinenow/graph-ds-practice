//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid)
    {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size(), m = grid[0].size();
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse neighbours and marks if it is land
            for (int delrow = -1; delrow <= 1; delrow++)
            { // diff between the actual node and its neighbours in col and rows are -1,0,1
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow; // neighbour row
                    int ncol = col + delcol; // neighbour col
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0)
                    { // condition if nrow and ncol lies between nxm in grid it is land and it is unvisited
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size(), m = grid[0].size(); // refer striver utube
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (vis[row][col] == 0 && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends