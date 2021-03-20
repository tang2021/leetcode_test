// 437. 路径总和 III
// 给定一个二叉树，它的每个结点都存放着一个整数值。
// 找出路径和等于给定数值的路径总数。
// 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
// 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
// 示例：
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1
// 返回 3。和等于 8 的路径有:
// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3.  -3 -> 11
#include<unordered_map>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
};
int pathSum(TreeNode* root,sum){
    if(root==NULL)return 0;
    return path(root,sum)+pahtSum(root->left,sum)+pathSum(root->right,sum);
}
int path(TreeNode* root,int sum){
    if(root==NULL)return 0;
    sum-=root->val;
    
    return ((sum==0)?1:0)+path(root->left,sum)+path(root->right,sum);
}

unordered_map<int,int>m;
int pathSum(TreeNode* root,int sum){
    m[0]=1;
    return path(root,sum,0);
    //return res;
}
int path(TreeNode* root,int sum, int prefix_sum){
    if(root==NULL)return 0;
    prefix_sum+=root->val;
    int res=0;
    res+=m[prefix_sum-sum];
    m[prefix_sum]++;
    res+=path(root->left,sum,prefix_sum)+path(root->right,sum,prefix_sum);
    m[prefix_sum]--;
    return res;
}