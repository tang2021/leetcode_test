// 438. 找到字符串中所有字母异位词
// 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
// 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
// 说明：
// 字母异位词指字母相同，但排列不同的字符串。
// 不考虑答案输出的顺序。
// 示例 1:
// 输入:
// s: "cbaebabacd" p: "abc"
// 输出:
// [0, 6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
//  示例 2:
// 输入:
// s: "abab" p: "ab"
// 输出:
// [0, 1, 2]
// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
#include<vector>
#include<string>
using namespace std;
vector<int> findAllAnagram(string s,string p){
    if(s.size()<p.size())return {};
    vector<int>ans, freqs(26,0), freqp(26,0);
    int l=0,r=0;
    for(int i=0;i<p.size();i++){
        freqs[s[r++]-'a']++;
        freqp[p[i]-'a']++;
    }
    if(freqs==freqp)ans.push_back(0);
    while(r<s.size()){
        freqs[s[r++]-'a']++;
        freqs[s[l++]-'a']--;
        if(freqs==freqp)ans.push_back(l);
    }
    return ans;
    }


}