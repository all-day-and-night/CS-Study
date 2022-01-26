TCP
==============

* 통신 프로토콜 중 하나

> OSI 계층 모델의 관점에서 Transport layer(4계층)에 해당


* 양 종단 호스트 내 프로세스 상호 간에 신뢰적인 연결지향성 서비스 제공

## TCP 세션 연결

> TCP 3-WAY-HANDSHAKE를 사용

> TCP/IP 프로토콜을 이용해서 통신을 하는 응용프로그램이 데이터를 전송하기 전에 먼저 정확한 전송을 보장하기 위해 

> 상대 호스트와 사전에 세션을 수립하는 과정

> 양쪽 모두 상대편에 대한 초기 sequential number를 얻을 수 있도록 한다


![image](https://user-images.githubusercontent.com/94096054/151113882-076e3f60-248a-4189-8bfd-d0b43d98318c.png)


1. Client -> Server : TCP SYN

2. Server -> Client : TCP SYN, ACK

3. Client -> Server : TCP ACK

* SYN : "Synchronize Sequence Number" 

> segment의 첫번째 바이트의 숫자

* ACK : "Acknowledgment"

> sequential number의 다음 숫자, 계속해서 축적되어 전송 


## TCP 연결 해제 

> TCP 4-WAY-HANDSHAKE를 사용

> 기존에 보내고 있던 데이터를 안전하게 모두 전송할 때까지 연결을 유지하기 위해

> 서버와 클라이언트가 세션을 종료하는 과정

![image](https://user-images.githubusercontent.com/94096054/151114649-d3447575-17e8-4cab-8164-78a0ffd58fc6.png)


1. Client -> Server : TCP FIN

> 이 때 클라이언트는 FIN-WAIT 상태가 된다.

2. Server -> Client : TCP ACK

> 서버는 FIN 신호를 받고 ACK 신호를 클라이언트에 전송한다. 

> 자신의 통신이 끝날 때까지 기다리게 되는데 이를 "CLOSE_WAIT" 상태이다.

3. Server -> Client : TCP FIN

> 서버가 통신을 완료하면 연결해지가 준비되었음을 클라이언트에 알리는데 이 때 서버의 상태를 "LAST_ACK"이다.

4. Client -> Server : TCP ACK

> 클라이언트가 해지 준비가 되었다는 ACK 신호를 보내고 "TIME_WAIT" 상태로 변경된다.

* TIME WAIT:

> Server에서 FIN을 전송하기 전에 전송한 패킷이 지연되어 FIN 패킷보다 늦게 도착하는 상황에 대비해 

> 일정 시간동안 세션을 유지하여 받지 못한 패킷을 기다린다.

> 일정 시간이 지나면 세션을 만료하고 연결을 종료한다.






