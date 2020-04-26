#include "eating.h"


T_info** eating;
int _count = 0; //저장돼있는 식당의 개수
int _totalMemory = 50; //총 메모리 공간

void m_allocation(){
    eating = calloc(50, sizeof(T_info*));
    for (int i=0; i<50 ; i++){
    	eating[i]= (T_info*)calloc(1, sizeof(T_info));
    }
}
int m_is_available(){ //현재 추가할 수 있는 데이터 공간 확인
    //int i;
    /*for(i=0 ; i<MAX_RESTAURANT ; i++){
        if(eating[i]==NULL) return 1;
    }*/
    if (_totalMemory>_count)
	return 1;
    else
	return 0;
}
void m_increase(){
    eating = realloc(eating, 10*sizeof(T_info*));
    _totalMemory = _totalMemory + 10;
}
int m_count(){ // 현재 저장된 회원 레코드 갯수 가져오기
    return _count;
}
void m_create(char* name, char* mf, char* tp, char* ad, char del){ // 식당정보로 신규정보 등록
    eating[_count] = (T_info*)malloc(sizeof(T_info));
    T_info* p = eating[_count];
    strcpy(p->name, name);
    strcpy(p->main_food, mf);
    strcpy(p->telephone, tp);
    strcpy(p->address, ad);
    p->delivery = del;
    _count++;
}
T_info* m_return_info_location(int n){ // 번호 입력받고, 해당 인덱스의 주소값 반환
    return eating[n-1];
}
void print_Name(){ // 모든 식당이름 출력
    int i;
    for (i=0 ; i<_count ; i++){
        printf("%d. %s", i+1, eating[i]->name);
    }
}
void m_update(T_info* p, char* name, char* mf, char* tp, char* ad, char del){ // 새로 받은 정보로 업데이트
    strcpy(p->name, name);
    strcpy(p->main_food, mf);
    strcpy(p->telephone, tp);
    strcpy(p->address, ad);
    p->delivery = del;
}
void m_delete(T_info* p){ // 특정 식당정보 삭제
    int i, index;
    for(i=0; i<_count; i++)
        if(eating[i]==p) {
            index=i;
            break;
        }
    free(eating[index]);
    _count--;

    for(i=index ; eating[i]!=0x0 ; i++)
    {
        if(eating[i+1]==0x0){
            free(eating[i]);
            break;
        }
        eating[i] = eating[i+1];
    }
}

char* m_getName(T_info* p){
    return p->name;
}
char* m_getMain(T_info* p){
    return p->main_food;
}
char* m_getTele(T_info* p){
    return p->telephone;
}
char* m_getAddress(T_info* p){
    return p->address;
}
char m_getDelivery(T_info* p){
    return p->delivery;
}
int m_get_about_menu(T_info* p[], char * menu){
    // 검색한 menu와 같은 menu를 가지고 있는 구조체를 찾아서 p가 가리키게 하는 함수
    int i, count=0;
    int range=m_count();
    for (i=0 ; i<range ;i++){
        if(strstr(eating[i]->main_food, menu)){
            p[count] = eating[i];
            count++;
        }
    }
    return count;
}
int m_check_delivery(T_info* p[]){
    int i, count=0;
    int range=m_count();
    for (i=0 ; i<range ;i++){
        if(eating[i]!=NULL && (eating[i]->delivery == 'y')){
            p[count] = eating[i];
            count++;
        }
    }
    return count;
}
char* m_to_string(T_info* p){
    static char str[100];
    sprintf(str, "%s | %s | %s | %s | %c", p->name, p->main_food, p->telephone, p->address, p->delivery);
    return str;
}
char* m_to_string_save(T_info* p){
    static char str[100];
    sprintf(str, "%s%s%s%s%c", p->name,  p->main_food, p->telephone, p->address, p->delivery);
    return str;
}
