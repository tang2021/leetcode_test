// 面试题 08.09. 括号
// 括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。
// 说明：解集不能包含重复的子集。
// 例如，给出 n = 3，生成结果为：
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
#include<string>
#include<vector>
using namespace std;
vector<string>res;
vector<string>generateParenthesis(int n){
    string track;
    back_track(n,track,0,0);
    return res;
}
void back_track(const int&n,string track,int left,int right){
    if(left>n||right>n||left>right)return ;
    if(left==n&&right==n){
        res.push_back(track);
        return ;
    }
    back_track(n,track+'(',left+1,right);
    back_track(n,track+')',left,right+1);
}