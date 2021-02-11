// 面试题 04.05. 合法二叉搜索树
// 实现一个函数，检查一棵二叉树是否为二叉搜索树。
// 示例 1:
// 输入:
//     2
//    / \
//   1   3
// 输出: true
// 示例 2:
// 输入:
//     5
//    / \
//   1   4
//      / \
//     3   6
// 输出: false
// 解释: 输入为: [5,1,4,null,null,3,6]。
//      根节点的值为 5 ，但是其右子节点值为 4 。
typedef struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(nullptr),riight(nullptr){}
};
bool isVaildBST(TreeNode *root){
    if(!root)return true;
    return isBST(root,LONG_MAX,LONG_MIN);

}
bool isBST(TreeNode* root,long nummax,long nummin){
    if(!root)return true;
    if(root->val >= nummax ||root->val <= nummin)return false;
    return isBST(root->left,root->val,nummin)&&isBST(root->right,nummax,root->val);
}