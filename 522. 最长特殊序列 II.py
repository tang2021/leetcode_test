# 522. 最长特殊序列 II
# 给定字符串列表，你需要从它们中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。
# 子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。
# 输入将是一个字符串列表，输出是最长特殊序列的长度。如果最长特殊序列不存在，返回 -1 。
# 示例：
# 输入: "aba", "cdc", "eae"
# 输出: 3
# 提示：
# 所有给定的字符串长度不会超过 10 。
# 给定字符串列表的长度将在 [2, 50 ] 之间。
def findLUSlength(self, strs: List[str]) -> int:
    def subseq(w1,w2):
        i,n1=0,len(w1)
        for c in w2:
            if i<n1 and w1[i] ==c:
                i+=1
        return i==n1
    strs.sort(key =len,reverse=True)
    for i,w1 in enumerate(strs):
        if all(not subseq(w1,w2) for j,w2 in enumerate(strs) if i!=j):
            return len(w1)
    return -1