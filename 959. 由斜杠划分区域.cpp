// 959. 由斜杠划分区域
// 在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。
// （请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。
// 返回区域的数目。
// 示例 1：
// 输入：
// [
//   " /",
//   "/ "
// ]
// 输出：2
// 解释：2x2 网格如下：
// 示例 2：
// 输入：
// [
//   " /",
//   "  "
// ]
// 输出：1
// 解释：2x2 网格如下：
// 示例 3：
// 输入：
// [
//   "\\/",
//   "/\\"
// ]
// 输出：4
// 解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
// 2x2 网格如下：
// 示例 4：
// 输入：
// [
//   "/\\",
//   "\\/"
// ]
// 输出：5
// 解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
// 2x2 网格如下：
// 示例 5：
// 输入：
// [
//   "//",
//   "/ "
// ]
// 输出：3
// 解释：2x2 网格如下：
// 提示：
// 1 <= grid.length == grid[0].length <= 30
// grid[i][j] 是 '/'、'\'、或 ' '。
#include<vector>
#include<string>
using namespace std;

class UnionFind{
    private:
    int n;
    int cnt;
    public:
    vector<int>parent;
    UnionFind(int _n):n(_n),cnt(_n),parent(_n){
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int x){
        if(x!=parent[x]){
            parent[x]=parent[parent[x]];
            x=parent[x];
        }
        return x;
    }
    bool merge(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx==rooty)return false;
        if(rootx<rooty)swap(rootx,rooty);
        parent[rooty]=rootx;
        cnt--;
        return true;
    }
    int getCount(void){
        return cnt;
    }
};

int regionsBySlashes(vector<string>& grid) {
    int n=grid.size();
    UnionFind uf(n*n*4);
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        int idx=4*(i*n+j);
        if(grid[i][j]==' '){
            uf.merge(idx,idx+1);
            uf.merge(idx+1,idx+2);
            uf.merge(idx+2,idx+3);
        }else if(grid[i][j]=='/'){
            uf.merge(idx,idx+3);
            uf.merge(idx+1,idx+2);
        }else{
            uf.merge(idx,idx+1);
            uf.merge(idx+2,idx+3);
        }
        if(i+1<n){//单元格合并，当前1，右一 3
            uf.merge(idx+1,4*(n*i+j+1)+3);
        }
        if(j+1<n){//单元格合并，当前2，下一行 0
            uf.merge(idx+2,4*(n*(i+1)+j));
        }
    }
    return uf.getCount();
}