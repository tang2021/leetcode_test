// 1289. 下降路径最小和  II
// 给你一个整数方阵 arr ，定义「非零偏移下降路径」为：从 arr 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。
// 请你返回非零偏移下降路径数字和的最小值。
// 示例 1：
// 输入：arr = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：13
// 解释：
// 所有非零偏移下降路径包括：
// [1,5,9], [1,5,7], [1,6,7], [1,6,8],
// [2,4,8], [2,4,9], [2,6,7], [2,6,8],
// [3,4,8], [3,4,9], [3,5,7], [3,5,9]
// 下降路径中数字和最小的是 [1,5,7] ，所以答案是 13 。
// 提示：
// 1 <= arr.length == arr[i].length <= 200
// -99 <= arr[i][j] <= 99
// 通过次数3,358提交次数5,423

#include<vector>
#include<algorithm>
using namespace std;
int minFallingPathSum(vector<vector<int>>& arr){
    int n=arr.size();
    int NUMMAX=1e9+7;
    vector<vector<int>>dp(n,vector(n,NUMMAX));
    for(int i=0;i<n;i++)
    dp[0][i]=arr[0][i];
    for(int i=1;i<n;i++)
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            if(j!=k)
            dp[i][j]=min(dp[i][j],dp[i-1][k]+arr[i][j]);
        }
    }
    int res=NUMMAX;
    for(int i=0;i<n;i++)
    res=min(res,dp[0][i]);
    return res;
}