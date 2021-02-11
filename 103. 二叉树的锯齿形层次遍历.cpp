// 103. 二叉树的锯齿形层次遍历
// 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回锯齿形层次遍历如下：
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
#include<queue>
#include<vector>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode* left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root)return ans;
    queue<TreeNode*>q;
    int level=0;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int>lvl;
        while(n--){
            TreeNode* t=q.front();q.pop();
            lvl.push_back(t->val);
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
        if(level&1)reverse(lvl.begin(),lvl.end());
        ans.push_back(lvl);
        lvl.clear();
        level++;
    }
    return ans;
}

