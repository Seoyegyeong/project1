#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 식당 기본정보의 데이터 타입을 정의함
typedef struct st_info{
    char name[30]; //식당이름
    char main_food[30]; //대표메뉴
    char telephone[20]; //전화번호
    char address[40]; //주소
    char delivery; //배달가능여부
} T_info;

// 라이브러리 함수 원형을 선언함
void m_allocation(); //처음 시작할 때 정보저장할 메모리 공간 할당해줌
int m_is_available(); //현재 추가할 수 있는 데이터 공간 확인
void m_increase(); //메모리 공간 늘려줌
int m_count(); // 현재 저장된 회원 레코드 갯수 가져오기
void m_create(char* name, char* mf, char* tp, char* ad, char del); // 식당정보로 신규정보 등록
T_info* m_return_info_location(int n); // 번호 입력받고, 해당 인덱스의 주소값 반환
void print_Name(); // 모든 식당이름 출력
void m_update(T_info* p, char* name, char* mf, char* tp, char* ad, char del); // 새로 받은 정보로 업데이트
void m_delete(T_info* p); // 특정 식당정보 삭제
char* m_getName(T_info* p);   // 특정 식당의 이름 가져오기
char* m_getMain(T_info* p);   // 특정 식당의 대표메뉴 가져오기
char* m_getTele(T_info* p);   // 특정 식당의 전화번호 가져오기
char* m_getAddress(T_info* p);   // 특정 식당의 주소 가져오기
char m_getDelivery(T_info* p);   // 특정 식당의 배달가능여부 가져오기
int m_get_about_menu(T_info* p[], char * menu); 
int m_check_delivery(T_info* p[]);
char* m_to_string(T_info* p);  // 특정 식당의 정보를 문자열로 만들어주기
char* m_to_string_save(T_info* p);  // 특정 식당정보를 문자열로 만들어주는데 save file 때만 사용

//dibs(찜 목록)에 대해.
void dibs_allocation(); //찜한 항목 저장할 공간 생성해주기
int dibs_is_available();
void dibs_increase();
void dibs_create(T_info* p);
int return_dibs_count();
char* return_dibs_location(int n);
int check_same_name(T_info* p);
