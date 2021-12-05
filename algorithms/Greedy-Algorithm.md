Greedy Algorithm
================

> 탐욕 알고리즘으로 현재 상황에서 가장 좋은 선택을 하는 알고리즘이다

> 최적화를 위해 사용되지만 항상 최적의 값을 도출하지 않는다

> 그리디 알고리즘의 종류

1. Fractional Knapsack 알고리즘
2. 허프만(Huffman)
3. 크루스칼 MST
4. 프림 MST

> 그리디 알고리즘 vs 다이나믹 프로그래밍

- 둘다 최적화 부분 구조를 찾는데 사용되는 기법
1) 다이나믹 프로그래밍: 부분문제의 해결 기반으로 해결된다. 최적의 부분문제 탐색하는 방식
2) 그리디 알고리즘 : 주어진 순간에서 최선의 선택을 하는 방식으로 문제 해결. 미래의 문제 해결을 고려하지 않고 당장의 문제에서 최적의 해 선택 

### Ex) Activity Selection


https://www.acmicpc.net/problem/1931

> 회의실 배정 문제

```
import sys 
N = int(sys.stdin.readline()) 
time = [[0]*2 for _ in range(N)] 
for i in range(N): 
  s, e = map(int, sys.stdin.readline().split()) 
  time[i][0] = s 
  time[i][1] = e 
time.sort(key = lambda x: (x[1], x[0])) cnt = 1 end_time = time[0][1] 

for i in range(1, N): 
  if time[i][0] >= end_time: 
    cnt += 1 
    end_time = time[i][1] 

print(cnt)
```


### Ex) Fractional knapsack

> 일반적인 Knapsack알고리즘은 dp를 사용하여 문제를 해결해야 최적의 해를 구할 수 있다.

> 하지만 Fractional knapsack알고리즘은 greedy 알고리즘을 사용하여 문제를 해결할 수 있다.


