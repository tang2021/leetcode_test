// 47. 全排列 II
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
// 示例 1：
// 输入：nums = [1,1,2]
// 输出：
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// 示例 2
// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 提示：
// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10
#include<vector>
using namespace std;
vector<vector<int>>res;
vector<vector<int>> permuteUnique(vector<int>& nums) {
    if(nums.size()<2)return {nums};
    sort(nums.begin(),nums.end());
    vector<bool>visited(nums.size(),false);
    vector<int>track;
    back_track(nums,track,visited);
    return res;
}
void back_track(vector<int>&nums,vector<int>&track,vector<bool>&visited){
    if(track.size()==nums.size()){
        res.push_back(track);
        return ;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i])continue;
        if(i>0&&visited[i-1]&&nums[i-1]==nums[i])continue;
        track.push_back(nums[i]);
        visited[i]=true;
        back_track(nums,track,visited);
        track.pop_back();
        visited[i]=false;
    }
}