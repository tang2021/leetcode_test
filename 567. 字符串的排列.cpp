// 567. 字符串的排列
// 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
// 换句话说，第一个字符串的排列之一是第二个字符串的子串。
// 示例1:
// 输入: s1 = "ab" s2 = "eidbaooo"
// 输出: True
// 解释: s2 包含 s1 的排列之一 ("ba").
// 示例2
// 输入: s1= "ab" s2 = "eidboaoo"
// 输出: False
// 注意：
// 输入的字符串只包含小写字母
// 两个字符串的长度都在 [1, 10,000] 之间
#include<vector>
#include<string>
using namespace std;
bool  checkInclusion(string s1,string s2)
{
    int n1=s1.size(),n2=s2.size();
    vector<int>m1(26,0),m2(26,0);
    for(int i=0;i<n1;i++){
        m1[s1[i]-'a']++;
        m2[s2[i]-'a']++;
    }
    for(int i=n1;i<n2;i++){
        if(m1==m2)return true;
        m2[s2[i]-'a']++;
        m2[s2[i-n1]-'a']--;
    }
    return m1==m2;
}