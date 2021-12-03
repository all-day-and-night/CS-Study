Binary Search Tree
==================

- Concepts

- 이진 탐색 트리는 이진 탐색(binary search)과 연결리스트(linked list)를 결합한 자료구조의 일종
- 이진 탐색의 효율적인 탐색 능력을 유지하면서 빠른 자료 insert와 delete가 가능하게끔 설계
- 탐색에 소요되는 시간 : O(log N)
- 입력, 삭제에 소요되는 시간: O(1)
- 하지만 입력과 삭제할 위치를 탐색하는데 O(N)의 시간이 필요
- BST는 같은 값이어도 들어오는 순서에 따라 트리의 모양이 변할 수 있다.
- 불균형한 트리 구조를 가질 수 있음 


![image](https://user-images.githubusercontent.com/94096054/144619884-99ef4887-4589-4b5e-ac7c-3dbf3742f06c.png)

+ 각 노드의 왼쪽 서브트리에는 해당 노드의 값보다 작은 값을 지닌 노드로 구성
+ 각 노드의 오른쪽 서브트리에는 해당 노드의 값보다 큰 값을 지닌 노드로 구성
+ 중복 노드 x
+ 왼쪽 서브트리, 오른쪽 서브트리 모두 이진 탐색 트리구조를 유지
+ 순회의 경우 중위순회를 사용하여 오름차순의 형태로 노드를 방문

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
            #case 1 자식 노드가 없을 경우
            if self.curNode.left == None and self.curNode.right==None:
                if value < self.parent.value:
                    self.parent.left = None
                else:
                    self.parent.right = None
                del self.curNode
                return True
            #case 2 자식 노드가 하나만 존재할 경우
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
            
            #case 3 2개의 leaf node 가지고 있을 때
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

+ Successor vs Predecessor

1. Successor

- 노드 x 의 Successor는 key[x]보다 크면서 가장 작은 키를 가진 노드
- 모든 키들이 서로 다르다고 가장
- 3가지 경우
> 노드 X의 오른쪽 트리가 존재할 경우 오른쪽 트리의 최소값

> 오른쪽 부트리가 없는 경우 어떤 노드 y의 왼쪽 트리의 최대값이 x가 되는 경우 y의 값

> 그런 노드가 모두 존재하지 않을 경우 Successor도 존재하지 않음


2. Predecessor

- Successor의 반대의 경우
- key[x] 보다 작으면서 가장 큰 노드


+ find minimun

- 최소값은 항상 가장 왼쪽 노드에 존재
```
def tree_minimum(x):
    while x->left != NIL:
        x = x->left
    return x
```

+ find maximum

- 최대값은 항상 가장 오른쪽 노드에 존재
```
def tree_maximum(x):
    while x->right != NIL
        x = x->right
    return x
    
```

+ Successor
```
def tree_Successor(x):
    if x->right != NIL:
        return tree_minimun(x->right)
    y = x->parent
    while y != NIL and x == y->right:
        x = y
        y = y->parent
    return y
```
+ Predecessor
```
def tree_Predecessor(x):
    if x->left != NIL:
        return tree_maximum(x->left)
    y = x->parent
    while y != NIL and x == y->left:
        x = y
        y = y->parent
    return y
```
#### Functions
          
1. Search

![image](https://user-images.githubusercontent.com/94096054/144621577-2cc301fb-a339-4c06-859c-4d4d06ab64f6.png)

> 왼쪽 자식 노드는 부모 노드보다 작고 오른쪽 자식 노드는 부모 노드보다 큰 점을 활용하여 탐색을 한다

![image](https://user-images.githubusercontent.com/94096054/144626363-5f346823-ad40-4490-83b8-0f227160b0e5.png)


2. Insert

> 노드를 삽입할 위치를 찾고 노드를 생성 후 추가한다

> leaf node에 추가하기 때문에 노드의 값을 비교 후 leaf 노드를 찾고 추가한다

3. Delete

> BST 구현중 가장 까다롭다

> 3가지 case로 나뉜다

- case1:

> 지울려는 노드의 자식이 없는 경우 그대로 삭제

- case2:

> 지울려는 노드의 자식이 1명 있는 경우(left or right)

> 왼쪽일 경우 자식의 부모와 왼쪽 자식을 이어주고 오른쪽일 경우 자식의 부모와 오른쪽 자식을 이어주면 된다

- case3:

> 자신의 왼쪽 자식 트리에서 가장 큰 노드(Predecessor) or 자신의 오른쪽 노드에서 가장 작은 노드(Successor)를 선택하여 지우고 그 값을 삭제할 노드에 할당


