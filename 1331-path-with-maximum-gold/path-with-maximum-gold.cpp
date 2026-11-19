class Solution {
private:
    int dfs(vector<vector<int>>& grid, int x, int y, int n, int m, vector<vector<int>>& visited) {
        
        //base case
        if (x < 0 || y < 0 || x >= n || y >= m ||
            grid[x][y] == 0 || visited[x][y] == 1) {
            return 0;
        }

        visited[x][y] = 1;

        int gold = grid[x][y];

        int up = dfs(grid, x - 1, y, n, m, visited);
        int down = dfs(grid, x + 1, y, n, m, visited);
        int left = dfs(grid, x, y - 1, n, m, visited);
        int right = dfs(grid, x, y + 1, n, m, visited);


        visited[x][y] = 0;

        return gold + max({up, down, left, right});

    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, i, j, n, m, visited));
                }
            }
        }
    return ans;
    }
};