#include "restaurants.h"

int info_count = 0; //현재 추가되어 있는 식당의 수
int memory_count = 30; //현재 만들어져 있는 메모리 개수
T_info* place[30];

int m_is_available(){
	int i;
	for(i=0 ; i<memory_count ; i++){
		if(place[i]==NULL) return 1;
	}
	return 0;
}

int  find_same_name(char *Name){
	int i;
	for(i=0 ; i<info_count ; i++){
		T_info* p = place[i];
		if(strcmp(p->name, Name)==0) return 1;
	}
	return 0;
}

void m_create(char* nm, char* mf, char* tp, char* ad, char del)
{
	T_info* p = place[info_count+1];
	strcpy(p->name, nm);
	strcpy(p->main_food, mf);
	strcpy(p->telephone, tp);
	strcpy(p->address, ad);
	p->delivery = del;
	info_count++;
} 

void increase_memory_count()//메모리 공간 증가시켜주기
{
	memory_count = memory_count + 10;
}

int return_info_count()//저장돼있는 식당 수 리턴해주기
{
	return info_count;
}

char* get_name(int s)
{
	return place[s]->name;
}

char* get_mainfood(int s)
{
	return place[s]->main_food;
}

char* get_phone(int s)
{
	return place[s]->telephone;
}

char* get_address(int s)
{
	return place[s]->address;
}

char get_delivery(int s)
{
	return place[s]->delivery;
}
