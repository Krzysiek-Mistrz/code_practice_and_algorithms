class TreeNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return f'TreeNode(data={self.data}, left={self.left}, right={self.right})'


class BinarySearchTree:
    def __init__(self, tree_data):
        self.root = None
        
        for value in tree_data:
            self._insert(value)

    def data(self):
        return self.root

    def _insert(self, value):
        new_node = TreeNode(value)
        
        if self.root is None:
            self.root = new_node
            return

        current = self.root
        
        while True:
            if value <= current.data:
                if current.left is None:
                    current.left = new_node
                    break
                current = current.left
            else:
                if current.right is None:
                    current.right = new_node
                    break
                current = current.right

    def sorted_data(self):
        result = []
        self._in_order(self.root, result)
        return result

    def _in_order(self, node, result):
        if node is not None:
            self._in_order(node.left, result)
            result.append(node.data)
            self._in_order(node.right, result)