#include "eating.h"
#include <stdio.h>

//애플리케이션용 함수 원형
void create_info();
void read_info();
void update_info();
void delete_info();
void read_one_record();
void search_menu();
void search_delivery();
void load_file();
void save_file();
void call_dibs();
void read_dibs();


int main(){
    int menu=0;
    m_allocation();
    dibs_allocation();
    while(1){
        printf("\nChoose number : 1.Create  2.Read list  3.Update  4.Delete  5.Read one  6.Search(menu)  7.Search(delivery)  8.Load file  9.Save file  10.add dibs  11.dibs list  0.Quit > ");
        scanf("%d", &menu);
        printf("\n");
        switch(menu){
            case 1:
                create_info();
                break;
            case 2:
                read_info();
                break;
            case 3:
                update_info();
                break;
            case 4:
                delete_info();
                break;
            case 5:
                read_one_record();
                break;
            case 6:
                search_menu();
                break;
            case 7:
                search_delivery();
                break;
            case 8:
                load_file();
                break;
            case 9:
                save_file();
                break;
            case 10:
                call_dibs();
                break;
            case 11:
                read_dibs();    
                break;
            case 0:
            default:
                return 0;
        }
    }
    return 0;
}

void create_info(){
    if(!m_is_available()){
        m_increase();
    }
    char name[30], mf[30], tp[20], ad[40], del;
    char c;
    printf("Enter a new restaurant's info.\n");
    printf("Name > ");
    scanf("%c", &c);
    fgets(name,30,stdin);
    printf("Main menu > ");
    fgets(mf,30,stdin);
    printf("Telephone > ");
    fgets(tp,20,stdin);
    printf("Address > ");
    fgets(ad,40,stdin);
    printf("Delivery(enter y or n) > ");
    scanf("%c", &del);
    m_create(name, mf, tp, ad, del);
}
void read_info(){
    int i, range=m_count();
    for (i=0 ; i<range ; i++){
        T_info* p = m_return_info_location(i+1);
        printf("%d. %s\n", i+1, m_to_string(p));
    }
}
void update_info(){
    int num, range=m_count();
    print_Name();
    printf("Choose one number > ");
    scanf("%d", &num);
    while(num<1 || range<num){
        printf("Wrong range. Enter again > ");
        scanf("%d", &num);
    }

    T_info* p = m_return_info_location(num);
    printf("This is original info.\n%s\n",m_to_string(p));
    char name[30], mf[30], tp[20], ad[40], del;
    char c;
    printf("\nEnter a new restaurant's info.\n");
    printf("Name > ");
    scanf("%c", &c);
    fgets(name,30,stdin);
    printf("Main menu > ");
    fgets(mf,30,stdin);
    printf("Telephone > ");
    fgets(tp,20,stdin);
    printf("Address > ");
    fgets(ad,40,stdin);
    printf("Delivery(enter y or n) > ");
    scanf("%c", &del);

    m_update(p, name, mf, tp, ad, del);
}
void delete_info(){
    int num, range=m_count();
    print_Name();
    printf("Choose one number > ");
    scanf("%d", &num);
    while(num<1 || range<num){
        printf("Wrong range. Enter again > ");
        scanf("%d", &num);
    }
    T_info* p = m_return_info_location(num);
    m_delete(p);
}
void read_one_record(){
    int num, range=m_count();
    print_Name();
    printf("Choose one number > ");
    scanf("%d", &num);
    while(num<1 || range<num){
        printf("Wrong range. Enter again > ");
        scanf("%d", &num);
    }
    T_info* p = m_return_info_location(num);
    printf("%s\'s info.\n", m_getName(p));
    printf("Main menu : %s", m_getMain(p));
    printf("Telephone : %s", m_getTele(p));
    printf("address : %s", m_getAddress(p));
    printf("delivery : %c\n", m_getDelivery(p));
}
void search_menu(){
    char menu[30], c;
    printf("Enter a menu you want > ");
    scanf("%c", &c);
    fgets(menu,30,stdin);

    int range=m_count();
    T_info* menuArray[range];
    int size = m_get_about_menu(menuArray, menu);

    if (size==0){
        printf("There is no matched info\n");
        return;
    }
        printf("This is the restaurant list which sells %s",menu);
        for(int i=0 ; i<size ; i++){
            T_info* p = menuArray[i];
            char str[50];
            sprintf(str,"%s > %s", p->name, p->telephone);
            printf("%s", str);
        }
}
void search_delivery(){
    int range=m_count();
    T_info* deliveryArray[range];
    int size = m_check_delivery(deliveryArray);

    if (size==0){
        printf("There is no restaurant having delivery service\n");
        return;
    }

    printf("This is the restaurant list which has delivery service\n");
    for(int i=0 ; i<size ; i++){
        T_info* p = deliveryArray[i];
        char str[60];
        sprintf(str, "%s > %s", m_getName(p), m_getMain(p));
        printf("%s",str);
    }
}

void load_file(){
    FILE* f = fopen("info.txt", "r");
    
    char name[30], mf[30], tp[20], ad[40], del;
    while (feof(f) == 0)
    {
        if(!m_is_available()){
        m_increase();
        }
        fgets(name, sizeof(name)+sizeof(char), f);
        fgets(mf, sizeof(mf)+sizeof(char), f);
        fgets(tp, sizeof(tp)+sizeof(char), f);
        fgets(ad, sizeof(ad)+sizeof(char), f);
        del = fgetc(f);
        m_create(name, mf, tp, ad, del);
	del = fgetc(f);
    }
    fclose(f);
}
void save_file(){
    FILE* f = fopen("info.txt", "a");
    int range = m_count();
    for (int i=0 ; i<range ; i++){
        T_info* p = m_return_info_location(i+1);
        fprintf(f, "\n%s", m_to_string_save(p));
    }
    fclose(f);
}
void call_dibs(){ //찜하기 : 식당 리스트 출력 후 번호를 입력받아 해당 식당이름을 따로 dips어레이에 저장
    int num, range=m_count();
    print_Name();
    printf("Choose one number you like > ");
    scanf("%d", &num);
    while(num<1 || range<num){
        printf("Wrong range. Enter again > ");
        scanf("%d", &num);
    }
    T_info* p = m_return_info_location(num);
    if(check_same_name(p)==0){ //이미 추가한 항목이라면 inform 주고 return하기.
        printf("You've already added this restaurant!");
        return;
    }
    if(!dibs_is_available()){ //dibs 공간 부족하면 늘려주기
        dibs_increase();
    }
    dibs_create(p);
}
void read_dibs(){
    int range = return_dibs_count();
    for(int i=0 ; i<range ; i++){
        printf("%d. %s ",i+1,return_dibs_location(i));
    }
}
