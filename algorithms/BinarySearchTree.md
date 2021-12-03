Binary Search Tree
==================

- Concepts

> 이진 탐색 트리는 이진 탐색(binary search)과 연결리스트(linked list)를 결합한 자료구조의 일종
> 이진 탐색의 효율적인 탐색 능력을 유지하면서 빠른 자료 insert와 delete가 가능하게끔 설계
> 탐색에 소요되는 시간 : O(log N)
> 입력, 삭제에 소요되는 시간: O(1)
> 하지만 입력과 삭제할 위치를 탐색하는데 O(N)의 시간이 필요


![image](https://user-images.githubusercontent.com/94096054/144619884-99ef4887-4589-4b5e-ac7c-3dbf3742f06c.png)

+ 각 노드의 왼쪽 서브트리에는 해당 노드의 값보다 작은 값을 지닌 노드로 구성
+ 각 노드의 오른쪽 서브트리에는 해당 노드의 값보다 큰 값을 지닌 노드로 구성
+ 중복 노드 x
+ 왼쪽 서브트리, 오른쪽 서브트리 모두 이진 탐색 트리구조를 유지
+ 

+ code
```
class Node:
    def __init__(self, value):
        self.value = value
        self.right=None
        self.left=None

class Tree:
    def __init__(self, head):
        self.head = head
        self.parent = None
        self.curNode = None
        self.changeNode = None
        self.changeParentNode = None
    
    def insert(self, value):
        self.curNode = self.head
        
        while True:
            if value < self.curNode.value:
                if self.curNode.left != None:
                    self.curNode = self.curNode.left
                else:
                    self.curNode.left = Node(value)
                    break
                
            else:
                if self.curNode.right != None:
                    self.curNode = self.curNode.right
                else:
                    self.curNode.right = Node(value)
                    break
    
    def search(self, value):
        self.curNode = self.head
        
        while self.curNode:
            if self.curNode.value == value:
                print(self.curNode.value)
                return True
            elif value < self.curNode.value:
                self.curNode = self.curNode.left
            elif value > self.curNode.value:
                self.curNode = self.curNode.right
        return False
    
    def delete(self, value):
        searched = False
        self.curNode = self.head
        self.parent == self.head
        
        while self.curNode:
            if self.curNode.value == value:
                searched = True
                break
            elif value < self.curNode.value:
                self.parent = self.curNode
                self.curNode = self.curNode.left
            elif value > self.curNode.value:
                self.parent = self.curNode
                self.curNode = self.curNode.right
        
        if not searched:
            return False
            
        else:
            if self.curNode.left == None and self.curNode.right==None:
                if value < self.parent.value:
                    self.parent.left = None
                else:
                    self.parent.right = None
                del self.curNode
                return True
                
            elif self.curNode.left == None and self.curNode.right != None:
                #왼쪽
                if value < self.parent.value:
                    self.parent.left = self.curNode.right
                elif value > self.parent.value:
                    self.parent.right = self.curNode.right
                del self.curNode
                return True
                
            elif self.curNode.left != None and self.curNode.right == None:
                #parent의 어느 노드에 cur node가 있는지
                if value < self.parent.value:
                    self.parent.left = self.curNode.left
                elif value > self.parent.value:
                    self.parent.right = self.curNode.left
                del self.curNode
                return True
            
            #2개의 leaf node 가지고 있을 때
            elif self.curNode.right != None and self.curNode.left != None: # case3
                if value < self.parent.value:  # case 3-1 left node
                    self.changeNode = self.curNode.right
                    self.changeParentNode = self.curNode.right
                    
                    while self.changeNode:
                        self.changeParentNode = self.changeNode
                        self.changeNode = self.changeNode.left
                    
                    
                    self.changeParentNode.left = None
                    
                    if self.changeNode.right == None:
                        self.changeParentNode.left = None
                        
                    elif self.changeNode.right != None:
                        self.changeParentNode.left = self.changeNode.right
                    
                    self.parent.left = self.changeNode
                    self.changeNode.left = self.curNode.left
                    self.changeNode.right = self.curNode.right
                    return True
                
                else:
                    self.changeNode = self.curNode
                    self.changeParentNode = self.curNode
                    
                    while self.changeNode.left:
                        self.changeParentNode = self.changeNode
                        self.changeNode = self.changeNode.left
                        
                    if self.changeNode.right != None:
                        self.changeParentNode.left = self.changeNode.right
                    else:
                        self.changeParentNode.left = None
                    
                    self.parent.right = self.changeNode
                    self.changeNode.left = self.curNode.left
                    self.chagneNode.right = self.curNode.right
                    return True
            
    def output(self, node):
        if node == None:
            return
        self.output(node.left)
        print(node.value)
        self.output(node.right)
```
                
                
1. Search

- 
                
    
