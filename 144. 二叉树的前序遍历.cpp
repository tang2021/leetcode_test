// 144. 二叉树的前序遍历
// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
// 示例 1：
// 输入：root = [1,null,2,3]
// 输出：[1,2,3]
// 示例 2：
// 输入：root = []
// 输出：[]
// 示例 3：
// 输入：root = [1]
// 输出：[1]
// 示例 4：
// 输入：root = [1,2]
// 输出：[1,2]
// 示例 5：
// 输入：root = [1,null,2]
// 输出：[1,2]
// 提示：
// 树中节点数目在范围 [0, 100] 内
// -100 <= Node.val <= 100
#include<vector>
#include<stack>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
vector<int> preordertranserve(TreeNode* root){
    vector<int>ans;
    if(!root)return ans;
    stack<TreeNode*>stk;
    TreeNode* p=root;
    while(!stk.empty()||p){
        while(p){
            ans.push_back(p->val);
            stk.push(p);
            p=p->left;
        }
        p=stk.top();stk.pop();
        p=p->right;
    }
    return ans;
}

void preorder(TreeNode* root,vector<int> &res){
    if(!root)return ;
    res.push_back(root->val);
    preorder(root->left,res);
    preorder(root->right,res);
}
vector<int> preordertanserver1(TreeNode* root){
    vector<int>ans;
    preorder(root,ans);
    return ans;
}