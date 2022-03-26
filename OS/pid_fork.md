PID FORK
============


## PID

> Process Identifier의 약자로, 운영체제에서 프로세스를 식별하기 위해 할당하는 고유 번호

> fork라는 시스템 호출에 의해 반환

* Process

> 디스크에 있던 프로그램 파일이 메모리에 올려지고 시스템의 스케줄에 따라 실행되는 실행 단위

## FORK

> fork() 함수는 현재 실행되고 있는 프로세스를 복사해 주는 함수

* fork 함수를 사용하는 이유

> 하나의 프로세스는 멀티 스레드를 통해 나눠서 작업한다. 

> fork를 통해 프로세스를 복사하여 작업하면 더 많은 작업을 빠른 시간 내에 동시 작업 할 수 있기 때문에 사용한다.

* fork를 통해 만들어진 자식 프로세스

  + 자식 프로세스는 고유한 프로세스 아이디를 가진다.
  + 자식 프로세스는 고유한 메모리 공간을 가진다.
  + 자식 프로세스는 부모 프로세스의 file descriptor의 복사본을 가지며 부모와 자식 프로세스의 file descriptor는 같은 파일을 가리킨다.
  


* fork 예제

```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int parentcount = 0, childcount = 0;
    pid_t pid;

    pid = fork();

    switch(pid) {
        // 에러 발생
        case -1 : 
        {
            printf("error\n");
            return -1;
        }
        // 자식 프로세스
        case 0 :
        {
            printf("child process=%d\n", getpid());
            while(1) {
                printf("child=%d\n", childcount--);
                sleep(1);
            }
            break;
        }
        // 부모 프로세스
        default :
        {
            printf("parent process=%d\n", getpid());
            while(1) {
                printf("parent=%d\n", parentcount++);
                sleep(1);
            }
            break;
        }
    }

    return 0;
}
```

* getpid 함수는 함수를 호출한 프로세스의 ID를 반환한다. 부모 프로세스가 먼저 실행되고 자식 프로세스와 번갈아가며 실행된다.



## fork vs thread

* fork : 자기 자신과 똑같은 프로세스 생성
* pthread : 스레드는 자신이 원하는 작업을 태스크의 형태로 생성

> 가장 큰 차이점은 별도의 address 공간을 가지는 지의 여부

> fork로 생성한 프로세스는 부모 프로세스의 메모리 공간에 접근할 수 없다.(반대의 경우도 마찬가지, 메모리 공간이 다르기 때문)

> 하지만 pthread는 메모리를 공유할 수 있고 동기화를 위해 여러 가지 방법이 존재한다.

> 프로세스끼리 데이터를 주고 받기 위해서는 IPC라고 하는 통신 기법을 사용해야 한다.


