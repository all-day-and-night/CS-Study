HTTP REQUEST RESPONSE HEADER
============================

1. HTTP HEADER

  * HTTP 헤더는 HTTP 본문 및 요청/응답에 대한 정보를 포함

  * 요청/응답에 대한 정보는 요청/응답에 대한 일반(General) 정보를 포함한다.

  + 헤더의 프로퍼티는 이름:값 쌍으로 설정되며 콜론(:)으로 구분된다.

  + 헤더와 본문은 개행 '\n' 으로 나뉘기 때문에 각 헤더의 항목들은 '\r'로 구분된다.

2. HTTP 헤더 유형

> HTTP 1.1에서 헤더는 3부분으로 나뉜다.

> 일반헤더(General Header)

> 요청 / 응답 헤더(Request Response Header)

> 엔터티 헤더(Entity Header)

  * 일반헤더(General Header)

    + 전송되는 HTTP 본문 컨텐츠와 관련없이 요청/응답이 생성된 날짜 및 시간 등과 같은 HTTP 통신에 대한 일반적인 정보

    + 주요 항목

      - Date : HTTP 메세지를 생성한 일시
        * Date: Mon, 20 Dec 2021 

      - Connection

      - Cache-Control

      - Pragma

      - Trailer

  * 엔터티 헤더(Entity Header)

  
  * 요청 응답 헤더(Request Response Header)

> 다시
  
