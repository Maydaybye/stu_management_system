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
}STU;      //ѧ����

void welcome() {
	system("cls");
	printf("\t\t\t\t\t\t����������������������������\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t|   ��ӭʹ��ѧ������ϵͳ    |\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t����������������������������\n");
}
//��ӭ����
void direct_search() {
	int a;
	printf("\t\t\t\t\t\t      1�����а༶          \n");
	printf("\t\t\t\t\t\t      2���½��༶          \n");
	printf("\t\t\t\t\t\t      3��ɾ���༶          \n");
	printf("��ѡ��");
	scanf("%d", &a);
	system("cls");      //����
	void exist_class(); 
	void new_class();
	void delete_class();	/*�������ں���,����������*/
	switch (a) {
	case 1:exist_class(); break;
	case 2:new_class(); break;
	case 3:delete_class(); break;

	}

}
//��ѡ�����
void exist_class() {
	int a;
	char flag;
	printf("������༶��");
	scanf("%s", &class);
	if ((fp = fopen(class, "r")) == NULL)
	{
		printf("\t\t\t\t\t\tû�иð༶����Ϣ\n");
		return;

	}

	else {
		
		do {
			system("cls");
			printf("\t\t\t\t\t\t������������������������������������\n");
			printf("\t\t\t\t\t\t|        1���鿴����ѧ����Ϣ       |\n");
			printf("\t\t\t\t\t\t|        2������ѧ����Ϣ           |\n");
			printf("\t\t\t\t\t\t|        3��ɾ��ѧ����Ϣ           |\n");
			printf("\t\t\t\t\t\t|        4���޸�ѧ����Ϣ           |\n");
			printf("\t\t\t\t\t\t|        5����ѯѧ����Ϣ           |\n");
			printf("\t\t\t\t\t\t������������������������������������\n");

			printf("\t\t\t\t\t\t��ѡ��");
			scanf("%d", &a);
			void look_through();
			void append_student();
			void delete_student(); 
			void update_student();  //��������
			switch (a) {
			case 1:look_through(); break;
			case 2:append_student(); break;
			case 3:delete_student(); break;
			case 4:update_student(); break;
			case 5:break;
			default:break;
			}
			printf("����������ذ༶��������#�˳��༶������");
			scanf(" %c", &flag);
		} while (flag != '#');


	}
}
//���а༶�������������½���͵��ö�Ӧ���ܺ�����
void new_class() {
	char name[10];
	int Chinese_grade;
	int Math_grade;
	char flag;
	printf("������༶���ƣ�");
	scanf("%s", class);
	system("cls");
	FILE* fp = fopen(class, "w");
	do {
		printf("%s��\n������ѧ��������",class);
		scanf("%s", name);
		system("cls");
		printf("%s��\n���������ĳɼ���",class); 
		scanf(" %d", &Chinese_grade);
		system("cls");
		printf("%s��\n��������ѧ�ɼ�:",class);
		scanf(" %d", & Math_grade);
		fprintf(fp,"%s   %d   %d\n",name,Chinese_grade,Math_grade);
		system("cls");
		printf("�������������¼��ѧ����Ϣ������#����¼��ѧ����Ϣ\n");
		scanf(" %c", &flag);
	} while (flag != '#');
	fclose(fp);
	
}
//�½��༶����
void look_through() {
	system("cls");
	int flag;
	char name[10];
	int Chinese_grade, Math_grade;
	fp = fopen(class, "r");
	printf("����  ���ĳɼ�  ��ѧ�ɼ�\n");
	do {
		flag=fscanf(fp, "%s  %d  %d", name, &Chinese_grade, &Math_grade);
		if(flag==3)
		printf("%s  %d        %d\n", name, Chinese_grade, Math_grade);
	} while (flag == 3);
	fclose(fp);
}
//�鿴����ѧ����Ϣ
void append_student() {
	char name[10];
	int Chinese_grade;
	int Math_grade;
	char flag;
	system("cls");
	fp = fopen(class, "a");
	do {
		printf("%s��\n������ѧ��������", class);
		scanf("%s", name);
		system("cls");
		printf("%s��\n���������ĳɼ���", class);
		scanf(" %d", &Chinese_grade);
		system("cls");
		printf("%s��\n��������ѧ�ɼ�:", class);
		scanf(" %d", &Math_grade);
		fprintf(fp, "%s   %d   %d\n", name, Chinese_grade, Math_grade);
		system("cls");
		printf("�������������¼��ѧ����Ϣ������#����¼��ѧ����Ϣ\n");
		scanf(" %c", &flag);
	} while (flag != '#');
	fclose(fp);
}
//����ѧ����Ϣ
void delete_student() {
	char name[10];
	int flag = 3;
	int flag_arry_count=0;
	int stu_list_count = 0;
	STU* student_link_list = malloc(sizeof(STU) * 50);//һ��ѧ��������飬������ʱ���ѧ����Ϣ�������������50����
	fp = fopen(class, "r");
	system("cls");
	printf("������Ҫɾ����ѧ�������֣�\n");
	scanf("%s", name);
	for (stu_list_count; flag == 3; stu_list_count++) {
		flag = fscanf(fp, "%s  %d  %d", student_link_list[stu_list_count].name, &student_link_list[stu_list_count].Chinese_grade, &student_link_list[stu_list_count].Math_grade);
		if (!(strcmp(student_link_list[stu_list_count].name,name)))
			flag_arry_count = stu_list_count;
	}//���Ѵ��ڰ༶�е�ѧ����Ϣ����ѧ�������顣
	int count = stu_list_count-1;//count�������������do{}whileѭ��������
	stu_list_count = 0;

	fclose(fp);
	remove(class);//ɾ��ԭ���İ༶�ļ�
	fp = fopen(class, "w");
	do {
		if (stu_list_count == flag_arry_count)
			stu_list_count++;
		fprintf(fp, "%s   %d   %d\n", student_link_list[stu_list_count].name, student_link_list[stu_list_count].Chinese_grade, student_link_list[stu_list_count
		].Math_grade);
		stu_list_count++;
	} while (count > stu_list_count);//�ѳ���Ҫɾ����ѧ������Ϣ�������뵽ͬ�����ļ����С�
	free(student_link_list);//�ͷ�ѧ�����顣
	fclose(fp);

}
//ɾ��ѧ����Ϣ
void update_student() {
	int Chinese_grade;
	int Math_grade;
	char name[10];
	int flag = 3;
	int flag_arry_count = 0;
	int stu_list_count = 0;
	STU* student_link_list = malloc(sizeof(STU) * 50);//һ��ѧ��������飬������ʱ���ѧ����Ϣ�������������50����
	fp = fopen(class, "r");
	system("cls");
	printf("������Ҫ���µ�ѧ�������֣�");
	scanf("%s", name);
	for (stu_list_count; flag == 3; stu_list_count++) {
		flag = fscanf(fp, "%s  %d  %d", student_link_list[stu_list_count].name, &student_link_list[stu_list_count].Chinese_grade, &student_link_list[stu_list_count].Math_grade);
		if (!(strcmp(student_link_list[stu_list_count].name, name)))
			flag_arry_count = stu_list_count;
	}//���Ѵ��ڰ༶�е�ѧ����Ϣ����ѧ�������顣
	int count = stu_list_count - 2;//count�������������do{}whileѭ��������
	stu_list_count = 0;

	fclose(fp);
	remove(class);//ɾ��ԭ���İ༶�ļ�
	fp = fopen(class, "w");
	do {
		if (stu_list_count == flag_arry_count)
			stu_list_count++;
		fprintf(fp, "%s   %d   %d\n", student_link_list[stu_list_count].name, student_link_list[stu_list_count].Chinese_grade, student_link_list[stu_list_count
		].Math_grade);
		stu_list_count++;
	} while (count > stu_list_count);//�ѳ���Ҫɾ����ѧ������Ϣ�������뵽ͬ�����ļ����С�
	free(student_link_list);//�ͷ�ѧ�����顣
	
	
	printf("%s��\n���������ĳɼ���", class);
	scanf(" %d", &Chinese_grade);
	system("cls");
	printf("%s��\n��������ѧ�ɼ�:", class);
	scanf(" %d", &Math_grade);
	fprintf(fp, "%s   %d   %d\n", name, Chinese_grade, Math_grade);
    fclose(fp);
}
//����ѧ����Ϣ
void delete_class() {
	printf("������Ҫɾ���İ༶���֣�");
	scanf("%s", class);
	remove(class);
}
//ɾ���༶