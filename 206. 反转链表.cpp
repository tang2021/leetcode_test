// 206. 反转链表
// 反转一个单链表。
// 示例:
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
// 进阶:
// 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
typedef struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
}ListNode;

ListNode* reverse(ListNode* head){
    ListNode *newhead=nullptr,*h=head;
    while(h!=nullptr){
        ListNode* n=h->next;
        h->next=newhead;
        newhead=h;
        h=n;
    }
    return newhead;
}

ListNode* reverse(ListNode* head){
    if(head==nullptr)return head;
    ListNode* p=reverse(head->next);
    head->next->next=head;
    head->next=nullptr;
    return p;
}