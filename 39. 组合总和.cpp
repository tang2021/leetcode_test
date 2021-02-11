// 39. 组合总和
// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字可以无限制重复被选取。
// 说明：
// 所有数字（包括 target）都是正整数。
// 解集不能包含重复的组合。 
// 示例 1：
// 输入：candidates = [2,3,6,7], target = 7,
// 所求解集为：
// [
//   [7],
//   [2,2,3]
// ]
// 示例 2：
// 输入：candidates = [2,3,5], target = 8,
// 所求解集为：
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
#include<vector>
using namespace std;
vector<vector<int>>res;
vector<vector<int>>combinationSum(vector<int>candidates,int target){
    vector<int>track;
    back_track(candidates,track,target,0);
}
void back_track(vector<int>&nums,vector<int>&track,int target,int start){
    if(start==nums.size())return ;
    if(target==0){
        res.push_back(track);
        return ;
    }
    for(int i=start;i<nums.size();i++){
        if(target<nums[i])continue;
        track.push_back(nums[i]);
        back_track(nums,track,target-nums[i],i);
        track.pop_back();
    }
}