# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p, q):
         """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        #both trees empty
        if(p is None and q is None):
            return True
        elif((p is None and not (q is None)) or (q is None and not (p is None))):
            return False
        same = True
        #values are equal, then go into recursion
        if(p.val == q.val):
            #traverse starting from left
            if(p.left is not None and q.left is not None):
                same = self.isSameTree(p.left, q.left)
            elif((p.left != None and  q.left == None) or (p.left == None and q.left != None)):
                return False
            if(p.right != None and q.right != None and same):
                same = self.isSameTree(p.right, q.right)
            elif((p.right != None and q.right == None) or (p.right == None and q.right != None)):
                return False
            return same
        else:
            return False