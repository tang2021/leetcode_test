//面试题 04.12. 求和路径
// 给定一棵二叉树，其中每个节点都含有一个整数数值(该值或正或负)。设计一个算法，打印节点数值总和等于某个给定值的所有路径的数量。注意，路径不一定非得从二叉树的根节点或叶节点开始或结束，但是其方向必须向下(只能从父节点指向子节点方向)。
// 示例:
// 给定如下二叉树，以及目标和 sum = 22，
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// 返回:
// 3
// 解释：和为 22 的路径有：[5,4,11,2], [5,8,4,5], [4,11,7]
#include<unordered_map>
#include<map>
typedef struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

int pathSum(TreeNode* root,int sum){
    if(!root)return 0;
    return path(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
}
int path(TreeNode* root,int sum){
    if(!root)return 0;
    int ans=0;
    if(root->val==sum)ans=1;
    return ans+path(root->left,sum-root->val)+path(root->right,sum-root->val);
}
int pathSum2(TreeNode* root,int sum){
    if(!root)return 0;
    unordered_map<int,int>m;
    m[0]=1;
    return path2(root,m,0,sum);

}
int path2(TreeNode*root, unordered_map<int,int>&m,int currsum,int t){
    if(!root)return 0;
    currsum+=root->val;
    int ans=0;
    if(m.find(currsum-t)!=m.end())ans+=m[currsum-t];
    m[currsum]++;
    ans+=path2(root->left,m,currsum,t);
    ans+=path2(root->right,m,currsum,t);
    if(--m[currsum]<=0)m.erase(currsum);
    return ans;

}