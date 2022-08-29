#include<stdio.h>
#include<stdlib.h>

#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front=0;
int rear =0;

void push(int data){
    if(rear >= SIZE){
        printf("큐 오버플로우가 발생했습니다.\n");
        return 0;
    }
    queue[rear++] = data;
}

int pop(){
    if(front == rear){
        printf("큐 언더플로우가 발생했습니다.\n");
        return -INF;
    }
    return queue[front++];
}

void show(){
    for(int i=front; i<rear; i++){
        printf("%d\n", queue[i]);
    }
}

int main(){
    push(7);
    push(5);
    push(4);
    pop();
    push(0);
    show();
    return 0;
}