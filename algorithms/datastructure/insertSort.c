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
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", a[i]);
    for(int i=0; i<n; i++){
        int j =i;
        while(j>=0 && a[j] > a[j+1]){
            swap(&a[j], &a[j+1]);
            j--;
        }
    }
    return 0;
}