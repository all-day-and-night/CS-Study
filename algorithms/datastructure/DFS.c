#include<stdlib.h>
#include<stdio.h>

#define MAX 1001

typedef struct Node{
    int index;
    struct Node*next;
}Node;
Node**a;
int n,m,c[MAX];//방문체크

void addFront(Node* root, int index){
    Node * node = (Node*)malloc(sizeof(Node));
    node->index= index;
    node->next = root->next;
    root->next = node;
}
void dfs(int x){
    if(c[x]){
        return;
    }
    c[x] =1;
    printf("%d", x);
    Node* cur = a[x]->next;
    while(cur != NULL){
        int next = cur->index;
        dfs(next);
        cur = cur->next;
    }
}
int main(){
    scanf("%d %d", &n, &m);
    a = (Node**)malloc(sizeof(Node*)*MAX);
    for(int i=1; i<=n ; i++){
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }
    for(int i=0; i<m; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y);
        addFront(a[y], x);
    }
    dfs(1);
    return 0;
}