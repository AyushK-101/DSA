1class Solution {
2public:
3    int minPathSum(vector<vector<int>>& grid) {
4        for(int i=1;i<grid.size();i++){
5            grid[i][0]+=grid[i-1][0];
6        }
7        for(int j=1;j<grid[0].size();j++){
8            grid[0][j]+=grid[0][j-1];
9        }
10
11        for(int i=1;i<grid.size();i++){
12            for(int j=1;j<grid[0].size();j++){
13                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
14            }
15        }
16
17        return grid.back().back();
18    }
19};