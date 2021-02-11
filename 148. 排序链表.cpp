// 148. 排序链表
// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
// 进阶：
// 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
// 示例 1：
// 输入：head = [4,2,1,3]
// 输出：[1,2,3,4]
// 示例 2：
// 输入：head = [-1,5,3,4,0]
// 输出：[-1,0,3,4,5]
// 示例 3：
// 输入：head = []
// 输出：[]

typedef struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}

};

ListNode* sortList(ListNode* head) {
    return sortlist(head,nullptr);
}
ListNode* sortlist(ListNode* head,ListNode* tail){
    if(head==nullptr)return head;
    if(head->next==tail){
        head->next=nullptr;
        return head;
    }
    ListNode *fast=head,*slow=head;
    while(fast!=tail){
        fast=fast->next;
        slow=slow->next;
        if(fast!=tail)fast=fast->next;
    }
    return merge(sortlist(head,slow),sortlist(slow,tail));
}
ListNode* merge(ListNode*l1,ListNode*l2){
    ListNode* dummyhead=new ListNode(-1);
    ListNode* p=dummyhead;
    while(l1!=nullptr && l2!=nullptr){
        if(l1->val>l2->val){
            p->next=l2;
            l2=l2->next;
        }else{
            p->next=l1;
            l1=l1->next;
        }
        p=p->next;
    }
    if(l1!=nullptr)p->next=l1;
    if(l2!=nullptr)p->next=l2;
    return dummyhead->next;       
}