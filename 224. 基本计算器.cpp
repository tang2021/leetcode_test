// 224. 基本计算器
// 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
// 示例 1：
// 输入：s = "1 + 1"
// 输出：2
// 示例 2：
// 输入：s = " 2-1 + 2 "
// 输出：3
// 示例 3：
// 输入：s = "(1+(4+5+2)-3)+(6+8)"
// 输出：23
// 提示：
// 1 <= s.length <= 3 * 105
// s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
// s 表示一个有效的表达式
#include<string>
#include<stack>
using namespace std;

int calculate(string s){
    int n=s.size();
    stack<int> opt;
    opt.push(1);
    int flg=1;
    int num=0;
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            long t=0;
            t=10*t-'0'+s[i];
            while(i+1<n&&s[i+1]>='0'&&s[i+1]<='9')
            t=10*t-'0'+s[++i];
            num+=flg*t;
        }
        else if(s[i]=='-') flg=-opt.top();
        else if(s[i]=='+') flg=opt.top();
        else if(s[i]=='(') opt.push(flg);
        else if(s[i]==')')opt.pop();
    }
    return num;
}