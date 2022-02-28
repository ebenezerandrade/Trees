class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None

  def insert(self, data):
    if(self.data):
      if(data < self.data):
        if(self.left is None):
          self.left = Node(data)
        else:
          self.left.insert(data)
      if(data > self.data):
        if(self.right is None):
          self.right = Node(data)
        else:
          self.right.insert(data)
    else:
      self.data = data
  
  def printBinaryTree(self):
    if(self.left):
      self.left.printBinaryTree()
    print(self.data)
    if(self.right):
      self.right.printBinaryTree()

tree = Node(10)
tree.insert(40)
tree.insert(55)
tree.insert(20)

tree.printBinaryTree()
