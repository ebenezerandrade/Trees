class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

class LinkedList:
  def __init__(self):
    self.head = None

  def insertAtBeginning(self, value):
    if(self.head):
      newNode = Node(value)
      newNode.next = self.head
      self.head = newNode
    else:
      self.head = Node(value)

  def length(self):
    pointer = self.head
    count = 0
    while(pointer.next != None):
      count = count + 1
      pointer = pointer.next
    count = count + 1
    return count

  def insertAtEnd(self, value):
    if(self.head):
      pointer = self.head
      while(pointer.next):
        pointer = pointer.next
      pointer.next = Node(value)
    else:
      self.head = Node(value)
   
  def getnode(self, index):
        pointer = self.head
        for i in range(index):
            if pointer:
                pointer = pointer.next
            else:
                raise print("list index out of range") #return None
        return pointer

  def insertAtIndex(self, index, value):
    if(index > self.length() or index < 0):
      print("index incorrect")
      return None
    else: 
      if(index == 0):
        self.insertAtBeginning(value)
      else:
        if(index == self.length()):
          self.insertAtEnd(value)
        else:
          newNode = Node(value)
          pointer = self.getnode(index-1)
          newNode.next = pointer.next
          pointer.next = newNode

  def printValues(self):
    pointer = self.head
    count = 0
    if(pointer.next == None):
      print(f"{pointer.data}")
    while(pointer.next != None):
      print(f"{pointer.data}")
      pointer = pointer.next
      count = count + 1
      if(pointer.next == None):
        print(f"{pointer.data}")
