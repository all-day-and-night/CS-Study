Dynamic Programming
===================

> 하나의 문제를 단 한번만 풀도록 하는 알고리즘

> 분할정복 기법은 동일한 문제를 다시 푸는 단점을 가지고 있는데 기존에 풀었던 문제를 기억하고 재활용하여 효율성을 높임(Memorization)



### Longest Common Subsequence(LCS)

> 두개의 배열 중 가장 긴 부분수열을 구하는 것

- Brute force 기법을 사용할 경우 시간 복잡도는 다음과 같다.

+ a = [1 .. m], b = [1 .. n] 일 때

> 각 부분 수열마다 O(n)의 시간이 소요되고

> a의 부분수열 2 ^ m이 생성되므로 

> 시간 복잡도는 O(n * 2 ^ m) => exponential time


- Dynamic programming을 사용한다면 O(m * n)으로 줄일 수 있다.

> 2차원 배열을 사용하여 기존의 값을 저장하고 다음 연산에 사용하여 LCS를 찾는다.

![image](https://user-images.githubusercontent.com/94096054/144706361-c569da95-179c-439d-b13b-231bf88a26c9.png)


![image](https://user-images.githubusercontent.com/94096054/144706384-4b86e1c7-83e8-45b7-a068-2e21829e2044.png)


![image](https://user-images.githubusercontent.com/94096054/144706420-69b8cb26-8112-4fd7-a142-b1ce1daa64fe.png)


- code
```
def sol(str1, str2):
    len1 = len(str1)
    len2 = len(str2)

    mat = [[0] * (len2 + 1) for _ in range(len1 + 1)]

    for i in range(1, len1+1):
        mat[i][0] = 0
    for i in range(1, len2+1):
        mat[0][i] = 0


    for i in range(1, len1+1):
        for j in range(1, len2+1):
            if str1[i-1] != str2[j-1]:
                mat[i][j] = max(mat[i-1][j], mat[i][j-1])
            else:
                mat[i][j] = mat[i-1][j-1] + 1
    for m in mat:
        print(m)
    
    return mat[-1][-1] 

```


### Knapsack Algorithm



