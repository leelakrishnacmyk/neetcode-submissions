class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxarea=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1){
                  int area=dfs(grid,i,j);
                  maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
    int dfs(vector<vector<int>>& grid,int i, int j){
        int row=grid.size();
        int col=grid[0].size();
        if (i<0|| i>=row || j<0 ||j>=col|| grid[i][j]==0){
            return 0;
        }
       grid[i][j]=0;
       int area=1;
       area+=dfs(grid,i-1,j);
       area+=dfs(grid,i,j-1);
       area+=dfs(grid,i+1,j);
       area+=dfs(grid,i,j+1);
       return area;
    }
};
