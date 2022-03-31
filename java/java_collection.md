Collections

============

> 데이터의 집합, 그룹

> 데이터, 자료구조인 컬렉션과 이를 구현하는 클래스를 정의하는 인터페이스 제공

1. List
2. Set
3. Queue
4. Map


![image](https://user-images.githubusercontent.com/94096054/160990347-2ba34be1-4d7a-490c-ae42-4d31cfea35eb.png)


## collection 인터페이스의 특징

1. Set

  * 구현 클래스: HashSet, TreeSet
  * 순서를 유지하지 않는 데이터의 집합으로 데이터의 중복을 허용하지 않는다. 
  
  * HashSet:
    
    > 가장 빠른 임의 접근 속도
    > 순서를 예측할 수 없음

  * TreeSet
  
    > 정렬방법을 지정할 수 있음
    
    
2. List

  * 구현 클래스: LinkedList, Vector, ArrayList
  * 순서가 있는 데이터의 집합으로 중복을 허용
  * stack 클래스 사용 가능
  
  * LinkedList
  
    > 양방향 포인터 구조로 데이터의 삽입, 삭제가 빈번할 경우 데이터의 위치 정보만 수정하면 되기에 유용
    > 스택, 큐, deque 등을 만들기 위한 클래스

  * Vector
  
    > 과거에 대용량 처리를 위해 사용했으며, 내부에서 자동으로 동기화처리가 일어나 비교적 성능이 좋지 않고 무거움
    > 동기화를 통해 안전성 확보

  * ArrayList
  
    > 단방향 포인터 구조로 각 데이터에 대한 인덱스를 가지고 있어 조회 기능에 성능이 뛰어남

  
3. Queue

  * 구현 클래스: LinkedList, PriorityQueue
  * List와 유사
  * queue의 기능을 LinkedList로 구현
  * Heap을 PriorityQueue로 구현

4. Map

  * 구현 클래스: HashTable, HashMap, TreeMap
  * key:value의 쌍으로 이루어진 데이터의 집합으로 순서는 유지되지 않음
  * Key의 중복을 허용하지 않지만 value의 중복을 허용

  * HashTable
  
    > HashMap보다 느리지만 동기화 지원
    > null 불가

  * HashMap
  
    > 중복과 순서가 없으며 Null 값이 올 수 있다.
    > hashTable과 같이 동기화를 지원하는 ConcurrentHashMap 존재

  * TreeMap
  
    > 정렬된 순서대로 Key:value를 저장하여 검색이 빠름










