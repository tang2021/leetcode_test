//234. 回文链表
//请判断一个链表是否为回文链表。
//示例 1:
//输入: 1->2
//输出: false
//示例 2:
//输入: 1->2->2->1
//输出: true
bool isPalindrome(ListNode head) {
    if(!head !head-next)return true;
    ListNode newhead = nullptr;
    ListNode fast = head;
    ListNode mid = head;
    while(fast && fast-next){
        ListNode pnext = mid-next;
        fast = fast-next-next;
        mid-next = newhead;
        newhead = mid;
        mid = pnext;
    }
     /* 奇数个链表 */
    if (fast !=  nullptr) {
        mid  =  mid-next;
    }
    while(newhead){
        if(newhead-val!= mid-val)return false;
        newhead = newhead-next;
        mid = mid-next;
    }
    return true;
}
