// 131. 分割回文串
// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
// 回文串 是正着读和反着读都一样的字符串。
// 示例 1：
// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]
// 示例 2：
// 输入：s = "a"
// 输出：[["a"]]
// 提示：
// 1 <= s.length <= 16
// s 仅由小写英文字母组成
#include<string>
#include<vector>
using namespace std;

bool isPatition(string&s){
    int n=s.size();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i+1])return false;
    }
    return true;
}

vector<vector<string>> res;
vector<vector<string>>partition(string s){
    vector<string> track;
    back_track(s,track,0);
    return res;
}
void back_track(string&s,vector<string>& track,int idx){
    int n=s.size();
    if(n==idx){
        res.push_back(track);
        return ;
    }
    for(int i=idx;i<n;i++){
        string t =s.substr(idx,i-idx+1);
        if(isPatition(t));
        track.push_back(t);
        back_track(s,track,i+1);
        track.pop_back();
    }
}