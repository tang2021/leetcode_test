// 118. 杨辉三角
// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
// 在杨辉三角中，每个数是它左上方和右上方的数的和。
// 示例:
// 输入: 5
// 输出:
// [
     // [1],
    // [1,1],
   // [1,2,1],
  // [1,3,3,1],
 // [1,4,6,4,1]
// ]
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i=0;i<numRows;i++){
       vector<int> lvl(i+1,1);
       for(int j=1;j<i;j++){
           lvl[j]=ans[i-1][j-1]+ans[i-1][j];
       }
       ans.push_back(lvl);
    }
    return ans;
}