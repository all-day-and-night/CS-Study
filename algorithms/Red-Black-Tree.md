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

> 만약 할아버지 노드가 루트노드라면 Black으로 바꾼다

![image](https://user-images.githubusercontent.com/94096054/144698276-681781e7-83fa-428b-b2c1-d4c69904653b.png)

- Reconstruct

> case 2일 때 부모노드를 Black으로 할아버지 노드를 Red로 Recoloring 한다. 삽입된 노드와 부모노드를 Left-rotate를 하고 부모 노드와 할아버지 노드를 Right-rotate한다. 

> case 3일 때 부모노드를 Black으로 할아버지 노드를 Red로 Recoloring한다. 삽입된 노드의 부모노드와 할아버지 노드를 Right-rotate한다. 

> 이 때의 조건은 부모 노드가 할아버지 노드의 왼쪽 자식 노드일 경우이다. 반대로 부모 노드가 할아버지 노드의 오른쪽 자식일 경우 오른쪽, 왼쪽을 반대로 수행하면 된다.

![image](https://user-images.githubusercontent.com/94096054/144698448-58bf335f-bee8-433d-a775-ff3c2f3d4f22.png)


+ Rotate

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

- 시간 복잡도

> 각 시행은 모두 O(1)의 시간이 소요되지만 노드가 삽입될 위치를 찾는데 O(log N)의 시간이 소요되므로 insert의 시간 복잡도는 O(log N)이다.




2. Deletion

> 이진 탐색 트리의 삭제와 동일하지만 삭제할 노드의 색깔에 따라 트리의 구조를 바꾼다.

> 삭제할 노드의 색이 Red일 경우 Red-Black tree의 특성을 위반하지 않기 때문에 Fix up 하지 않아도 된다

> 삭제할 노드의 색이 Black일 경우 Red-Black tree의 다음 특성을 위반할 가능성이 있다.
 
- Root Property : 루트 노드의 색은 검정(Black)이다.
- Internal Property : 빨강(Red) 노드의 자식은 검정(Black)이다.
- Depth Property : External 노드의 경우 루트 부터 외부 노드까지 방문하는 블랙 노드의 수가 같다.

> 위 특성을 위반할 경우는 총 4가지로 나뉘며 수정하는 노드가 루트가 아니고 색이 검정이 아닐 때까지 계속 반복한다.

+ pseudocode

![image](https://user-images.githubusercontent.com/94096054/144704462-79c8e120-38fd-4160-b783-e9a8e71224e8.png)


![image](https://user-images.githubusercontent.com/94096054/144704441-9df070ee-5d23-4bd0-b103-693a195301c6.png)


+ code

```
void transplant(rbTree *t, Node *u, Node *v) {
    if(u->parent == t->NIL)
        t->root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

Node* minimum(rbTree *t, Node *x) {
    while(x->left != t->NIL)
        x = x->left;
    return x;
}

void deleteFixup(rbTree *t, Node *x) {
while(x != t->root && x->color == 'B') {
  if(x == x->parent->left) {
    Node *w = x->parent->right;
    if(w->color == 'R') {
      w->color = 'B';
      x->parent->color = 'R';
      leftRotate(t, x->parent);
      w = x->parent->right;
    }
    if(w->left->color == 'B' && w->right->color == 'B') {
      w->color = 'R';
      x = x->parent;
    }
    else {
      if(w->right->color == 'B') {
        w->left->color = 'B';
        w->color = 'R';
        rightRotate(t, w);
        w = x->parent->right;
      }
      w->color = x->parent->color;
      x->parent->color = 'B';
      w->right->color = 'B';
      leftRotate(t, x->parent);
      x = t->root;
    }
  }
  else {
    Node *w = x->parent->left;
    if(w->color == 'R') {
      w->color = 'B';
      x->parent->color = 'R';
      rightRotate(t, x->parent);
      w = x->parent->left;
    }
    if(w->right->color == 'B' && w->left->color == 'B') {
      w->color = 'R';
      x = x->parent;
    }
    else {
      if(w->left->color == 'B') {
        w->right->color = 'B';
        w->color = 'R';
        leftRotate(t, w);
        w = x->parent->left;
      }
      w->color = x->parent->color;
      x->parent->color = 'B';
      w->left->color = 'B';
      rightRotate(t, x->parent);
      x = t->root;
    }
  }
}
x->color = 'B';
}

void delete(rbTree *t, int data) {
    
    // if root is null -> z is root
    Node *z;
    Node *ty = t->NIL;
    Node *tx = t->root;

        //ordering
    int check = 0;
    while(tx != t->NIL){
        if(data == tx->data){
            z = tx;
            break;
        }
        ty = tx;
        if(data < tx->data){
            tx = tx->left;
        }
        else if(data > tx->data){
            tx = tx->right;
        }
        else{
          return;
        }
    }
    
    
    Node *y = z;
    Node *x;
    char origin_color = y->color;
    if(z->left == t->NIL) {
        x = z->right;
        transplant(t, z, z->right);
    }
    else if(z->right == t->NIL) {
      x = z->left;
      transplant(t, z, z->left);
    }
    else {
        y = minimum(t, z->right);
        origin_color = y->color;
        x = y->right;
    if(y->parent == z) {
        x->parent = z;
    }
    else {
        transplant(t, y, y->right);
        y->right = z->right;
        y->right->parent = y;
    }
    transplant(t, z, y);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
    }
    if(origin_color == 'B')
        deleteFixup(t, x);
}
```


+ Case1 : 형제 노드(w)가 Red일 경우
![image](https://user-images.githubusercontent.com/94096054/144704641-d9fbe82a-9ce2-4775-9df4-7d694acadfdf.png)

> 지워야할 노드가 x라면 Depth Property를 위반하기 때문에 구조를 바꿔야 한다.

> x의 부모노드와 형제 노드를 Recoloring하고, x의 부모 노드에서 left Rotate를 실행하여 구조를 변경한다.

> 이후 나머지 case 2 ~ 4를 확인한다

+ Case2 : 형제 노드(w)가 Black이고 w의 자식들이 모두 Black일 경우
![image](https://user-images.githubusercontent.com/94096054/144704969-370cda11-659b-4a8f-9572-acd806042105.png)

> 마찬가지로 depth property를 위반하기 때문에 구조를 바꿔야 한다.

> 단순하게 w의 색을 Red로 Recoloring하면 된다. 

> 하지만 부모 노드의 색이 Red일 경우 문제가 생기기 때문에 Recoloring 하여 부모의 노드를 Black으로 바꾼다.


+ Case3 : 형제 노드(w)가 Black이고 w의 왼쪽 자식 노드만 Red일 경우 (삭제 노드가 부모 노드의 왼쪽 자식일 경우) 
+ 
![image](https://user-images.githubusercontent.com/94096054/144704980-e29bc85c-082a-4b73-ba24-716e2d6d3781.png)

> w를 right rotate를 하고 case 4로 넘어간다

+ Case4 : 형제 노드(w)가 Black이고 w의 오른쪽 자식 노드만 Red일 경우(삭제 노드가 부모 노드의 왼쪽 자식일 경우)
+ 
![image](https://user-images.githubusercontent.com/94096054/144705434-401cec4c-5fd2-475a-9ad9-0b8b550ddce3.png)

> 부모 노드와 형제 노드의 색을 바꾸고 left-Rotate를 시행한다. 이 때 노드를 삭제하고 트리의 특성에 맞다면 종료, 아니면 다시 시행한다.


+ 중간 노드 삭제 : 

> 중간에 존재하는 노드를 삭제할 경우 그 노드의 Successor를 찾아 그 값을 그대로 삭제할 노드에 저장하고 Successor 노드를 위의 4개의 Case에 따라 삭제한다

참고 사이트 : http://shumin.co.kr/red-black-tree-%EC%82%AD%EC%A0%9C/










