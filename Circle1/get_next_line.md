# Get Next Line

## Mandatory part - Get_next_line

|||
|-|-|
| Function name | get_next_line |
| Prototype | int get_next_line(int fd, char **line); |
| Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h|
| Parameters | #1. file descriptor for reading #2. The value of what has been read |
| Return Value | 1 : A line has been read, 0 : EOF has been reached, -1 : An error happened |
| External functs. | read, malloc, free |
| Description  | Write a function which returns a line read from a file descriptor, without the newline. |
|||
<br>
### Parameters
<br>

 #1. 읽을 파일 디스크럽터

 #2. 읽어 왔던 값
___
### Return Value
<br>
 1 : 한 라인이 읽혔을때

 0 : EOF(End-Of-File)에 도달 했을때

 -1 : 에러 발생
____
### Description
<br>
파일 디스크럽터로부터 읽어 온 하나의 라인(newline 없이)를 반환하는 함수 작성

get_next_line 함수를 반복문 안에서 호출하면 파일 디스크립터에서 사용할 수 있는 텍스트를 EOF가 올때까지 한 번에 한 줄씩 읽을 수 있을 것

파일과 표준입출력 모두 잘 작동하는지 확인 할 것

get_next_line에 필요한 함수들은 get_next_line_utils.c에 작성 (libft 사용 불가)


gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

- -D [매크로] = [매크로 값] : 외부에서 해당 매크로를 정의하고 값을 지정, 여기선 BUFFER_SIZE를 32로 지정

read 함수는 표준입력으로 또는 파일로부터 읽기 위해서 컴파일할 때 정의된 BUFFER_SIZE를 사용해야함<br><br>
___
<br>
### NOTICE
<br><br>


    Does your function still work if the BUFFER_SIZE value is 9999?
    And if the BUFFER_SIZE value is 1? And 10000000? Do you know why?
=>

    You should try to read as little as possible each time get_next_line
    is called. If you encounter a newline, you have to return the
    current line. Don’t read the whole file and then process each line.
<str>=> 가능한 적게 읽도록 할 것, newline을 만난다면 현재라인을 반환, 전체 파일을 읽고 한줄씩 처리하게끔 만들지 말자

    Don’t turn in your project without testing. There are many tests to
    run, cover your bases. Try to read from a file, from a redirection,
    from standard input. How does your program behave when you send a
    newline to the standard output? And CTRL-D?
=> 생각 해볼수 있는 모든 상황을 고려하고 테스트를 꼭 해본 다음 제출 할 것. file, stdin, redirection 모두 시도하기

   표준출력에 newline을 보내면 어떻게 작동하는가? CTRL-D는?

---
<br>

1. 만약 동일한 파일 디스크립터의 두 호출 사이에서 첫 번째 fd에서 EOF에 도달하기 전에<br>
다른 파일로 전환될 경우, 우리는 get_next_line이 정의되지 않은 동작을 가진다고 생각합니다.

2. 바이너리 파일을 읽을 때 get_next_line이 정의되지 않은 동작을 가진다고 생각 하지만,<br>
원한다면 이러한 동작을 논리적으로 작성 가능.
3. lseek는 허용된 함수가 아님. File reading은 한번만.
4. 전역번수 금지

<br>

___
<br>

## BONUS PART

<br>
이 파트를 위해서는 모든 3개의 원래의 파일에 _bonus를 붙여서 제출 할 것 (libft랑 다름)

- 하나의 정적변수로 get_next_line 성공하는 것

- get_next_line을 사용하여 다중 파일 디스크립터를 관리 할 수 있는 것

예를 들어, 파일 디스크립터 3, 4, 5가 읽을 수 있는 경우, get_next_line은 3에서 한 번, 4에서 한 번, 다시 3에서 한 번, 5에서 한 번 호출할 수 있음. 각 디스크립터의 리딩 쓰레드를 잃지 않은 채
___
<br>

## Source for GNL

<br>

### READ
저수준 파일 입출력 (system call)

    #include <unistd.h>
    ssize_t read(int fildes, void *buf, size_t nbyte);
- fildes : 읽을 파일의 디스크럽터
- buf : 읽어들인 데이터를 저장할 버퍼(배열)
- nbyte : 읽어들일 데이터의 최대 길이

Return Value : 읽어들인 데이터의 길이. 무조건 nbytes가 반환 되는게 아님 (EOF를 만난다면 끝)

<br>

처음에는 위치를 나타내는 오프셋이 파일의 시작을 가리키지만,

이후 읽어온 크기만큼 오프셋이 이동해 다음번 호출에 읽어 올 위치를 가르킴.

read 함수는 읽어 온 데이터 끝에 자동으로 '\0'을 추가해주지 않으므로 직접 추가해야함.
