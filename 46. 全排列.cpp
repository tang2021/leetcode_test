// 46. 全排列
// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

// 示例:

// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,bool>m;
vector<vector<int>>ans;
vector<vector<int>> permute(vector<int>& nums) {
    if(nums.size()<2)return {nums};
    vector<int>track;
    back_track(nums,track);
    return ans;
}
void back_track(vector<int>& nums,vector<int>& track){
    if(track.size()==nums.size()){
        ans.push_back(track);
        return ;
    }
    for(int i=0;i<nums.size();i++){
        if(m.count(nums[i]))continue;
        m[nums[i]]=true;
        track.push_back(nums[i]);
        back_track(nums,track);
        track.pop_back();
        m.erase(nums[i]);
    }
}