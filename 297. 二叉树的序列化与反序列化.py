import collections
class TreeNode(object):
    def __init__(self,x):
        self.val=x
        self.left=None
        self.right=None
class code(object):
    def serialize(root):
        val=[]
        def serhelp(root,v):
            if root==None:return 
            v.append(root.val)
            serhelp(root.left,v)
            serhelp(root.right,v)
        serhelp(root,val)
        return ''.jion(map(str,val))


    def deserialize(s):
        root=None
        def deserhelp(q,nmax,nmin):
            if len(q):return None
            if nmin<q[0]<nmax:
                v=q[0]
                root=TreeNode(q[0])
                nums.popleft()
                root.left=deserhelp(q,v,nmin)
                root.right=deserhelp(q,nmax,v)
                return root
            else : return None
        myque=collections.deuqe([int(x):for x in s.split()] )
        return deserhelp(myque,float('inf'),float('-inf'))