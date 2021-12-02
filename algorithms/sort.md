Sorting Algorithms
==================

### 1. insertion sort

![image](https://user-images.githubusercontent.com/94096054/144355878-cbdba51b-ee39-4bc4-b81b-5e9fceac063b.png)

-삽입 정렬(insertion sort)

자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여 자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘

+장점
구현이 간단하다

+단점
배열이 길어질수록 효율이 떨어진다.

+시간복잡도
O(N^2)


```
def insert_sort(x):
	for i in range(1, len(x)):
		j = i - 1
		key = x[i]
		while x[j] > key and j >= 0:
			x[j+1] = x[j]
			j = j - 1
		x[j+1] = key
	return x
'''



