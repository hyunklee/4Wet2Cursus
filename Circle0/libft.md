# Libft
## Mandatory part
|||
|-|-|
| Program name | libft.a |
| Turn in files | *.c, libft.h, Makefile |
| Makefile | Yes |
| External functs. | Detailed below |
| Libft authorized | Non-applicable |
|||
## Technical considerations
- 전역변수 사용 금지
- 함수 간 충돌 방지를 위해 정적 함수(static)으로 정의 할 것
- repository에 있는 모든 파일 제출
- 사용되지 않는 파일 제출 금지
- 모든 c파일은 -Wall, -Wextra and -Werror flag를 사용하여 컴파일
- 라이브러리 생성을 위해 ar명령어 사용, libtool 사용 금지

## Libc functions

### ! notice !

Some of the functions’ prototypes you have to re-code use the
"restrict" qualifier. This keyword is part of the c99 standard.
It is therefore forbidden to include it in your prototypes and to
compile it with the flag -std=c99.

+ prototype에 restrict가 있다해도 쓰지말 것!



### 1. memset

	#include <string.h>

	void *memset(void *b, int c, size_t len);
#### DESCRIPTION
The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.

=>  <u>len bytes 만큼 value c를 string b에 넣는다.</u>
- void *b : 채우고자 하는 메모리의 시작 포인터 (dest)
- int c : unsigned char 로 변환 되어서 저장, 채우고자 하는 값
- size_t len : 채우고자 하는 메모리의 크기

#### RETURN VALUES
- 첫번째 인자 (void *b)

<strong>보통 어떤 작업을 하기 전에 NULL로 초기화 할 때 많이 사용 된다.</strong>

### 2. strrchr

	#include <string.h>

	char *strrchr(const char *s, int c);
### DESCRIPTION
 The strrchr() function is identical to strchr(), except it locates the last occurrence of c.

 => <u>찾을려고 하는 문자 int c를 char *s의 뒤에서 부터 찾는다. (strchr의 역순)</u>
 - char *s : 찾을 대상이 되는 문자열
 - int c : 찾을 문자

 #### RETURN VALUES
- 찾은 지점의 주소를 반환, 없을경우 NULL

### 3. bzero

	#include <strings.h>

	void bzero(void *s, size_t n);
### DESCRIPTION
 The bzero() function writes n zeroed bytes to the string s.  If n is zero, bzero() does nothing.

 => <u>n bytes만큼 *s를 0으로 채운다. 만약 n이 0일경우 아무것도 안함.</u>
 - void *s : 채우게 될 대상
 - size_t n : 채울 0의 갯수

### 4. strnstr

	#include <string.h>

	char *strnstr(const char *haystack, const char *needle, size_t len);
### DESCRIPTION
The strnstr() function locates the first occurrence of the null-terminated string needle in the string haystack, where not more than len charac-ters are searched.  Characters that appear after a `\0' character are not searched.  Since the strnstr() function is a FreeBSD specific API, it
should only be used when portability is not a concern.

 => <u>haystack 의 n 만큼 범위에서 needle을 찾는 함수.</u>

 !! len > strlen(haystack) 이라도 무관하다 !!
 - const char *haystack : 찾게 되는 문자열
 - const char *needle : 찾을 문자열
 - size_t len : haystack 에서 읽을 범위 (찾고싶은 만큼)

### RETURN VALUES

- 만약 needle이 빈 문자열일 경우 haystack의 첫번째 주소를 반환
- 못 찾을 경우 NULL을 반환
- 찾을경우 needle의 첫번째 문자에 해당하는 haystack의 주소를 반환

### 5. memmove

	#include <string.h>

	void *memmove(void *dst, const void *src, size_t len);
### DESCRIPTION
 The memmove() function copies len bytes from string src to string dst.  The two strings may overlap; the copy is always done in a non-destruc-
     tive manner.

 => <u>src를 len만큼 복사 후 dst에 삽입 cpy와 다르게 dst와 src는 같은 배열일 수 있음 보다 안정적이지만 느림</u>
 - void *dst : 붙여넣을 대상
 - const void *src: 복사 될 배열의 주소
 - size_t len : 복사할 만큼의 bytes

### RETURN VALUES
- original value of dst
### 6. memcpy

	#include <string.h>

	void *memcpy(void *restrict dst, const void *restrict src, size_t n);
### DESCRIPTION
 The memcpy() function copies n bytes from memory area src to memory area dst.  If dst and src overlap, behavior is undefined.  Applications in
     which dst and src might overlap should use memmove(3) instead.

 => <u>src를 n만큼 복사 후 dst에 삽입. overlap에 대한 정의가 이뤄지지 않음.</u>
 - void *restrict dst : 채우게 될 대상
 - const void *restrict src : 복사 될 배열의 주소
 - size_t n : 복사할 만큼의 bytes
### RETURN VALUES
- original value of dst

### 7. strdup
	#include <string.h>
	char *strdup(const char *s1);


### DESCRIPTION
 The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may sub-
 sequently be used as an argument to the function free(3).

 => <u>문자열 길이 + 1 만큼 동적 할당 한 후 s1을 복사하고 반환한다.</u>
- const char *s1 : 복사 될 문자열
### RETURN VALUES
- 복사 한 문자열
### 8. memchr
    #include <string.h>

    void *memchr(const void *s, int c, size_t n);
### DESCRIPTION
The memchr() function locates the first occurrence of c (converted to an unsigned char) in string s.

 => <u>s에서 n bytes 만큼 c를찾는 함수. c는 int형 이지만 1byte씩 보기 위해 unsigned char로 변환되어짐.</u>
 - const void *s : 검색을 수행할 부분의 시작 주소
 - int c : 찾을 값
 - size_t n : 찾을 범위
 ### RETURN VALUES
 - s에서 c와 처음으로 일치하는 곳의 주소를 반환
 - n bytes 이내에 찾지 못한다면 NULL반환

### 9. memcmp
    #include <string.h>

    int memcmp(const void *s1, const void *s2, size_t n);
### DESCRIPTION
The memcmp() function compares byte string s1 against byte string s2.  Both strings are assumed to be n bytes long.

<u>s1과 s2를 비교함. 반환값이 0이 아닐경우 unsigned char를 이용하여 차이값을 반환.</u>

- const void *s1 : 메모리 블록을 가리키는 포인터
- const void *s2 : 메모리 블록을 가리키는 포인터
- size_t n : 비교할 byte 수

### RETURN VALUES
- 두 스트링의 원소들이 일치 할 경우 0을 반환
- 같지 않을경우 다른 값이 들어 있는 바이트에서의 차이값을 반환.

### 10. strlcpy
	#include <string.h>
	size_t strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
### DESCRIPTION
strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0.

<u>src를 dst에 dstsize - 1 만큼 복사를 해준다 dstsize번째에는 NULL이 들어감.</u>
- char * restrict dst : 복사 될 string.
- const char * restrict src : dst에 들어갈 string.
- size_t dstsize : dst에 넣을 src의 범위
### RETURN VALUES
- src의 길이 값

### 11. strlcat
 	#include <string.h>
 	size_t strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
### DESCRIPTION
appends string src to the end of dst.  It will append at most dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate,
unless dstsize is 0 or the original dst string was longer than dstsize (in practice this should not happen as it means that either dstsize is
incorrect or that dst is not a proper string).

=> <u>dst 끝에 src를 dstsize - strlen(dst) -  1 만큼 추가한다. 하나는 NULL 자리</u>
- char * restrict dst : 붙여 넣을 공간.
- const char * restrict src : dst에 들어갈 string.
- size_t dstsize : dst에 붙일 src의 길이 NULL도 포함.
### RETURN VALUES
만약 dstsize > strlen(dst)일 경우 strlen(src) + strlen(dst),
반대일 경우 dstsize + strlen(src)을 반환

### 12.strchr
	#include <string.h>
 	char *strchr(const char *s, int c)

### DESCRIPTION
The strchr() function locates the first occurrence of c (converted to a char) in the string pointed to by s.  The terminating null character is
considered to be part of the string; therefore if c is '\0', the functions locate the terminating `\0'.

=> <u>c는 char로 형변환이 된 상태에서 s에서 첫번째로 나타나는 위치를 찾는다. c가 \0일 경우 스트링의 끝을 가르킨다.</u>
- const char *s : 찾고자 하는 곳
- int c : 찾을 값
### RETURN VALUES
찾은 지점의 주소를 반환, 없을경우 NULL

### 13.atoi
	#include <stdlib.h>
	int atoi(const char *str);

### DESCRIPTION
The atoi() function converts the initial portion of the string pointed to by str to int representation.

=> <u>atoi는 str을 int형으로 반환하는 함수다.</u>

- const char *str : 반환할 문자열

### 14.calloc
	#include <stdlib.h>
	void *calloc(size_t count, size_t size);

### DESCRIPTION
The calloc() function contiguously allocates enough space for count objects that are size bytes of memory each and returns a pointer to the allocated memory. The allocated memory is filled with bytes of value zero.

=> <u>각각 메모리의 크기 바이트인 count 객체에 대해 충분한 공간을 연속적으로 할당하고 0byte 값으로 채움, 할당된 메모리에 대한 포인터를 반환</u>

- size_t count : 할당할 변수의 갯수
- size_t size : 할당할 변수 하나의 크기
### RETURN VALUES
할당된 메모리에 대한 포인터를 반환, 실패할 경우 NULL포인터를 반환한다.

### 15.memccpy
	#include <string.h>
	void *memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
### DESCRIPTION
The memccpy() function copies bytes from string src to string dst. If the character c (as converted to an
unsigned char) occurs in the string src, the copy stops and a pointer to the byte after the copy of c in the string dst is returned.  Otherwise, n bytes are copied, and a NULL pointer is returned. The source and destination strings should not overlap, as the behavior is undefined.

=> <u>src를 n바이트 만큼 dest에 복제하는데, src에서 c를 만나면 c까지 복제하고 중단. 복제된 dest변수에서 복제가 끝난 다음 번지를 반환. 만약 문자 c를 만나지 않았다면, n바이트를 복제하고 NULL을 반환</u>

- void *restrict dst : 복제가 되는 destination 변수
- const void *restrict src : 복제할 원본 데이터
- int c : src에서 만나면 중단할 값
- size_t n : 복제할 데이터의 byte수

### RETURN VALUES

Dest에 복제가 끝난 데이터의 다음 메모리 주소 (추가 복제를 쉽게 하기 위함)

c를 만나지 못할 경우 NULL 반환

### 16.substr
	char *ft_substr(char const *s, unsigned int start, size_t len);
### DESCRIPTION
Allocates (with malloc(3)) and returns a substring
from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.

=> <u>메모리를 할당한 후 s의 index 'start'부터 len까지의 문자열을 저장한 다음 반환.</u>

- char const *s : 반환값의 대상이 되는 문자열
- unsigned int start : 반환 문자열의 시작 지점 (s에서)
- size_t len : 반환 문자열의 길이

### RETURN VALUES
할당이 실패할 경우 NULL반환

start >= strlen(s) 일경우 빈 문자열 반환

그외 start부터 len만큼의 s를 반환한다.

### 17. strtrim
	char *ft_strtrim(char const *s1, char const *set);
### DESCRIPTION
Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.

=> <u>메모리를 할당한 후 s의 시작 지점과 끝 지점에서 set에 해당하는 문자들을 자르고 반환. </u>

- char const *s1 : 원본
- char const *set : s1에서 절단할 문자들

### RETURN VALUES
할당이 실패 할 경우 NULL 반환

그외 set에 의해 절단된 s1을 반환한다

### 18. ft_strmapi
	char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
### Description
Applies the function ’f’ to each character of the string ’s’ to create a new string (with malloc(3)) resulting from successive applications of ’f’.

=> <u>문자열 's'의 각 문자에 'f'함수를 연속적으로 적용시킨 새로운 문자열을 만듬. 새로운 문자열은 malloc(3)을 할당. </u>

- char const *s : 반복할 문자열
- char (*f)(unsigned int, char) : 각 문자에 적용할 함수

### RETURN VALUES
'f'함수를 연속적으로 적용시킨 문자열. 할당 실패시 NULL.


## BONUS PART
오 여기까지 오다니..

!!구조체를 libft.h에 추가!!

	typedef struct 	s_list
	{
	void 			*content;
	struct s_list 	*next;
	} 				t_list;
- content :  요소에 포함된 데이터. void 포인터는 어떠한 종류의 자료형이든 저장 가능
of data.
- next : 마지막 요소인 경우에는 NULL. 또는 다음 요소의 주소.

Makefile 안에 bonus를 만들것 (bonus functions만 사용)

### 1.ft_lstnew

	t_list	*ft_lstnew(void *content);
### DESCRIPTION
Allocates (with malloc(3)) and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.

=> <u>인자로 받는 content 값으로 초기화, 'next'는 NULL로 초기화 된다. </u>

- void *content : 새로 추가할 list의 content;

### RETURN VALUES
새로 만든 list

### 2. ft_lstadd_front

	t_list	void ft_lstadd_front(t_list **lst, t_list *new)
### DESCRIPTION
Adds the element ’new’ at the beginning of the list.

=> <u> list의 시작부분에 new list를 추가</u>

- t_list **lst : 첫 번째 링크 리스트의 포인터 주소
- t_list *new : list에 추가 될 new list의 주소

### 8. ft_lstmap

	t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
### DESCRIPTION
Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.

=> <u> 리스트 'lst'를 반복하여 각 요소의 content에 함수 'f'를 적용. 함수 'f'를 연속적으로 적용시켜 새로운 리스트를 만듬. 필요한 경우 함수 'del'은 요소의 content를 삭제하는데 사용됨 </u>

- t_list *lst : 요소의 포인터 주소

- void *(*f)(void *) : 리스트에 반복적으로 사용되는 함수의 주소

- void (*del)(void *) : 필요한 경우 요소의 content를 삭제하기위해사용되는 함수의 주소

### RETURN VALUES
새로운 리스트. 할당 실패시 NULL
