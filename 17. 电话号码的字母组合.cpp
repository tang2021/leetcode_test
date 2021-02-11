// 17. 电话号码的字母组合
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
// 示例:
// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 说明:
// 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
#include<string>
#include<vector>
using namespace std;
vector<string>mp={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
 vector<string> letterCombinations(string digits){
     int n=digits.size();
     vector<string> res;
     if(n==0)return res;
     string track;
     back_track(digits,res,track,0);
     return res;
 }
 void back_track(string digits,vector<string>&res,string& track,int idx){
     if(idx>digits.size())return ;
     if(idx==digits.size()){
         res.push_back(track);
     }
     string t=mp[digits[idx]-'2'];
     for(int i=0;i<t.size();i++){
         track.push_back(t[i]);
         back_track(digits,res,track,idx+1);
         track.pop_back();
     }
 }