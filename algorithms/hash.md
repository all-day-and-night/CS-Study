Hash Table
==========

- density dependent Search
- Quantity dependent Search
- 적은 리소스로 많은 데이터를 효율적으로 관리


![image](https://user-images.githubusercontent.com/94096054/144587599-7629485e-0cb1-41a7-a69a-096bbf6e1c48.png)


### Direct access table

![image](https://user-images.githubusercontent.com/94096054/144583316-4b968935-c8d2-428d-aa05-b2118e39b180.png)

+ 장점
- 각 연산(insert, delete, search)이 항상 같은 시간이 소요된다.

+ 단점
- key의 범위에 따라 메모리를 요구한다. 범위가 크다면 사용하지 않는 것이 좋다.


### Hash function

- 임의의 길이의 데이터를 고정된 길이의 데이터로 매핑하는 함수
- hash table 자료구조에 사용되며 데이터 검색의 속도를 향상시킨다

+ 충돌(collision):
- 해시 함수를 사용하여 key를 매핑할 경우 다른 데이터들이 같은 값으로 매핑되는 경우



### Collision resolution


1. Chaining

- 같은 슬롯에 매핑될 경우 링크드 리스트를 사용하여 값을 가지고 있는 노드를 추가하는 방법

+ code
```
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int hash_value = 7;

typedef struct Node{
    int value;
    struct Node* Next;
}Node;

int hash_func(int a ,int m){
    int result = a % m;
    return result;
}

void add_hash_data(Node** hashTable, int key, int m){
    
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = key;
    node->Next = NULL;

    int hash_key = hash_func(key, m);
    if (hashTable[hash_key] == NULL){
        hashTable[hash_key] = node;
    }
    else{
        node->Next = hashTable[hash_key];
        hashTable[hash_key] = node;
    }
}
```

2. Division method

+ hash function을 modular를 사용하여 key를 매핑
+ h(k) = k mod m

3. Multiplication method

+ key가 정수형이고 m = 2^r, bit 수는 w일 경우
- h(k) = ((A * K) mod 2 ^ w) right shift (w - r)
- A : 2 ^ (w-1) < A < 2 ^ w


4. Open addressing
- chaining과 다르게 한 슬롯에 들어갈 수 있는 엔트리가 하나인 해시 테이블
- 해시 함수로 얻은 주소가 아닌 다른 주소에 데이터를 저장할 수 있도록 허용
- 해시 충돌이 일어날 가능성 농후 probing(탐사) 방식으로 해결
- probing: 삽입, 삭제, 탐색을 수행하기 위해 해시 테이블 내 새로운 주소(해시값)를 찾는 과정

+ Linear probing

- 최초 해시값에 해당하는 슬롯에 다른 데이터가 이미 있다면 해당 해시값에서 고정폭을 옮기면서 다음 해시값에 해당하는 슬롯에 접근
- 빈 슬롯을 찾을 때까지 수행
- h(k, i) = (h'(k) + i) mod m
- 탐사 이동폭이 고정되어 있어 특정 해시값 주변 슬롯이 모두 채워져 있는 경우 primary clustering 문제에 취약

- code
```
void linear_insert(int *table, int value){
    int key;
    int i = 0;
    while(1){
        key = ((value % M) + i) % M;
        if(table[key] == -1){
            table[key] = value;
            break;
        }
        i++;
        cnt++;
    }
}
```

+ Quadratic probing

- Linear probing과 비슷하지만 고정폭이 제곱수로 늘어나는 특징을 갖고 있다
- 여러 개의 서로 다른 키들이 동일한 초기 해시값을 갖는 secondary clustering에 취약

- code
```
void quad_insert(int *table, int value){
    int key;
    int i=0;
    while(1){
        key = ((value % M) + i * 1 + 3 * i * i) % M;
        if(table[key] == -1){
            table[key] = value;
            break;
        }
        i++;
    }
}
```

+ Double hashing

- 탐사할 해시값의 규칙성을 없애서 clustering 방지
- 최초의 해시값을 얻는 해시 함수 + 충돌이 일어났을 때 탐사 이동폭을 얻는 해시함수
- 최초의 해시값이 같더라도 탐사 이동폭이 달라지기 때문에 primary, secondary clustering 모두 완화
- h(k, i) = (h1(k) + i * h2(k)) mod m

- code
```
void double_insert(int *table, int value){
    int key;
    int i=0;
    while(1){
        key = ((value % M) + i * (value % (M-1))) % M;
        if(table[key] == -1){
            table[key] = value;
            break;
        } 
        i++;
    }
}
```

+ 계산 복잡성

<br>
open addressing은 chaining과 달리 해시 테이블의 크기가 고정되어 있어 n개 데이터를 모두 저장하려는 경우 
Load Factor α=n/m 는 1과 같거나 작다고 가정한다.(즉 open addressing은 해시 테이블에 데이터가 가득 차지 않는다는 것을 전제한다)




