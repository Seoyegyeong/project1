#include "restaurants.h"

void create_record();
void read_record();
void read_one_record();

int main(){
	int menu;
	while(1){
	printf("\nMenu : 1.Create 2.Read all 3.Read one : ");
	scanf("%d",&menu);
	printf("\n");
	switch(menu){
	case 1:
		create_record();
		break;
	case 2:
		read_record();
		break;
	case 3:
		read_one_record();
		break;
	case 0:
	default:
		return 0;	
	}
	}
	return 0;
}

void create_record(){
	if(m_is_available()==0) {printf("There is no more space.\n");}
// realloc 해서 공간 추가 increase_memory_count(); } //공간 추가하면 memory_count 숫자도 증가시켜주기! memory_count 를 바로 증가시키지 말고 증가시키는 간단한 함수 추가해!
	char name[30], main_food[30], telephone[20], address[30];
	char delivery, YN; //YN은 Y/N를 저장하기 위한 변수
	printf("Enter a new restaurant information!\n");
	printf("Restaurant name > ");
	scanf("%s", name);
	if(find_same_name(name)== 1) { printf("There is same name. Are you sure about creating new information? Put \'Y\' or \'N\' "); scanf("%c", &YN); }
	if(YN == 'N') return; //대문자 N이 아닌 다른 것을 입력했다면 그냥 진행하도록 함.
	printf("Main menu > ");
	scanf("%s", main_food);
	printf("Telephone num > ");
	scanf("%s", telephone);
	printf("Adress > ");
	scanf("%s", address);
	printf("Delivery(If it have delivery service put \'Y\' and if not, put \'N\') > ");
	scanf("%c", &delivery);
	m_create(name, main_food, telephone, address, delivery);
}

void read_record(){
	int i;
	int info_count= return_info_count();
	for(i=0 ; i<info_count ; i++)
	{
		printf("%d. Restaurant name : %s, Main menu : %s\n", i+1, get_name(i), get_mainfood(i));		
	}
}

void read_one_record()
{
	int i;
	int info_count= return_info_count();
	for(i=0 ; i<info_count ; i++)
	{
		printf("%d. %s, ",i+1,get_name(i));
	}
	printf("\nPick one restaurant and put the number : ");
	scanf("%d",&i); //다 쓴 i 재활용하기.
	while(i<1 || i>info_count)
	{
		printf("Out of range. Please put a number again. ");
		scanf("%d",&i);
	}
	printf("This is \"%s\" information.\n", get_name(i-1));
	printf("Main menu : %s\n",get_mainfood(i-1));
	printf("Tel : %s\n",get_phone(i-1));
	printf("Address : %s\n",get_address(i-1));
	printf("Delivery service : %c\n",get_delivery(i-1));
}
