// 695. 岛屿的最大面积
// 给定一个包含了一些 0 和 1 的非空二维数组 grid 。
// 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
// 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
// 示例 1:
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
// 示例 2:
// [[0,0,0,0,0,0,0,0]]
// 对于上面这个给定的矩阵, 返回 0。
// 注意: 给定的矩阵grid 的长度和宽度都不超过 50。
#include<vector>
using namespace std;
int n,m;
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int res=0;
    n=grid.size();
    m=grid[0].size();
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        if(grid[i][j]==1){
            res=max(res,dfs(grid,i,j));
        }
    }   
    return res;
}
int dfs(vector<vector<int>>&grid,int row,int col){
    if(row<0||row>=n||col<0||col>=m||grid[row][col]==0)return 0;
    grid[row][col]=0;
    int up = dfs(grid,row-1,col);
    int down =dfs(grid,row+1,col);
    int left = dfs(grid,row,col-1);
    int right = dfs(grid,row,col+1);
    return up+down+left+right+1;
}