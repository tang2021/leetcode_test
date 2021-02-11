// 面试题 04.03. 特定深度节点链表
// 给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。
// 示例：
// 输入：[1,2,3,4,5,null,7,8]
//         1
//        /  \ 
//       2    3
//      / \    \ 
//     4   5    7
//    /
//   8
// 输出：[[1],[2,3],[4,5,7],[8]]
vector<ListNode*> listOfDepth(TreeNode* tree) {
    vector<ListNode*>ans;
    if(!tree)return ans;
    queue<TreeNode*>q;
    q.push(tree);
    while(!q.empty()){
        int n=q.size();
        ListNode* dummy=new ListNode(0);
        ListNode* plist=dummy;
        while(n--){
            TreeNode* p=q.front();q.pop();
            plist->next=new ListNode(p->val);
            plist=plist->next;
            if(p->left)q.push(p->left);
            if(p->right)q.push(p->right);
        }
        ans.push_back(dummy->next);
        delete dummy;
    }
    return ans;
}