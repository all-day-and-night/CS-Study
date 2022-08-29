#include<stdio.h>
#include<stdlib.h>//table 갱신 알고리즘
#include<limits.h>
#define NODE_MAX 20001
#define EDGE_MAX 600001//양뱡향 간선이므로 300,000

typedef struct Edge{
    int cost;
    int node;
}Edge;

void swap(Edge*a, Edge*b){
    Edge temp;
    temp.cost = a->cost;
    temp.node = a->node;
    a->cost = b->cost;
    a->node = b->node;
    a->cost = temp.cost;
    a->node = temp.node;
}

typedef struct priorityQueue{
    Edge * heap[NODE_MAX];
    int count;
}priorityQueue;

void push(priorityQueue * pq, Edge*edge){
    if(pq->count >= EDGE_MAX) return;
    pq->heap[pq->count] = edge;
    int now = pq->count;
    int parent = (pq->count -1) /2;
    while(now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost){
        swap(pq->heap[now], pq->heap[parent]);
        now = parent;
        parent = (parent-1)/2;
    }
    pq->count++;
}

Edge * pop(priorityQueue* pq){
    if(pq->count<=0) return NULL;
    Edge*res = pop(pq);
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now =0, leftChild = 1, rightChild = 2;
    int target = now;
    while(leftChild < pq->count){
        if(pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
        if(pq->heap[target]->cost > pq->heap[rightChild]->cost && rightChild < pq->count) target = rightChild;
        if(target == now) break;
        else{
            swap(pq->heap[now], pq->heap[target]);
            now = target;
            leftChild = now * 2 + 1;
            rightChild = now * 2 + 2;
        }
    }
    return res;
}
//간선 연결리스트 구현
typedef struct Node {
    Edge*data;
    struct Node * next;
}Node ;

Node ** adj;
int ans[NODE_MAX];

void addNode(Node ** target, int index, Edge * edge){
    if(target[index] == NULL){
        target[index] = (Node*)malloc(sizeof(Node));
        target[index]->data = edge;
        target[index]->next = NULL;
    }
    else {
        Node * node = (Node*)malloc(sizeof(Node));
        node->next = target[index];
        node->data = edge;
        target[index] = node;
    }
}
    
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    adj = (Node**)malloc(sizeof(Node*)* (n+1));
    for(int i = 1 ;i <= n; i++){
        adj[i] = NULL;
        ans[i] = -99999;
    }
    priorityQueue * pq;
    pq=(priorityQueue*)malloc(sizeof(priorityQueue));
    pq->count = 0;
    for(int i =0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        Edge * edge = (Edge*)malloc(sizeof(Edge));
        edge->node = b;
        edge->cost = c;
        addNode(adj, a, edge);
    }
    ans[k] = 0;
    Edge * start = (Edge*)malloc(sizeof(Edge));
    start->node = k; start->cost = 0; push(pq, start);
    while(1){
        Edge* now = pop(pq);
        if(now == NULL) break;
        int curNode = now->node;
        int curCost = now->cost;
        if(ans[curNode] < curCost) continue;
        Node* cur = adj[curNode];
        while(cur!=NULL){
            Edge*temp = cur->data;
            temp->cost += curCost;
            if(temp->cost < ans[temp->node]) {
                ans[temp->node] = temp->cost;
                push(pq,temp);
            }
            cur=cur->next;
        }
    }
    for(int i=1; i<=n; i++){
        if(ans[i] = -99999) printf("-99999");
        else printf("%d\n", ans[i]);
    }
    return 0;
}

