
# NETWAHT

## What is an IP address ?
### IP address : Internet Protocol address (인터넷규약주소)

컴퓨터 네트워크에서 장치들이 서로를 인식하고 통신을 하기 위해서 사용하는 특수한 번호

네트워크에 연결된 장치가 라우터이든 일반 서버이든, 모든 기계는 이 특수한 번호를 가지고 있어야함

공유기를 사용하면 사설 ip를 갖게 되는데
결국 통신을 위해 외부의 공인 ip를 사용한다.

하나의 IP는 네트워크 부분 + 호스트 부분으로 구성. 하나의 네트워크 즉 하나의 브로드캐스트 도메인에 있는 IP끼리 통신하기 위해선 네크워크 영역이 같아야하며, 호스트 IP는 달라야함.

호스트 IP가 다르지 않다면 IP 충돌이 발생.

네트워크 영역이 달라도 라우터나 게이트웨이와 같은 통신장비를 통해 통신할 수 있음.

### IP version 4

	주소의 범위는 32비트로 보통 0~255 사이의 십진수 넷을 쓰고 구분하여 나타냄

	중간의 일부 번호들은 특별한 용도를 위해 사용. 이를테면 127.0.0.1은 localhost(로컬 호스트)로 자기 자신을 가리킴

### IP version 6

	 주소 길이는 128비트. IPv6 주소는 보통 두 자리 16진수 여덟 개를 쓰고 각각을 : 기호로 구분함
2606:4700:4700:0000:0000:0000:0000:1111의 경우 0만 있는 4~7번째 필드를 생략하여 2606:4700:4700::1111로 표기 가능

----

## What is a class of IP addresses ?
하나의 네트워크안에 IP들은 네트워크 영역은 같아야하고, 호스트 IP는 서로 달라야 통신이 가능

- `A CLASS` : 호스트 수가 제일 많은 클래스

network address : 0 ~ 127

host ip : 0.0.0 ~ 255.255.255

첫번째 옥테드만 network adress를 나타낸다.

- `B CLASS` : 2진수로 표현 했을때 반드시 10으로 시작함

network address : 128.0 ~ 191.255

host ip : 0.0 ~ 255.255

- `C CLASS` : 2진수로 표현 했을때 반드시 110으로 시작함

network address : 192.0 ~ 223.255.255

host ip : 0 ~ 255

 `C CLASS`  `203.240.100.1` 에서
203.240.100은 `네트워크 영역`, 1은 `호스트 IP`

------
## What is a Netmask ?

하나의 네트워크를 몇 개의 네트워크로 나누어 사용할 때에 나눠진 각각의 네트워크를 구분하기 위해 사용하는 특수한 bit.

IP 주소와 넷마스크를 AND연산을 하면 네트워크 주소를 얻을수 있다.

일반적으로 사용하는 넷마스크는 `255.255.255.0`

255는 10 진수에 해당하거나 8 개의 이진수 1의 문자열의 합이므로 255는 네트워크를 숨기고 0은 IP 주소의 호스트 컴퓨터 부분이 네트워크에 액세스하는 모든 사람이 볼 수 있도록 허용함.

## What is the subnet of an IP with Netmask ?

### Subnetting
자원의 효율적 분배 (네트워크 영역 + 호스트 영역)
ip자원의 한계는 존재 하므로,
필요한 네트워크 주소만 호스트 IP로 할당 할 수 있게 만들어 네트워크 낭비를 방지

### Subnetmask

필요없는 부분을 가려준다고 생각 (필요한 부분에만 집중)

서브넷마스크에서 1은 연속적으로만 올 수 있다.

B class의 2진수 표현은 11111111.11111111.00000000.00000000

즉 1은 네트워크 영역을, 0은 host ip를 나타냄

192.168.3.19/24에서 24는 `서브넷 마스크의 bit수`를 의미 함. (C class : 255.255.255.0)
### 기본서브넷마스크

별개의 서브넷마스크를 생성하지 않아도 기본적으로 적용되어 있는게 기본 서브넷마스크이고
기본서브넷마스크로 쪼개진 네트워크 주소를 서브넷 네트워크 라고 함

- 클래스를 사용한다 = 세브넷마스크를 사용한다

IP 210.100.100.1 기본서브넷마스크 : 255.255.255.0 서브넷네트워크 : 210.100.100.0
즉 B class 일 경우 기본서브넷마스크는 255.255.0.0 C는 255.0.0.0

### 서브넷네트워크

	1101 0010. 0110 0100. 0110 0100. 0000 0001 = 210.100.100.1 (IP주소)

	1111 1111. 1111 1111. 1111 1111. 0000 0000 = 255.255.255.0 (기본서브넷마스크)

	1101 0010. 0110 0100. 0110 0100. 0000 0000 = 210.100.100.0 (서브넷네트워크)

위에서 알 수 있듯이 IP주소와 서브넷마스크를 논리 AND 연산하면 서브넷네트워크를 구할 수 있음.

150.150.100.1 이 경우 B CLASS에 해당하지만,

	1001 0110. 1001 0110. 0110 0100. 0000 0001 = 150.150.100.1 (IP주소)

	1111 1111. 1111 1111. 1111 1111. 0000 0000 = 255.255.255.0 (C클래스 기본서브넷마스크)

	1001 0110. 1001 0110. 0110 0100. 0000 0000 = 150.150.100.0 (서브넷네트워크)

C클래스 기본서브넷마스크를 사용하여 네트워크영역을 150.150.100까지 볼 수 있다.

즉 네트워크 영역을 늘리고 호스트 영역을 줄이겠다는 뜻을 내포하고 있음.

이렇게 하나의 주소에 서브넷 마스크를 씌워서 자신에게 맞는 네트워크를 만드는 것을 서브네팅이라고 함
(참고로 서브넷마스크로 나뉘어진 서브넷네트워크간 통신은 라우터를 통해서 통신이 되어야 함.
다른 말로 서브넷네트워크는 하나의 독립적인 네트워크)

CIDR ( Classless Inter-Domain Routing)에 의해 넷마스크는 서브넷마스크로 통용되고 있음

	최신의 IP 주소 할당 방법이다. 사이더는 기존의 IP 주소 할당 방식이었던 네트워크 클래스를 대체하였다.
	사이더는 IP 주소의 영역을 여러 네트워크 영역으로 나눌 때 기존방식에 비해 유연성을 더해준다

------

## What is the broadcast address of a subnet ?

### broadcast address
특정 네트워크에 속하는 모든 호스트들이 듣게되는 주소를 의미

네트워크 주소와는 반대로 특정 네트워크의 맨 마지막 주소를 브로드캐스트 주소로 사용

예) C class로 특정 네트워크를 구성하였고 네트워크 주소가 192.168.2.0 이라고 한다면 브로드캐스트주소는 192.168.2.255

- 네트워크 주소에서 서브넷마스크의 0으로된 비트를 모두 1로 바꾸어 주면 브로드캐스트 주소를 얻을 수 있음

IP주소가 165.132.120.10 이고, 서브넷마스크가 255.255.252.0 이라고 가정하면

	10100101 10000100 01111000 01100100 (IP)

	11111111 11111111 11111100 00000000 (subnet mask)

AND연산 결과 10100101 1000100 01111000 00000000 => 165.132.120.0을 얻을 수 있다. (네트워크 주소)

여기서 subnet mask의 0인 부분을 1로 치환하면 10100101 1000100 01111011 11111111

=> 165.132.123.255 브로드캐스트 주소가 나온다.

- 그러므로컴퓨터가 사용하는 IP주소 165.132.120.10 이 속한 네트워크는 165.132.120.0 ~ 165.132.123.255 이다.
-----

## What are the different ways to represent an ip address with the Netmask ?

 	255.255.255.0/24
	11111111.11111111.11111111.00000000
또는

	 255.255.0.0/16
	 11111111.11111111.00000000.00000000
------
## What are the differences between public and private IPs ?
### 공인 IP (public IP)
 - 인터넷 사용자의 로컬 네트워크를 식별하기 위해 ISP(인터넷 서비스 공급자)가 제공하는 IP 주소
 - 공인 IP 주소를 사용하는 경우, 방화벽 등의 보안 프로그램을 설치할 필요가 있음

### 사설 IP (Private IP)

- 로컬 IP, 가상 IP

- IPv4의 주소 부족으로 인해 서브네팅된 IP이기 때문에 라우터에 의해 로컬 네트워크 상의 PC나 장치에 의해 할당

- 주소 대역 : 다음 3가지 주소 대역으로 고정
    - Class A : **10**.0.0.0 ~ **10**.255.255.255
    - Class B : **172.16**.0.0 ~ **172.31**.255.255
    - Class C : **192.168**.0.0 ~ **192.168**.255.255

→ 인터넷 상에서 서버를 운영하고자 할 때에는 공인 IP를 고정 IP로 부여하는 것이 중요

- 공인 IP를 부여받지 못하면 다른 사람이 내 서버에 접속할 수 없고
- 고정 IP를 부여하지 않으면 내 서버가 아닌 다른 사람의 서버로 접속될 수 있기 때문

→ 반면, 집에서 사용하는 인터넷 서비스 업체는 각 가정마다 공인 IP를 유동 IP로 부여하고, 공유기 내부에서는 사설 IP를 유동 IP로 부여하는 것이 일반적

||||
|-|-|-|
|         |  공인 IP (public IP) | 사설 IP (Private IP)|
| 할당 주체 | ISP(인터넷 서비스 공급자) | 라우터(공유기) |
|할당 대상 |개인 또는 회사의 서버(라우터) |개인 또는 회사의 기기|
|고유성|인터넷 상에서 유일한 주소| 하나의 네트워크 안에서 유일|
|공개 여부| 내/외부 접근 가능 |외부 접근 불가능|
||||
## What is TCP ?
### TCP (Transmission Control Protocol) : 전송 조절 프로토콜
- IP는 패킷 전달 여부를 보증하지 않고, 패킷을 보낸 순서와 받는 순서가 다를 수 있음(unreliable datagram service)

- TCP는 IP 위에서 동작하는 프로토콜로, 데이터의 전달을 보증하고 보낸 순서대로 받게 해줌.

- HTTP,FTP,SMTP 등 TCP를 기반으로 한 많은 수의 애플리케이션 프로토콜들이 IP 위에서 동작하기 때문에, 묶어서 TCP/IP로 부르기도 함

## What is UDP ?
## What are the network layers ?
## What is the OSI model ?
## What is a DHCP server and the DHCP protocol ?
## What is a DNS server and the DNS protocol ?
## What are the rules to make 2 devices communicate using IP addresses ?
## How does routing work with IP ?
-----
## What is a default gateway for routing ?

### GATEWAY
 서로 다른 네트워크를 연결해주는 특정 장비나 특정 호스트를 의미

가장 일반적인 장비는 라우터(Router), 리눅스 시스템도 게이트 웨이로 사용 가능

일반적인 서버나 호스트에선 자기 자신의 패킷이 아닌 것을 받으면 그냥 지워 버리는데, 게이트웨이는 라우팅테이블을 확인하여 받은 패킷을 가장 적합한 다른 네트워크로 전달해주는 역할을 함

이를 `IP 포워딩` 또는 `패킷 포워딩`이라 함

일반적으로 gateway ip address로 사용되는 것은 특정 네트워크 내에서 호스트주소로 사용되는 IP 주소들 가운데 맨 마지막 IP주소인 254번을 주로 사용

## What is a port from an IP point of view and what is it used for when connecting to another device ?