// 22. 括号生成
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
// 示例
// 输入：n = 3
// 输出：[
//        "((()))",
//        "(()())",
//        "(())()",
//        "()(())",
//        "()()()"
//      ]
#include<vector>
#include<string>
using namespace std;
vector<string> generateParenthesis(int n) {
    vector<string>ans;
    string track="";
    back_track(ans,"",n,n,n);
    return ans;
}
void back_track(vector<string>& res,string track,int left,int right,int n){

    if(left<0||left>right)return ;
    if(left==0&&right==0){
        res.push_back(track);
        return ;
    }
    back_track(res,track+'(',left-1,right,n);
    back_track(res,track+')',left,right-1,n);
}