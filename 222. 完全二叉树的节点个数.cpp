// 222. 完全二叉树的节点个数
// 给出一个完全二叉树，求出该树的节点个数。
// 说明：
// 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
// 示例:
// 输入: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6
// 输出: 6
typedef struct TreeNode{
    int val;
    TreeNode* left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
int countNodes(TreeNode* root){
    if(root==nullptr)return 0;
    TreeNode* p=root;
    int lvl=0;
    while(p->left){
        lvl+=;
        p=p->left;
    }
    int maxnum=(1<<(lvl+1))-1,minnum=1<<lvl;
    int mid=0;
    while(minnum<maxnum){
        mid=(maxnum-minnum+1)/2+minnum;
        if(exists(root,lvl,mid))minnum=mid;
        else maxnum=mid-1;
    }
    return minnum;
}
bool exists(TreeNode* root,int level,int t){
    TreeNode* p=root;
    int bit=1<<level;
    while(p&&bit){
        if(t&bit)p=p->right;
        else p=p->left;
        bit>>=1;
    }
    return p==nullptr;
}