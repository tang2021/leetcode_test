// 15. 三数之和
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。
// 示例 1：
// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 示例 2：
// 输入：nums = []
// 输出：[]
// 示例 3：
// 输入：nums = [0]
// 输出：[]
// 提示：
// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105
#include<vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>&nums){
    int n=nums.size();
    vector<vector<int>> res;
    if(n<3)return res;
    for(int i=0;i<n;i++){
        if(i>0&&nums[i]==nums[i-1])continue;
        for(int j=i+1,k=n-1;j<k;j++){
            if(j>i+1&&nums[j]==nums[j-1])continue;
            while(k-1>j&&nums[i]+nums[j]+nums[k]>0)k--;
            if(nums[i]+nums[j]+nums[k]==0){
                res.push_back({nums[i],nums[j],nums[k]});
            }
        }
        return res;
    }
} 