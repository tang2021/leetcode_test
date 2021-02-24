// 16. 最接近的三数之和
// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
// 示例：
// 输入：nums = [-1,2,1,-4], target = 1
// 输出：2
// 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
// 提示：
// 3 <= nums.length <= 10^3
// -10^3 <= nums[i] <= 10^3
// -10^4 <= target <= 10^4
#include<vector>
#include<algorithm>
using namespace std;
int threeSumClosest(vector<int>&nums,int target){
    int n=nums.size();
    if(n<3)return -1;
    int res=nums[0]+nums[1]+nums[2];
    int gap=res;
    sort(nums.end(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0&&nums[i]==nums[i-1])continue;
        for(int j=i+1,k=n-1;j<k;){
            int t=nums[i]+nums[j]+nums[k];
            if(abs(t-target)<gap){
                res=t;
                gap=abs(t-target);
            }
            if(res==target)return res;
            else if(t>target)k--;
            else if(t<target)j++;
        }
    }
    return res;
}