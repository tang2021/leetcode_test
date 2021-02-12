// 119. 杨辉三角 II
// 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
// 在杨辉三角中，每个数是它左上方和右上方的数的和。
// 示例:
// 输入: 3
// 输出: [1,3,3,1]
// 进阶：
// 你可以优化你的算法到 O(k) 空间复杂度吗？
#include<stdio.h>
#include<malloc.h>

int* getRow(int rowIndex,int* returnSize){
    returnSize=rowIndex+1;
    int* num=(int*)malloc(sizeof(int)*returnSize);
    for(int i=0;i<returnSize;i++)
    for(int j=i;j>=0;j--){
        if(j==0||j==i)num[j]=0;
        else num[j]+=num[j-1];
    }
    return num;
}