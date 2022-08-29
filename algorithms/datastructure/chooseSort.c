#include <stdio.h> 
#include <limits.h> 
#define INF 9999999;
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n, min, index;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++){
        min = INF;
        for(int j=i; j<n; j++){
            if(min>a[j]){
                min =a[j];
                index = j;
            }
        }
        swap(&a[i], &a[index]);
    }
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}