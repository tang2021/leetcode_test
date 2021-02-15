// 485. 最大连续1的个数
// 给定一个二进制数组， 计算其中最大连续1的个数。
// 示例 1:
// 输入: [1,1,0,1,1,1]
// 输出: 3
// 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
// 注意：
// 输入的数组只包含 0 和1。
// 输入数组的长度是正整数，且不超过 10,000。
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>&nums){
    int res=0,t=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i])t++;
        else t=0;
        res=max(res,t);
    }
    return res;
}