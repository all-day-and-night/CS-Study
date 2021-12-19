JVM 동작 원리 및 기본 개념
==========================

### 자바 코드 실행 과정


![image](https://user-images.githubusercontent.com/94096054/146669031-62b3fd90-baf3-4a75-9ba9-a7885d6fdcde.png)

+ 자바의 가장 큰 특징 중 하나는 어떤 하드웨어에서나 어떤 운영체제이던지 상관없이 컴파일된 코드(바이트 코드)가 실행 가능하다

+ 이러한 특징을 구현하기 위해 JVM(Java Virtual Machine)이 필요함

+ JVM : 컴파일된 코드를 실행하는 가상의 컴퓨터

+ JVM은 H/W(cpu)와 OS(운영체제) 위에서 실행되기 때문에 JVM 자체는 플랫폼에 종속적이며 각 플랫폼에 맞는 JVM을 실행해야함

![image](https://user-images.githubusercontent.com/94096054/146669511-dfe279f7-a810-4341-a9d9-e5fcfc6b8ea1.png)


1) 작성한 자바소스(Java Source), 즉 확장자가 .java인 파일을 자바 컴파일러(Java Compiler)를 통해 자바 바이트 코드로 컴파일한다.

2) 컴파일된 바이트 코드를 JVM의 클래스 로더(Class Loader)에 전달한다.

3) 클래스로더는 동적 로딩(Dynamic loading)을 통해 필요한 클래스들을 로딩 및 링크하여 런타임 데이터 영역(Runtime Data Area), 즉 JVM의 메모리에 올린다.

4) 실행 엔진(Execution Engine)은 JVM메모디에 올라온 바이트 코드들을 명령어 단위로 하나씩 가져와서 실행한다.




https://steady-snail.tistory.com/67
