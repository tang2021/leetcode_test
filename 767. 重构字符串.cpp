// 767. 重构字符串
// 给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
// 若可行，输出任意可行的结果。若不可行，返回空字符串。
// 示例 1:
// 输入: S = "aab"
// 输出: "aba"
// 示例 2:
// 输入: S = "aaab"
// 输出: ""
// 注意:
// S 只包含小写字母并且长度在[1, 500]区间内。

bool static cmp(const pair<int,int>&a,const pair<int,int>&b){
    return a.second>b.second;
}
string reorganizeString(string S) {
    int n=S.size();
    if(n<2)return S;
    string ans(S);
    unordered_map<char,int>m;

    int maxnum=0;
    for(char c :S){
        m[c]++;
        maxnum=max(m[c],maxnum);
    }
    if(2*maxnum-1 >n)return "";
vector<pair<int,int>>v(m.begin(),m.end());
sort(v.begin(),v.end(),cmp);
int index=0;
for(int i=0;i<v.size();i++){
    while(v[i].second--){
        ans[index]=v[i].first;
        index+=2;
        if(index>=n)index=1;
    }
    
}
return ans;
}