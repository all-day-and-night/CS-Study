#include<stdio.h>
#include<stdlib.h>

int a[1001][1001];
int n, m;

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m ; i++){
        int x, y;
        scanf("%d %d",&x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d", a[i][j]);
        }
        printf("\n");
    }//여기까지 2차원배열을 이용한 무방향 비가중치 그래프
    return 0;
}