#include "student.h"
int main() {
	char flag;
	
	do {
	welcome();
	direct_search();
	printf("按任意键返回主界面，按#退出系统。");
	scanf(" %c",&flag);
	} while (flag!='#');
	
	return 0;
}