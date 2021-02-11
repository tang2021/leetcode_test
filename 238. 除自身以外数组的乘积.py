#238. 除自身以外数组的乘积
#给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
#示例:
#输入: [1,2,3,4]
#输出: [24,12,8,6]
#提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
#说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
def productExceptSelf(nums)：
    n = len(nums)
    left = [1 for _ in range(n)]
    for i in range(1,n):
        left[i] = left[i-1]*nums[i-1]
    right=1
    for i in range (n-2,-1,-1):
        right*=nums[i+1];
        left[i]*=right
    return left