# 3. 无重复字符的最长子串
# 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
# 示例 1:
# 输入: "abcabcbb"
# 输出: 3 
# 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
# 示例 2:
# 输入: "bbbbb"
# 输出: 1
# 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
# 示例 3:
# 输入: "pwwkew"
# 输出: 3
# 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
# 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
def lengthOfLongestSubstring(self, s: str) -> int:
    occ=[]
    ans=0
    n = len(s)
    left=-1
    for i in range(n):
        if i!=0:occ.remove(s[i-1])
        while left+1<n and s[left+1] not in occ:
            occ.append(s[left+1])
            left+=1
        ans=max(ans,left -i+1)
    return ans
