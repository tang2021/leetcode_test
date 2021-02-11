// 306. 累加数
// 累加数是一个字符串，组成它的数字可以形成累加序列。
// 一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
// 给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。
// 说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
// 示例 1:
// 输入: "112358"
// 输出: true 
// 解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
// 示例 2:
// 输入: "199100199"
// 输出: true 
// 解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
// 进阶:
// 你如何处理一个溢出的过大的整数输入?
#include<string>
#include<vector>
using namespace std;

bool isAdditiveNumber(string num){
    vector<string>track;
    return back_track(num,track,0);
}
bool back_track(string& num,vector<string>&track,int start){
    int n=num.size();
    int ntrack=track.size();
    if(start==n&&ntrack>2)return true;
    for(int i=start;i<n;i++){
        ntrack=track.size();
        if(num[start]=='0'&&i>start)break;
        string t=num.substr(start,i+1);
        if(ntrack>1){
            string st=strAdd(track[ntrack-1],track[ntrack-2]);
            if(t<st)continue;
            else if (t>st)break;
        }
        track.push_back(t);
        if(back_track(num,track,i+1))return true;
        track.pop_back();
    }
    return false;
}
string strAdd(string&s1,string&s2){
    int n1=s1.size()-1,n2=s2.size()-1;
    int c1=0,c2=0;
    int curr=0,carry=0;
    string res;
    while(n1>=0||n2>=0||carry>0){
        c1=n1<0?0:s1[n1]-'0';
        c2=n2<0?0:s2[n2]-'0';
        curr=c1+c2+carry;
        carry=curr/10;
        curr=curr%10;
        res=to_string(curr)+res;
    }
    return res;
}