// 738. 单调递增的数字
// 给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
// （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
// 示例 1:
// 输入: N = 10
// 输出: 9
// 示例 2:
// 输入: N = 1234
// 输出: 1234
// 示例 3:
// 输入: N = 332
// 输出: 299
#include<string>
using namespace std;
int monotoneIncreasingDigits(int N){
    string ans=to_string(N);
    int i=1;
    int n=ans.size();
    while(i<n&&ans[i-1]<=ans[i])i++;
    if(i==n)return  N;
    ans[i]-=1;
    while(i>0&&s[i-1]<s[i])ans[i--]-=1;
    while((++i)<n)ans[i]='9';
    return atoi(ans.c_str());
}