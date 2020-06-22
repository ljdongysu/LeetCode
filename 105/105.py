class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class SolutionNew:
    def buildTree(self, preorder: list, inorder: list) -> TreeNode:
        # 实际上inorder 和 postorder一定是同时为空的，因此你无论判断哪个都行
        if not preorder:
            return None
        root = TreeNode(preorder[0])

        i = inorder.index(root.val)
        print("i: ",i)
        root.left = self.buildTree(preorder[1:i + 1], inorder[:i])
        root.right = self.buildTree(preorder[i + 1:], inorder[i+1:])

        return root



class Solution:
    def devTree(self,preorder:list,inorder:list):
        print(preorder)
        print(inorder)
        for i in range(len(inorder)):
            if preorder[0] == inorder[i]:
                return i

    def buildTree(self, preorder: list, inorder:list) -> TreeNode:
        if len(preorder) < 1:
            return None

        middle = self.devTree(preorder,inorder)
        print("middle: ",middle)
        root = TreeNode(preorder[0])
        root.left = self.buildTree(preorder[1:middle+1],inorder[:middle])
        print(len(preorder),"middle + 1====================================: ", middle+1)
        if middle + 1 < len(preorder):
            root.right = self.buildTree(preorder[middle+1:], inorder[middle+1:])
        return root



def main():
    # a = [1]
    preorder = [3,9,20,15,7,6]
    cc = preorder[6:]
    # print(preorder[:10])
    assert 0
    inorder = [9,3,15,20,6,7]
    a = Solution()
    b = a.buildTree(preorder,inorder)
    c = SolutionNew()
    d = c.buildTree(preorder,inorder)

if __name__ == '__main__':
    main()