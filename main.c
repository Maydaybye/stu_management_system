#include "student.h"
int main() {
	char flag;
	
	do {
	welcome();
	direct_search();
	printf("����������������棬��#�˳�ϵͳ��");
	scanf(" %c",&flag);
	} while (flag!='#');
	
	return 0;
}