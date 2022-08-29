#include<stdio.h>
#include<stdlib.h>

#define NUMBER 7

int a[] = {7, 1, 9, 5,6,4,1};
int tree[4*NUMBER];//모든 범위 커버 가능

int init(int start, int end, int node){
     if(start == end) return tree[node] = a[start];
     int mid = (start + end) /2;
     return tree[node] = init(start, mid, node* 2) + init(mid + 1, end, node*2 + 1);
 }

//start, end => index
//left, right => range that get sum

int sum(int start, int end, int node, int left, int right){
    //out of range
    if(left > end || right < start) return 0;
    // in of range
    if(left < end && right > start) return tree[node];
    //get sum devided two part
    int mid = (start + end) /2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}
//dif is the result of update
void update(int start, int end, int node, int index, int dif){
    if(index < start || index > end) return;
    tree[node]+=dif;
    if(start == end) return;
    int mid = (start + end) /2;
    update(start, mid, node * 2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
}

int main() {
    init(0, NUMBER -1, 1);
    printf("%d \n", sum(0, NUMBER - 1, 1, 0, 6));
    printf("update index 5 to +3\n");
    update(0, NUMBER -1, 1, 5, 3);
    printf("%d in range of 3 to 6\n", sum(0, NUMBER-1, 1, 3, 6));
    return 0;
}