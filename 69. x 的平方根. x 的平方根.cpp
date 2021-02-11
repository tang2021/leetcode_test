// 69. x 的平方根
// 实现 int sqrt(int x) 函数。
// 计算并返回 x 的平方根，其中 x 是非负整数。
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
// 示例 1:
// 输入: 4
// 输出: 2
// 示例 2:
// 输入: 8
// 输出: 2
// 说明: 8 的平方根是 2.82842..., 
// 由于返回类型是整数，小数部分将被舍去。
int mySqrt(int x){
    if(x==1)return 1;
    int lo=0,hi=x;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(x/mid<mid)hi=mid;
        else lo=mid;
    }
    return lo;
}
int mySqrt1(int x) {
    if(x<=1)return x;
    double i=x;
    for(;i-x/i>1e-9;i=(i/2+x/i/2));
    return int(i);
}