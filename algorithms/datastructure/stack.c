#include<stdio.h>
#include<stdlib.h>

#define SIZE 10000
#define INF 9999999

int stack[INF];
int top =-1;

void push(int data){
    if(top ==SIZE-1){
        printf("스택오버플로우 발생\n");
        return;
    }
    stack[++top] = data;
}


int pop(){
    if(top ==-1){
        printf("stackunderflow happens");
        return -INF;
    }
    return stack[top--];
}

void show(){
    for(int i=top; i>=0; i--){
        printf("%d\n", stack[i]);
    }
}
int main(){
    push(5);
    push(3);
    push(6);
    push(1);
    printf("%d\n", pop());
    show();
    return 0;;
}
