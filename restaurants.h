#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//식당정보를 구조체로 묶어 새로운 타입을 정의함.
typedef struct st_info{
	char name[25];
	char main_food[30];
	char telephone[15];
	char address[30];
	char delivery;
} T_info;

int m_is_available();
int find_same_name(char* Name);
void m_create(char* nm,char* mf, char*tp, char*ad, char del);
void increase_memory_count();
int return_info_count();
char* get_name(int s);
char* get_mainfood(int s);
char* get_phone(int s);
char* get_address(int s);
char get_delivery(int s);
