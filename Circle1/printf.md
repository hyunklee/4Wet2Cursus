# ft_printf
Because putnbr and putstr aren’t enough

    int pirntf(const char* fromat, ...);

첫 번째 인자엔 "출력할 데이터와 그 서식"이 오고 

두 번째 인자부턴 서식 지정자의 갯수와 종류에 따라 변수가 오게 됨

### Return value

출력되는 문자의 갯수가 반환된다

예를 들어

    int main(void)
    {
        char c[10] = "abcdefg";

        printf("%d",printf("12345678%s\n",c));
    }

이 경우 9가 아닌 16이 반환 됨
### 서식 지정자(format specifier)

- %c : 문자
- %s : 문자열
- %p : 포인터의 메모리 주소
- %d : 부호 있는 10진 정수
- %i : 부호 있는 10진 정수
- %u : 부호 없는 10진 정수
- %x : 부호 없는 16진 정수 (소문자)
- %X : 부호 없는 16진 정수 (대문자)
- %% : '%'를 출력하는 방법 
-----------------
## Mandatory part

|||
|-|-|
| program name | libftprintf.a |
| Turn in files | *.c, */*.c, *.h, */*.h, Makefile|
| Makefile | all, clean, fclean, re, bonus |
| External functs. | malloc, free, write, va_start, va_arg, va_copy, va_end |
| Libft authorized | yes |
| Description  | Write a library that contains ft_printf, a function that will mimic the real printf |
|||


- It must not do the buffer management like the real printf

    실제 printf처럼 버퍼 관리를 해주지 않아야 함.
- You must use the command ar to create your librairy, using the command libtool is forbidden.

    라이브러리를 만들기 위해 ar 명령어를 사용해야함. libtool은 사용 금지.

------------
## Technical Reference

### 가변 인자 (Variable Arguement)

    int pirntf(const char* format, ...);
인자의 `...`은 가변 인자 혹은 가변 파라미터라고 불림

`...`의 영역에 매개변수로 아무것도 넘겨주지 않거나 여러개 넘길 수 있음

    #include <stdarg.h>
아래 4가지 매크로가 정의된 헤더

    va_list ap
각 가변 인자의 시작 주소를 가리킬 포인터로 사용 됨

    void va_start(va_list ap, variable_name);

 - ap : 인수(arguement) va_list로 만든 포인터를 받음
 - variable_name : 마지막 고정 인수 ( 이 경우 format에 해당)
 
 가변 인자를 가져올 수 있도록 포인터를 설정

    var_type va_arg(va_list ap, var_type);
- ap : va_list로 만든 포인터
- var_type : int나 long,double 과 같은 타입 이름이 담김

var_type일 경우 인수는 int, long, decimal, double, struct, union, pointer 만 지원됨

가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져 옴

va_list의 포인터를 다음 가변인자로 이동시켜 주는 매크로

    void va_copy(va_list dest, va_list src);
- dest : src의 사본을 담을 변수
- src : dest를 초기화 하는데 사용 될 주소(사본)

원본 주소에 구애 받지 않고 사용 가능한 copy본을 생성 할 때 사용

    void va_end(va_list arg_ptr);

- ap : va_list로 만든 포인터
가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화 해주는 역할



# BONUS PART
서식지정자에는 형식태그(format tag)가 올 수 있다.

물론 []부분은 생략 가능

    %[flag][width][.precision]서식지정자


- Manage any combination of the following flags: ’-0.’ and minimum field width
with all conversions

여기서 다뤄야 할 플래그는 -, 0, . 3가지 (width와 함께)

 1. "-" : 왼쪽정렬 (기본은 오른쪽)
 2. "0" : 오른쪽 정렬 일 때 공백을 0으로 매꿔줌
 3. "." : 정밀도 (precision)


 ### 폭(width)
출력할 값의 최소 너비(폭) 지정

1. 출력할 값이 너비보다 작을 경우

자릿수를 맞추기 위해 공백 또는 0을 채워 넣는다.

2. 출력할 값이 지정한 너비보다 크면

값이 잘리면 안되기 때문에 width를 무시

만약 width에 음수가 할당 될 경우 -(플래그) + width로 본다.

%뒤에 나오는 10진수 숫자가 곧 지정한 폭이 된다.

    printf("[%060d]",323);

기본적으로 오른쪽 정렬 이므로 "60"은 60 - 3 만큼의 왼쪽 공백을 가진다

여기서 숫자앞의 "0"은 공백 대신 0으로 출력 해줌

### 정밀도(precision)

정밀도에 음수가 할당 될 경우 무시

 1. 문자열일 경우

 정밀도가 길이보다 길 경우 무시되지만

 길이보다 짧을경우 그만큼 문자열이 짤린다.

 2. %pdiuxX

 정밀도가 길이보다 길 경우 그만큼 0이 붙음

그게 아닌 경우 무시

- Manage all the following flags: ’# +’ (yes, one of them is a space)

1. "#" : %x, %X에 사용되면 출력되는 값 앞에 각각 0x, 0X를 붙인다 (x,X)
2. " " : -가 아닌 경우 한칸을 띄워서 출력 (d, i)
3. "+" : 출력결과가 양수(0 포함)인 경우 +를 붙인다 (d,i)

"+"에서 width가 주어질때, +가 같이 정렬 되지만 "0"플래그가 사용된 경우는 숫자만 정렬된다

참고로 +는 width 수에 포함되어 간격이 정해짐

"#", " "에서도 같음

## 태그 적용 순서

1. precision으로 먼저 갯수를 맞춘다음

2. width와 0을 제외한 나머지 태그들을 적용

3. -로 정렬을 확인하고 width만큼 칸을 맞춰줌

-가 존재한다면 width에 따른 빈칸이 오른쪽에 붙고 없다면 왼쪽에 붙는다

0태그는 width와 세트라고 생각 하고 처리 해줄것

## 공존 할 수 없는 플래그
flag ' ' is ignored when flag '+' is present

flag '0' is ignored when flag '-' is presen

    printf("{%050.30u}\n", 214748365)

다음과 같을때 0 태그가 적용되지 않음 

## %s에서

" ", "+", "0", "#" 태그는 올 수 없다.

즉 "-", width, precision에 대해서만 신경쓰자

## %c에서

"0", " ", "+", "#" 불가능

precision 또한 undefined

"-"와 "width만 사용 가능

## %p에서

"0", " ", "+", "#"

precision 또한 undefined

## %u에서

"+", " ", "#" 사용 불가

## %d,%i에서

"#" 사용 불가능

"0"태그와 "+", " "이 공존할 경우 width로 정해진 0은 부호(공백)과 숫자 사이에 붙음

## %x,%X에서

" ", "+" 사용 불가능

    printf("{%#011x}\n", 214748365)
{0x00ccccccd} 0은 0x와 출력값 사이에 붙는다.

0태그가 없으면 앞을 띄워줌