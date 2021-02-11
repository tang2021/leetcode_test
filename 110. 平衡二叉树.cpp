// 110. 平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树。
// 本题中，一棵高度平衡二叉树定义为：
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：true
// 示例 2：
// 输入：root = [1,2,2,3,3,null,null,4,4]
// 输出：false
// 示例 3：
// 输入：root = []
// 输出：true
#include<algorithm>
typedef struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

bool isBalanceTree(TreeNode* root){
    return dfs(root)==-1;
}
int dfs(TreeNode* root){
    if(!root)return 0;
    int left=0,right=0;
    if((left=dfs(root->left))!=-1||(right=dfs(root->right))!=-1||abs(left-right)>1)
    return -1;
    return max(right,left)+1;
}
bool isBalanceTree1(TreeNode* root){
    if(!root)return true;
    return (abs(hightTree(root->left)-hightTree(root->right))<2) &&\
            isBalanceTree1(root->left)&&isBalanceTree1(root->right);
}
int hightTree(TreeNode* root){
    if(!root)return 0;
    return max(hightTree(root->left),hightTree(root->right))+1;
}