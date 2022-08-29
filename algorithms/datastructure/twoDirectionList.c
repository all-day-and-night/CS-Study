#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
}Node;

Node *head, *tail;

void insert(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node*cur;
    cur = head->next;
    while(cur->data < data && cur != tail){//오름차순 정렬
        cur = cur->next;
    }
    Node*prev = cur->prev;
    prev->next = node;
    node->prev = prev;
    cur->prev = node;
    node->next = cur;
}

void removeFront(){
    Node * node = head->next;
    head->next = node->next;
    Node*next = node->next;
    next->prev = head;
    free(node);
}
void show() {
    Node*cur = head->next;
    while(cur != tail)  {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}
void freeAll(){
    Node*cur = head->next;
    while(cur != tail){
        Node* next = cur->next;
        free(cur);
        cur = next;
    }

}

int main(){
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
    insert(2);
    insert(1);
    insert(3);
    insert(4);
    insert(5);
    removeFront();
    show();
    freeAll();
    return 0;
}//왜그러는지 젠장