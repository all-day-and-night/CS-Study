#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000
//정렬을 가정
int a[MAX];
int founded =0;

int search(int start, int end, int target){
    if(start>end) return -9999;
    int mid = (start+ end)/2;
    if(a[mid]==target) return mid;
    else if(a[mid]>target) return search(start, mid-1, target);
    else return search(mid+1, end, target);
}

int main(){
    int n, target;
    scanf("%d %d", &n, &target);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int result = search(0, n-1, target);
    if(result != -9999) printf("%dst element\n", result+1);
    else printf("couldn't find the element\n");
    return 0;
}
