// 34. 在排序数组中查找元素的第一个和最后一个位置
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// 进阶：
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
// 示例 1：
// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]
// 示例 2：
// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]
// 示例 3：
// 输入：nums = [], target = 0
// 输出：[-1,-1]
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>ans(2,-1);
    int n=nums.size();
    int l=0,r=n-1;
    while(l<r){
        int mid=(r-l+1)/2+l;
        if(nums[mid]>=target)r=mid;
        else l=mid+1;
    }
    if(nums[l]!=target)return ans;
    ans[0]=l;
    r=n;
    while(l<r){
        int mid=(r-l+1)/2+l;
        if(nums[mid]>=target)r=mid;
        else l=mid+1;
    }
    if(nums[r]!=target)return {-1,-1};
    ans[1]=r;
    return ans;
}