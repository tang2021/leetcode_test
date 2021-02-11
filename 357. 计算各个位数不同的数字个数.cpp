// 357. 计算各个位数不同的数字个数
// 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n 。
// 示例:
// 输入: 2
// 输出: 91 
// 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。

int countNumbersWithUniqueDigits(int n){
    if(n<1)return 1;
    int res=10;
    int num=9,base=9;
    n=n>10?10:n;
    for(int i=1;i<n;i++){
        num=num*base--;
        res+=num;
    }
    return res;
}