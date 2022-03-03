#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

FILE* fp = NULL;
char class[10];
typedef struct stu
{
	char name[5];
	int Chinese_grade;
	int Math_grade;
	struct stu *nextp;
}STU;      //学生类

void welcome() {
	system("cls");
	printf("\t\t\t\t\t\t——————————————\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t|   欢迎使用学生管理系统    |\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t——————————————\n");
}
//欢迎界面
void direct_search() {
	int a;
	printf("\t\t\t\t\t\t      1、已有班级          \n");
	printf("\t\t\t\t\t\t      2、新建班级          \n");
	printf("\t\t\t\t\t\t      3、删除班级          \n");
	printf("请选择：");
	scanf("%d", &a);
	system("cls");      //清屏
	void exist_class(); 
	void new_class();
	void delete_class();	/*函数体在后面,声明函数。*/
	switch (a) {
	case 1:exist_class(); break;
	case 2:new_class(); break;
	case 3:delete_class(); break;

	}

}
//主选择界面
void exist_class() {
	int a;
	char flag;
	printf("请输入班级：");
	scanf("%s", &class);
	if ((fp = fopen(class, "r")) == NULL)
	{
		printf("\t\t\t\t\t\t没有该班级的信息\n");
		return;

	}

	else {
		
		do {
			system("cls");
			printf("\t\t\t\t\t\t——————————————————\n");
			printf("\t\t\t\t\t\t|        1、查看所有学生信息       |\n");
			printf("\t\t\t\t\t\t|        2、增加学生信息           |\n");
			printf("\t\t\t\t\t\t|        3、删除学生信息           |\n");
			printf("\t\t\t\t\t\t|        4、修改学生信息           |\n");
			printf("\t\t\t\t\t\t|        5、查询学生信息           |\n");
			printf("\t\t\t\t\t\t——————————————————\n");

			printf("\t\t\t\t\t\t请选择：");
			scanf("%d", &a);
			void look_through();
			void append_student();
			void delete_student(); 
			void update_student();  //声明函数
			switch (a) {
			case 1:look_through(); break;
			case 2:append_student(); break;
			case 3:delete_student(); break;
			case 4:update_student(); break;
			case 5:break;
			default:break;
			}
			printf("按任意键返回班级操作，按#退出班级操作。");
			scanf(" %c", &flag);
		} while (flag != '#');


	}
}
//已有班级函数，包括了新界面和调用对应功能函数。
void new_class() {
	char name[10];
	int Chinese_grade;
	int Math_grade;
	char flag;
	printf("请输入班级名称：");
	scanf("%s", class);
	system("cls");
	FILE* fp = fopen(class, "w");
	do {
		printf("%s班\n请输入学生姓名：",class);
		scanf("%s", name);
		system("cls");
		printf("%s班\n请输入语文成绩：",class); 
		scanf(" %d", &Chinese_grade);
		system("cls");
		printf("%s班\n请输入数学成绩:",class);
		scanf(" %d", & Math_grade);
		fprintf(fp,"%s   %d   %d\n",name,Chinese_grade,Math_grade);
		system("cls");
		printf("输入任意键继续录入学生信息，输入#结束录入学生信息\n");
		scanf(" %c", &flag);
	} while (flag != '#');
	fclose(fp);
	
}
//新建班级函数
void look_through() {
	system("cls");
	int flag;
	char name[10];
	int Chinese_grade, Math_grade;
	fp = fopen(class, "r");
	printf("姓名  语文成绩  数学成绩\n");
	do {
		flag=fscanf(fp, "%s  %d  %d", name, &Chinese_grade, &Math_grade);
		if(flag==3)
		printf("%s  %d        %d\n", name, Chinese_grade, Math_grade);
	} while (flag == 3);
	fclose(fp);
}
//查看所有学生信息
void append_student() {
	char name[10];
	int Chinese_grade;
	int Math_grade;
	char flag;
	system("cls");
	fp = fopen(class, "a");
	do {
		printf("%s班\n请输入学生姓名：", class);
		scanf("%s", name);
		system("cls");
		printf("%s班\n请输入语文成绩：", class);
		scanf(" %d", &Chinese_grade);
		system("cls");
		printf("%s班\n请输入数学成绩:", class);
		scanf(" %d", &Math_grade);
		fprintf(fp, "%s   %d   %d\n", name, Chinese_grade, Math_grade);
		system("cls");
		printf("输入任意键继续录入学生信息，输入#结束录入学生信息\n");
		scanf(" %c", &flag);
	} while (flag != '#');
	fclose(fp);
}
//增加学生信息
void delete_student() {
	char name[10];
	int flag = 3;
	int flag_arry_count=0;
	int stu_list_count = 0;
	STU* student_link_list = malloc(sizeof(STU) * 50);//一个学生类的数组，用于暂时存放学生信息，存放数量少于50个。
	fp = fopen(class, "r");
	system("cls");
	printf("请输入要删除的学生的名字：\n");
	scanf("%s", name);
	for (stu_list_count; flag == 3; stu_list_count++) {
		flag = fscanf(fp, "%s  %d  %d", student_link_list[stu_list_count].name, &student_link_list[stu_list_count].Chinese_grade, &student_link_list[stu_list_count].Math_grade);
		if (!(strcmp(student_link_list[stu_list_count].name,name)))
			flag_arry_count = stu_list_count;
	}//将已存在班级中的学生信息读入学生类数组。
	int count = stu_list_count-1;//count用来控制下面的do{}while循环结束、
	stu_list_count = 0;

	fclose(fp);
	remove(class);//删除原来的班级文件
	fp = fopen(class, "w");
	do {
		if (stu_list_count == flag_arry_count)
			stu_list_count++;
		fprintf(fp, "%s   %d   %d\n", student_link_list[stu_list_count].name, student_link_list[stu_list_count].Chinese_grade, student_link_list[stu_list_count
		].Math_grade);
		stu_list_count++;
	} while (count > stu_list_count);//把除了要删除的学生的信息，都输入到同名新文件夹中。
	free(student_link_list);//释放学生数组。
	fclose(fp);

}
//删除学生信息
void update_student() {
	int Chinese_grade;
	int Math_grade;
	char name[10];
	int flag = 3;
	int flag_arry_count = 0;
	int stu_list_count = 0;
	STU* student_link_list = malloc(sizeof(STU) * 50);//一个学生类的数组，用于暂时存放学生信息，存放数量少于50个。
	fp = fopen(class, "r");
	system("cls");
	printf("请输入要更新的学生的名字：");
	scanf("%s", name);
	for (stu_list_count; flag == 3; stu_list_count++) {
		flag = fscanf(fp, "%s  %d  %d", student_link_list[stu_list_count].name, &student_link_list[stu_list_count].Chinese_grade, &student_link_list[stu_list_count].Math_grade);
		if (!(strcmp(student_link_list[stu_list_count].name, name)))
			flag_arry_count = stu_list_count;
	}//将已存在班级中的学生信息读入学生类数组。
	int count = stu_list_count - 2;//count用来控制下面的do{}while循环结束、
	stu_list_count = 0;

	fclose(fp);
	remove(class);//删除原来的班级文件
	fp = fopen(class, "w");
	do {
		if (stu_list_count == flag_arry_count)
			stu_list_count++;
		fprintf(fp, "%s   %d   %d\n", student_link_list[stu_list_count].name, student_link_list[stu_list_count].Chinese_grade, student_link_list[stu_list_count
		].Math_grade);
		stu_list_count++;
	} while (count > stu_list_count);//把除了要删除的学生的信息，都输入到同名新文件夹中。
	free(student_link_list);//释放学生数组。
	
	
	printf("%s班\n请输入语文成绩：", class);
	scanf(" %d", &Chinese_grade);
	system("cls");
	printf("%s班\n请输入数学成绩:", class);
	scanf(" %d", &Math_grade);
	fprintf(fp, "%s   %d   %d\n", name, Chinese_grade, Math_grade);
    fclose(fp);
}
//更新学生信息
void delete_class() {
	printf("请输入要删除的班级名字：");
	scanf("%s", class);
	remove(class);
}
//删除班级