//238. 除自身以外数组的乘积
//给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//示例:
//输入: [1,2,3,4]
//输出: [24,12,8,6]
vector<int> productExceptSelf(vector<int>& nums) {
    int n =nums.size();
    if(n<1) return nums;
    vector<int>pre(n,1);
    for(int i=1;i<n;i++)
    pre[i]=pre[i-1]*nums[i-1];
    int next = 1;
    for(int i=n-2;i>=0;i--){
        next*=nums[i+1];
        pre[i]*=next;
    }
    return pre;
}