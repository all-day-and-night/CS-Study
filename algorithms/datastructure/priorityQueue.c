#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10000

typedef struct priorityQueue{
    int heap[MAX_SIZE];
    int count;
}priorityQueue;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(priorityQueue * pq, int data){
    if(pq->count >=MAX_SIZE) return;
    pq->heap[pq->count] = data;
    int now = pq->count;
    int parent = (pq->count-1)/2 ;
    while(now>0 && pq->heap[now] > pq->heap[parent]){
        swap(&pq->heap[now], &pq->heap[parent]);
        now = parent;
        parent = (parent-1)/2;
    }
    pq->count++;
}

int pop(priorityQueue*pq){
    if(pq->count <=0) return -MAX_SIZE;
    int res = pq->heap[0];
    pq->count--;//왜지
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftChild =1, rightChild=2;
    int target = now;
    //새원소 추출후 하향식으로 힙 구성
    while(leftChild < pq->count){
        if(pq->heap[target] < pq->heap[leftChild]) target = leftChild;
        if(pq->heap[target] < pq->heap[rightChild]) target = rightChild;
        if(target == now) break;//더이상 내려가지 않을때 종료
        else{
            swap(&pq->heap[now], &pq->heap[target]);
            now = target;
            leftChild = now*2 +1;
            rightChild = now*2 +2;
        }
    }  
    return res;
}

int main() {
    int n, data; 
    scanf("%d", &n); 
    priorityQueue pq; 
    pq.count = 0; 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &data); 
        push(&pq, data); 
    } 
    for (int i = 0; i < n; i++) { 
        int data = pop(&pq); 
        printf("%d ", data); 
    } 
    return 0;
}