Time Complexity
===============
- Asymptotic notation(점근적 표기법)

1. Big O Notation
2. Big Omega Notation
3. Big Theta Notation


+ example 
![image](https://user-images.githubusercontent.com/94096054/144387977-ffd44b10-5f0b-4b49-9dae-c3be1f387cac.png)


### Big O

- 빅 오 표기법은 f(n) = O(g(n)) 과 같은 모양을 하고 있다
- 이 때 f(x) <= c * g(x)를 증명할 수 있는 c을 찾으면 빅 오 표기법을 사용할 수 있다.
- 최대 복잡도(worst case)



### Big Ω(omega)

- 빅 오메가 표기법은 f(n) = O(g(n)) 과 같은 모양을 하고 있다
- 이 때  빅오 표기법과 반대로 f(x) > =c * g(x)를 증명할 수 있는 c을 찾으면 빅 오 표기법을 사용할 수 있다.
- f(x)가 최선의 경우에도 Ω(g(x))보다 크다
- 최소 복잡도(best case)

### Big θ

- 빅 세타 표기법은 따로 공식은 존재하지 않는다
- 빅 오와 빅 오메가 표기법이 참이라면 
- f(x) = θ(g(x)) 표기법을 사용할 수 있다.
