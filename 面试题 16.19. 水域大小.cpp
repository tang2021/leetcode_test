// 面试题 16.19. 水域大小
// 你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。
// 示例：
// 输入：
// [
//   [0,2,1,0],
//   [0,1,0,1],
//   [1,1,0,1],
//   [0,1,0,1]
// ]
// 输出： [1,2,4]
// 提示：
// 0 < len(land) <= 1000
// 0 < len(land[i]) <= 1000
// 通过次数13,907提交次数22,922
#include<vector>
using namespace std;
vector<int>res;
int N,M;
vector<int> pondSizes(vector<vector<int>>& land) {
    N=land.size();
    M=land[0].size();
    int t=0;
    for(int i=0;i<N;i++)
    for(int j=0;j<M;j++){
        t=dfs(land,i,j);
        if(t!=0)res.push_back(t);
    }
    sort(res.begin(),res.end());
    return res;
}
int dfs(vector<vector<int>>&land,int row,int col){
    if(row<0||row>=N||col<0||col>=M||land[row][col]!=0)return 0;
    land[row][col]=-1;
    int up=dfs(land,row-1,col);
    int down=dfs(land,row+1,col);
    int left=dfs(land,row,col-1);
    int right=dfs(land,row,col+1);
    int upLeft=dfs(land,row-1,col-1);
    int downLeft=dfs(land,row+1,col-1);
    int upRight=dfs(land,row-1,col+1);
    int downRight=dfs(land,row+1,col+1);
    return up+down+left+right+upLeft+downLeft+upRight+downRight+1;
}