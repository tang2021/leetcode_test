class ListNode:
    def __init__(self,x):
        self.val=x
        self.next=None
class solution:
    def __init__(self,h):
        self.head=h
    
    def getRandom(self):
        ans=-1
        curr,n=self.head,0
        while curr:
            ans=curr.val if randint(0,n+1)==1 else ans
            curr,n=curr.next,n+1
        return ans