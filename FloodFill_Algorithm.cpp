//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newcolor, int delrow[], int delcol[], int inicolor)
    {
        ans[row][col] = newcolor; // fist assign newcolor to the first traversed cell
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor)
            { // valididty condition -> nrow and ncol is inside image, neighboring cell should be inicolr, in ans neighboring cell should not be filled with newcolor
                dfs(nrow, ncol, ans, image, newcolor, delrow, delcol, inicolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newcolor)
    {
        // Code here
        vector<vector<int>> ans = image; // initialize ans as given image first
        int inicolor = image[sr][sc];    // initial color
        int delrow[] = {-1, 0, 1, 0};    // delrow and delcol is diff between neighboring row and col
        int delcol[] = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, newcolor, delrow, delcol, inicolor);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends