//922. 按奇偶排序数组 II
//给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
//对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
//你可以返回任何满足上述条件的数组作为答案。
//示例：
//输入：[4,2,5,7]
//输出：[4,5,2,7]
//解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
vector<int> sortArrayByParityII(vector<int>& A) {
    int n =A.size();
    if(n==0&&((n&1) == 1))return A;
    int odd=1,even=0;
    while(odd<n&&even<n){
        while(odd<n&&((A[odd]&1)==1))odd+=2;
        while(even<n&&((A[even]&1)==0))even+=2;
        if(!(odd<n)||!(even<n))break;
        swap(A[odd],A[even]);
    }
    return A;
}