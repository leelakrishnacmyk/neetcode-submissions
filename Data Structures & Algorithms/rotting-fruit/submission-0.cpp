class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      int fresh=0;
      queue<pair<int,pair<int,int>>>q;
      for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j]==2){
            q.push({0,{i,j}});
            }
            if (grid[i][j]==1){
                fresh++;
            }
        }
      }
       int dr[] = {-1, 1, 0, 0};
       int dc[] = {0, 0, -1, 1};
       int time=0;
      while(!q.empty()){
        auto c=q.front();
        q.pop();
        int t=c.first;
        int r=c.second.second;
        int p=c.second.first;
        time=max(t,time);
        for (int i=0;i<4;i++){
            int nr=p+dr[i];
            int nc=r+dc[i];
             if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == 1) {
                        grid[nr][nc]=2;
                     q.push({t+1,{nr,nc}});
                     fresh--;
                    }
                                         
        }
      }
      if (fresh>0){
        return -1;
      }
    return time;
    }
};
