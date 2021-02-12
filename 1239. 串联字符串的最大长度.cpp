// 1239. 串联字符串的最大长度
// 给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。
// 请返回所有可行解 s 中最长长度。
// 示例 1：
// 输入：arr = ["un","iq","ue"]
// 输出：4
// 解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
// 示例 2：
// 输入：arr = ["cha","r","act","ers"]
// 输出：6
// 解释：可能的解答有 "chaers" 和 "acters"。
// 示例 3：
// 输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
// 输出：26
// 提示：
// 1 <= arr.length <= 16
// 1 <= arr[i].length <= 26
// arr[i] 中只含有小写英文字母
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int res=0;
bool mp[26]={false};
int maxLength(vector<string>&arr){
    string track;
    back_track(arr,track,0);
    return res;
}
void back_track(vector<string>&arr,string track,int start){
    int n=arr.size();
    res=max(res,track.size());
    if(start==n)return ;
    for(int i=start;i<n;i++){
        if(check(arr[i]))continue;
        back_track(arr,track+arr[i],i+1);
        update(arr[i]);
    }
}
bool check(string&s){
    bool m[26]={false};
    for(char c:s){
    if(mp[c-'a'])return true;//track 字符串不重复
    if(m[c-'a'])return true;//本字符串不重复
    else m[c-'a']=true;
    }
    for(char c:s)
    mp[c-'a']=true;
    return false;
}


void update(string& s){
    for(char c:s)
    mp[c]=false;
}
