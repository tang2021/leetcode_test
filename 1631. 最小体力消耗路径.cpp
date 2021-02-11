// 1631. 最小体力消耗路径
// 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

// 一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

// 请你返回从左上角走到右下角的最小 体力消耗值 。
// 示例 1：
// 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
// 输出：2
// 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
// 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
// 示例 2：
// 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
// 输出：1
// 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
// 示例 3：
// 输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// 输出：0
// 解释：上图所示路径不需要消耗任何体力。
// 提示：
// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106
#include<vector>
#include<algorithm>
using namespace std;
class UnionFind{
    public:
    int n;
    int cnt;
    vector<int>parent;
    vector<int>rank;
    UnionFind(int _n):n(_n),cnt(_n),rank(_n,1),parent(_n){
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int x){
        if(x!=parent[x])
        parent[x]=find(parent[x]);
        return parent[x];
    }
    bool merge(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx==rooty)return false;
        if(rootx<rooty)swap(rootx,rooty);
        parent[rooty]=rootx;
        rank[rootx]+=rank[rooty];
        cnt--;
        return true;
    }
    bool connected(int x,int y){
        return find(x)==find(y);
    }
};

int minnumEffortPath(vector<vector<int>>&heights){
    int n=heights.size();
    int m=heights[0].size();
    UnionFind uf(n*m);
    vector<tuple<int,int,int>> edges;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        int id=i*m+j;
        if(i>0)edges.emplace_back(id-m,id,abs(heights[i][j]-heights[i-1][j]));
        if(j>0)edges.emplace_back(id-1,id,abs(heights[i][j],heights[i][j-1]));
    }
    sort(edges.begin(),edges.end(),[](const auto&x,const auto&y){
        auto&& [x1,x2,v1]= x;
        auto&& [y1,y2,v2]= y;
        return v1<v2;
    });
    int ans=0;
    for(auto [x,y,v]:edges){
        uf.merge(x,y);
        if(uf.connected(0,n*m-1)){
            ans=v;
            break;
        }
        
    }
    return ans;
}
