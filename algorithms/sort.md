Sorting Algorithms
==================

### 1. insertion sort

![image](https://user-images.githubusercontent.com/94096054/144355878-cbdba51b-ee39-4bc4-b81b-5e9fceac063b.png)

- 삽입 정렬(insertion sort)

자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여 자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘

+ 장점
구현이 간단하다

+ 단점
배열이 길어질수록 효율이 떨어진다.

+ 시간복잡도
O(N^2)

- 최악의 경우
배열이 역순으로 정렬되어 있을 경우

+ code
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
```

### 2. selection sort

- 선택 정렬(selection sort)

1. 주어진 리스트 중에 최소값을 찾는다.
2. 그 값을 맨 앞에 위치한 값과 교체한다.
3. 맨 처음 위치를 뺀 나머니 리스트를 같은 방법으로 교체한다.

+ 장점
구현이 간단하다, 사용할 수 있는 메모리가 제한적인 경우 사용시 성능 상의 이점이 있다.

+ 단점
배열이 길어질수록 효율이 떨어진다.

+ 시간복잡도
O(N^2)

- 최악의 경우
배열이 역순으로 정렬되어 있을 경우

+ code
```
def selectionSort(x):
	length = len(x)
	for i in range(length-1):
	    indexMin = i
		for j in range(i+1, length):
			if x[indexMin] > x[j]:
				indexMin = j
		x[i], x[indexMin] = x[indexMin], x[i]
	return x
```



### 3. bubble sort

- 거품 정렬(bubble sort)

1. 두 인접한 원소를 검사하여 정렬하는 방법
2. 시간복잡도가 O(N^2)로 상당히 느리지만 코드가 단순해서 자주 사용된다.

+ 장점
구현이 간단하다 

+ 단점
시간 복잡도가 상당히 느리다

+ 시간복잡도
O(N^2)

- 최악의 경우
배열이 역순으로 정렬되어 있을 경우

+ code
```
def bubbleSort(x):
	length = len(x)-1
	for i in range(length):
		for j in range(length-i):
			if x[j] > x[j+1]:
				x[j], x[j+1] = x[j+1], x[j]
	return x
```




### 4. merge sort

- 병합 정렬(merge sort)

1. 분할 정복 알고리즘
2. 정렬되지 않은 리스트를 하나의 원소만 포함하는 n개의 부분 리스트로 분할한다.
3. 부분리스트가 하나만 남도록 반복해서 병합하여 정렬된 리스트를 생성한다.
4. 재귀함수(recursion) 사용


+ 장점
시간 복잡도가 O(N log N)이다


+ 시간복잡도
O(N log N)

+ code
```
def merge(left, right):
    len_left = len(left)
    len_right = len(right)

    left_cnt, right_cnt = 0, 0
    merge_list = []

    while left_cnt < len_left and right_cnt < len_right:
        if left[left_cnt] > right[right_cnt]:
            merge_list.append(right[right_cnt])
            right_cnt += 1
        else:
            merge_list.append(left[left_cnt])
            left_cnt += 1

    while left_cnt < len_left:
        merge_list.append(left[left_cnt])
        left_cnt += 1

    while right_cnt < len_right:
        merge_list.append(right[right_cnt])
        right_cnt += 1

    print(merge_list)
    return merge_list

def merge_sort(data):
    if len(data) <= 1:
        return data

    mid = int(len(data) / 2)

    left = data[:mid]
    right = data[mid:]

    left1 = merge_sort(left)
    right1 = merge_sort(right)

    return merge(left1, right1)
```

+ recursion tree
![image](https://user-images.githubusercontent.com/94096054/144385116-7ead8c97-dd43-475e-ad1d-81b946a81657.png)




### 5. quick sort

- 퀵 정렬(quick sort)

1. 분할 정복 알고리즘
2. 정렬되지 않은 리스트를 하나의 원소만 포함하는 n개의 부분 리스트로 분할한다.
3. 부분리스트가 하나만 남도록 반복해서 병합하여 정렬된 리스트를 생성한다.
4. 재귀함수(recursion) 사용

+ 장점
시간 복잡도가 O(N log N)이다

+ 단점
리스트가 이미 정렬되어 있을 경우 분할이 불균형하게 되어 시간복잡도가 O(N^2)가 될 수 있음

+ 시간복잡도
O(N log N)



+ code
```
def quickSort(data):
    if len(data) <= 1:
        return data

    pivot = data[0]
    left, right = [], []
    left = [item for item in data[1:] if pivot > item]
    right = [item for item in data[1:] if pivot < item]

    return quickSort(left) + [pivot] + quickSort(right)
```

+ worst case
![image](https://user-images.githubusercontent.com/94096054/144385696-e0fa8353-23d3-4b13-8b4d-96f343e805cc.png)




