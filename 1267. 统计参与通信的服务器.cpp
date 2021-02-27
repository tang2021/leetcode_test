// 1267. 统计参与通信的服务器
// 这里有一幅服务器分布图，服务器的位置标识在 m * n 的整数矩阵网格 grid 中，1 表示单元格上有服务器，0 表示没有。
// 如果两台服务器位于同一行或者同一列，我们就认为它们之间可以进行通信。
// 请你统计并返回能够与至少一台其他服务器进行通信的服务器的数量。
// 示例 1：
// 输入：grid = [[1,0],[0,1]]
// 输出：0
// 解释：没有一台服务器能与其他服务器进行通信。
// 示例 2：
// 输入：grid = [[1,0],[1,1]]
// 输出：3
// 解释：所有这些服务器都至少可以与一台别的服务器进行通信。
// 示例 3：
// 输入：grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
// 输出：4
// 解释：第一行的两台服务器互相通信，第三列的两台服务器互相通信，但右下角的服务器无法与其他服务器通信。
#include<vector>
using namespace std;
int N,M;
int countServers(vector<vector<int>>& grid) {
    int ans =0,cnt=0;
    M=grid.size();
    if(M<1)return 0;
    N=grid[0].size();
    for(int i=0;i<M;i++)
    for(int j=0;j<N;j++){
        if(grid[i][j]==1){
            cnt=0;
            cnt=back_track(grid,i,j);
            if(cnt>1)ans+=cnt;
        }
    }
    return ans;
}
int back_track(vector<vector<int>>&grid,int row,int col){
    if(row<0||row>=M||col<0||col>=N||grid[row][col]!=1)return 0;
    grid[row][col]=-1;
    int ans=1;
    for(int i=0;i<N;i++) if(grid[row][i]==1) ans+=back_track(grid,row,i);
    for(int i=0;i<M;i++) if(grid[i][col]==1) ans+=back_track(grid,i,col);
    return ans;
}