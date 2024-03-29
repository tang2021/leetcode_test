// 53. 最大子序和
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 示例 1：
// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
// 示例 2：
// 输入：nums = [1]
// 输出：1
// 示例 3：
// 输入：nums = [0]
// 输出：0
// 示例 4：
// 输入：nums = [-1]
// 输出：-1
// 示例 5：
// 输入：nums = [-100000]
// 输出：-100000
#include<vector>
using namespace std;
int maxSubArray(vector<int>nums){
    int res=nums[0],sum=0;
    for(int i=0;i<nums.size();i++){
        if(sum>0)sum+=nums[i];
        else sum=nums[i];
        res=max(res,sum);
    }
    return res;
}
int maxSubArray(vector<int>nums){
    int n=nums.size();
    int res=nums[0];
    vector<int>dp(n+1,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        dp[i]=max(nums[i],dp[i-1]+nums[i]);
        res=max(dp[i],res);
    }
    return res;
}