// 14. 最长公共前缀
// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。
// 示例 1:
// 输入: ["flower","flow","flight"]
// 输出: "fl"
// 示例 2:
// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。
// 说明:
// 所有输入只包含小写字母 a-z 。
#include<string>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())return "";
    int n=strs[0].size();
    string ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<strs.size();j++){
            if(strs[0][i]!=strs[j][i])return ans;
        }
        ans.push_back(strs[0][i]);
    }
    return ans;
}