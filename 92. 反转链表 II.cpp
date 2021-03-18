// 92. 反转链表 II
// 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
// 示例 1
// 输入：head = [1,2,3,4,5], left = 2, right = 4
// 输出：[1,4,3,2,5]
// 示例 2：
// 输入：head = [5], left = 1, right = 1
// 输出：[5]
// 提示：
// 链表中节点数目为 n
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n
// 进阶： 你可以使用一趟扫描完成反转吗？
typedef struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* resverse(ListNode* head,int left,int right){
    ListNode* dummy=new TreeNode(-1);
    ListNode* p=dummy;
    dummy->next=head;
    for(int i=0;i<left-1;i++)
    p=p->next;
    ListNode* curr=p->next;
    ListNode* pnext;
    for(int i=0;i<right-left;i++){
        pnext=curr->next;
        curr->next=pnext->next->next;
        pnext->next=p->next;
        p->next=pnext;
    }
    return dummy->next;
}