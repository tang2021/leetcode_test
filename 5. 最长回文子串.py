# 5. 最长回文子串
# 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
# 示例 1：
# 输入: "babad"
# 输出: "bab"
# 注意: "aba" 也是一个有效答案。
# 示例 2：
# 输入: "cbbd"
# 输出: "bb"
def longestPalindrome(self, s: str) -> str:
    ans=""
    maxlen=0
    n =len(s)
    if n<2:return s
    news='#'+'#'.join(s)+'#'
    newlen=2*n+1
    # dp=[1 for i in range(newlen)]
    for i in range(newlen):
        for j in range(0,i+1):
            if i+j<newlen and news[i-j]==news[i+j]:
                if 2*j>maxlen:
                    ans=news[i-j:i+j+1]
                    maxlen=2*j+1
                continue
            break
    return ''.join(i for i in ans if i!='#')