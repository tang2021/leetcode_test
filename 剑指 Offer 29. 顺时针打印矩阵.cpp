// 剑指 Offer 29. 顺时针打印矩阵
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
// 示例 1：
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
// 示例 2：
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 限制：
// 0 <= matrix.length <= 100
// 0 <= matrix[i].length <= 100
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>&matrix){
    int n=matrix.size();
    if(n==0)return {};
    int m=matrix[0].size();
    int top=0,bott=n-1,left=0,right=m-1;
    int idx=0;
    vector<int>res;
    while(top<=bott||left<=right){
        for(int i=left;i<=right;i++)res.push_back(matrix[top][i]);
        if(++top>bott)break;
        for(int i=top;i<bott;i++)res.push_back(matrix[i][right]);
        if(--right<left)break;
        for(int i=right;i>=left;i--)res.push_back(matrix[bott][i]);
        if(--bott<top)break;
        for(int i=bott;i>=top;i--)res.push_back(matrix[i][left]);
        if(++left>right)break;
    }
    return res;
}
