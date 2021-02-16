// 200. 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。
// 示例 1：
// 输入：grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// 输出：1
// 示例 2：
// 输入：grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// 输出：3
// 提示：
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] 的值为 '0' 或 '1'
#include<vector>
#include<string>
using namespace std;
class UnionFind{
    public:
    int n,cnt;
    vector<int>rank,parent;
    UnionFind(int _n):n(_n),cnt(_n),rank(_n,1),parent(_n){
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int x){
        if(x!=parent[x])
        parent[x]=find(parent[x]);
        return parent[x];
    }
    bool connected(int x,int y){
        return find(x)==find(y);
    }
    bool merge(int x,int y ){
        x=find(x);
        y=find(y);
        if(x==y)return false;
        if(x<y)swap(x,y);
        parent[y]=x;
        rank[x]+=rank[y];
        cnt--;
        return true;
    }
    int getCount(void){
        return cnt;
    }
};
int numIslands(vector<vector<int>>&grids){
    int n=grids.size();
    int m=grids[0].size();
    UnionFind uf(n*m);
    int space=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        int id=i*m+j;
        if(grids[i][j]=='0'){
            space++;
            continue;
        }
        if(i>0&&grids[i-1][j]=='1')uf.merge(id,id-m);
        if(j>0&&grids[i][j-1]=='1')uf.merge(id,id-1);
    }
    return uf.getCount()-space;
}