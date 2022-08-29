#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 9999999;

typedef struct Node{
    char data[100];
    struct Node*next;
}Node;
typedef struct Stack{
    Node * top;
}Stack;

void push(Stack * stack, char *data){
    Node*node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = stack->top;
    stack->top = node;
}
char * getTop(Stack * stack){
    Node * top = stack->top;
    return top->data;
}

char *pop(Stack * stack){
    if(stack->top == NULL){
        printf("스택언더플로우 발생\n");
        return -INF;
    }
    Node *node = stack->top;
    char*data = (char)malloc(sizeof(char)*100);
    strcpy(data, node->data);
    stack->top = node->next;
    free(node);
    return data;
}

int getPriority(char*i){//우선순위 두기
    if(!strcmp(i, "(")) return 0;
    if(!strcmp(i, "+")||!strcmp(i, "-")) return 1;
    if(!strcmp(i, "*")||strcmp(i, "/")) return 2;
    return 3;
}

char *transition(Stack *stack, char**s, int size){
    char res[1000] = "";
    for(int i=0; i<size; i++){
        if(!strcmp(s[i],"+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")){
            while(stack->top !=NULL && getPriority(getTop(stack)) >= getPriority(s[i])){
                strcat(res, pop(stack));
                strcat(res, " ");
            }
            push(stack, s[i])
        }
        else if(!strcmp(s[i], "(")) push(stack, s[i]);
        else if(!strcmp(s[i], ")")){
            while(strcmp(getTop(stack), "(")){
                strcat(res, pop(stack));
                strcat(res, " ");
            }
            pop(stack);
        }
        else strcat(res, s[i]); 
        strcat(res, " ");
    }
    while(stack->top != NULL){
        strcat(res, pop(stack)); strcat(res, " ");
    }
    return res;
}
void calculate(Stack *stack, char **s, int size) { 
    int x, y, z; 
    for (int i = 0; i < size; i++) { 
        if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
             x = atoi(pop(stack)); 
             y = atoi(pop(stack)); 
             if (!strcmp(s[i], "+")) z = y + x; 
             if (!strcmp(s[i], "-")) z = y - x; 
             if (!strcmp(s[i], "*")) z = y * x; 
             if (!strcmp(s[i], "/")) z = y / x; 
             char buffer[100]; 
             sprintf(buffer, "%d", z); //숫자를 문자의 형태로 초기화
             push(stack, buffer); } 
             else { push(stack, s[i]); } } 
    printf("%s ", pop(stack)); 
}


int main(){
    //다시 해봐야해 이정도도 못하면 ㅄ 인정?
    return 0;
}