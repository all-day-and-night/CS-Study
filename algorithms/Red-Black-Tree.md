Red-black Tree
==============

- 균형 이진 트리(balanced binary tree)
- 형태는 이진 탐색 트리와 동일하지만 특정 조건에 위배될 경우 트리의 구조를 변화하여 균형을 맞춘다

### Red-Black tree 특성

1. Root Property : 루트 노드의 색은 검정(Black)이다.
2. External Property : 모든 External node들은 검정(Black)이다.
3. Internal Property : 빨강(Red) 노드의 자식은 검정(Black)이다.
4. Depth Property : External 노드의 경우 루트 부터 외부 노드까지 방문하는 블랙 노드의 수가 같다.



![image](https://user-images.githubusercontent.com/94096054/144630805-14a942f9-042b-41fe-9f1e-e80f08f176e0.png)


> 트리의 높이는 항상 O(log N)이다

> 삽입의 시간 복잡도는 항상 O(log N)이다


+ Red black Tree Structure

```
typedef struct Node {
    int data;
    char color;
    struct Node *right, *left, *parent;
}Node;

typedef struct rbTree {
    Node *root;
    Node *NIL;
}rbTree;
```

+ Constructor
```
Node* new_Node(int data) {
    Node* n = malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    n->data = data;
    n->color = 'R';

    return n;
}

rbTree* new_rbTree() {
    rbTree *t = malloc(sizeof(rbTree));
    Node *nil_node = malloc(sizeof(Node));
    nil_node->left = NULL;
    nil_node->right = NULL;
    nil_node->parent = NULL;
    nil_node->color = 'B';
    nil_node->data = 0;
    t->NIL = nil_node;
    t->root = t->NIL;

    return t;
}
```



### Balance

1. Insertion

```
void insert(rbTree *t, int data) {
    Node *z = new_Node(data);
    Node* y = t->NIL; 
    Node* x = t->root;

    while(x != t->NIL) {
        y = x;
        if(z->data < x->data)
            x = x->left;
        else if(z->data > x->data){
            x = x->right;
        }
        else{
            return ;
        }
            
    }
    z->parent = y;

    if(y == t->NIL) { 
        t->root = z;
    }
    else if(z->data < y->data) 
        y->left = z;
    else
        y->right = z;

    z->right = t->NIL;
    z->left = t->NIL;

    insertion_fixup(t, z);
}
```

> 새로 생성되는 노드의 색은 항상 빨강(Red)이며 예외적으로 루트 노드만 검정(Black)이다.

> 삽입 상태에서 규칙을 위반하는 경우는 신규 노드가 삽입되고 Red 노드가 연속으로 2개 나타날 경우이다.

- 이때 Case는 3가지로 나뉜다

+ case1: 부모 노드가 Red인데, 부모 노드의 형제가 Red 일 때 (Recoloring)
+ case2: 부모 노드가 Red인데, 부모 노드의 형제가 없거나 Black 일 때, 자기 자신은 오른쪽 자식 노드 (Reconstruct)
+ case3: 부모 노드가 Red인데, 부모 노드의 형제가 없거나 Black 일 때, 자기 자신은 왼쪽 자식 노드 (Reconstruct)

> 위 case를 고려하여 트리의 구조를 변경하고 변경 후 위 case에 위반되는 경우가 생기지 않을 때까지 반복한다 

- Recoloring

> case 1일 때 부모 노드와 부모 노드의 형제 노드를 Black으로 Recoloring 후 할아버지 노드를 Red로 Recoloring한다   

![image](https://user-images.githubusercontent.com/94096054/144698276-681781e7-83fa-428b-b2c1-d4c69904653b.png)

- Reconstruct

> case 2일 때 삽입된 노드와 부모노드를 Left-rotate를 하고 부모 노드와 할아버지 노드를 Right-rotate한다 

![image](https://user-images.githubusercontent.com/94096054/144634155-193288b4-b5ff-451a-bb9f-6172697951ab.png)


+ left-rotation
```
void leftRotate(rbTree *t, Node *x) {
  Node *y = x->right;
  x->right = y->left;
  
  if(y->left != t->NIL) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  
  if(x->parent == t->NIL) { //x is root
    t->root = y;
  }
  else if(x == x->parent->left) { //x is left child
    x->parent->left = y;
  }
  
  else { //x is right child
    x->parent->right = y;
  }
  
  y->left = x;
  x->parent = y;
}
```

+ right-rotation

```

void rightRotate(rbTree *t, Node *x) {
  Node *y = x->left;  
  x->left = y->right;
  
  if(y->right != t->NIL) {
    y->right->parent = x;
  }
  
  y->parent = x->parent;
  
  if(x->parent == t->NIL) { //x is root
    t->root = y;
  }
  
  else if(x == x->parent->right) { //x is left child
    x->parent->right = y;
  }
  
  else { //x is right child
    x->parent->left = y;
  }
  
  y->right = x;
  x->parent = y;
}
```

+ Insertion Fix up
> 위 두가지 case에 해당된다면 노드 삽입 이후 fix

```
void insertion_fixup(rbTree *t, Node *z) {
  while(z->parent->color == 'R') {
    if(z->parent == z->parent->parent->left) { //z.parent is the left child

      Node *y = z->parent->parent->right; //uncle of z

      if(y->color == 'R') { //case 1
        z->parent->color = 'B';
        y->color = 'B';
        z->parent->parent->color = 'R';
        z = z->parent->parent;
      }
      else { //case2 or case3
        if(z == z->parent->right) { //case2
          z = z->parent; //marked z.parent as new z
          leftRotate(t, z);
        }
      //case3
        z->parent->color = 'B'; //made parent 'B'
        z->parent->parent->color = 'R'; //made parent 'R'
        rightRotate(t, z->parent->parent);
      }
    }
    else { //z.parent is the right child
      Node *y = z->parent->parent->left; //uncle of z

      if(y->color == 'R') {
        z->parent->color = 'B';
        y->color = 'B';
        z->parent->parent->color = 'R';
        z = z->parent->parent;
      }
      else {
        if(z == z->parent->left) {
          z = z->parent; //marked z.parent as new z
          rightRotate(t, z);
        }
        z->parent->color = 'B'; //made parent 'B'
        z->parent->parent->color = 'R'; //made parent 'R'
        leftRotate(t, z->parent->parent);
      }
    }
  } 
  t->root->color = 'B';
}
```








