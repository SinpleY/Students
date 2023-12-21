#include "config.h"
#define stu_path "Student.txt"

//此函数用于获取当前文件内的数据并放入一个新定义的链表中，返回该链表的头指针
Student* initialize_table() {
	static Student* old=NULL;//初始化一个old指针，用于记录当前链表指针，但它的初值为空
	free(old);//释放，确保内存空间不会浪费
	//获取链表长度
	int table_capacity=0;//代表链表长度
	FILE* f = fopen("basic.csv", "r");//打开文件
	char temp_c;//临时变量，用于判断行数
	for (;;) {
		temp_c = fgetc(f);//读取文件内下一个字符
		if (temp_c == '\n') {
			table_capacity++;//；链表的长度+1
		}
		else if (temp_c == -1) {//文件结束
			fclose(f);
			break;
		}		
	}
	//建立循环链表
	Student* head;//存放链表的头节点
	Student* local = (Student*)malloc(sizeof(Student));//local为链表的中间节点，此行生成的指针为链表的头节点
	head = local;
	for (int i = 0; i < table_capacity - 1; i++) {
		local->next = (Student*)malloc(sizeof(Student));//建立中间节点，并把他们都连起来，形成链表
		local = local->next;
	}
	local->next = head;//让链表的尾节点与头节点连接起来，形成循环链表

	get_data(head);//把目前文件里的数据读入链表中
	old = head;//记录下当前的链表头结点，下次启用该函数时释放该节点
	return head;//返回链表的头节点
}

//将csv文件中读到的学生数据写入初始化好的指针链表
void get_data(Student* head) {
	FILE* p_ini = fopen("basic.csv", "r");//读方式打开文件
	Student* p = head;//记录下头指针

	int cell = 0;//所在的列
	char temp[5][30] = { NULL };//读取的格子内容
	for (;;) {//不断地遍历每一行
		static char point[2] = { "\0" };//当前指向的字符
		cell = 0;//将所在的列置为0
		for (;;) {//遍历一行的数据存入temp中
			point[0] = fgetc(p_ini);//读取一个字符
			if (point[0] == -1) {//文件结束
				break;//跳出
			}
			else if (point[0] == ',') {//遇到列分隔符
				cell++;//temp定位下标+1
			}
			else if (point[0] == '\n') {//遇到换行符
				fseek(p_ini, -1, ftell(p_ini));
				break;//跳出，结算本行内容
			}
			else {//读取到正常文本内容
				strcat(temp[cell], point);//装到相应的罐子里
			}
		}


		//将temp的值赋到链表中
		strcpy(head->stu_num, temp[0]);
		strcpy(head->stu_name, temp[1]);
		strcpy(head->stu_sex, temp[2]);
		strcpy(head->stu_address, temp[3]);
		strcpy(head->stu_phone_num, temp[4]);



		//清空temp值
		for (int i = 0; i < 5; i++) {
			strcpy(temp[i], "");
		}

		//判断文件是否结束
		if (point[0] = fgetc(p_ini) == -1) {
			break;
		}
		else {
			//链表向前
			head = head->next;
		}

	}
	head->next = p;//将head再置为链表头结点
}


void input(Student* stu) {
	printf("请输入学生的学号：");
	scanf("%s", stu->stu_num);

	printf("请输入学生的姓名：");
	scanf("%s", stu->stu_name);

	printf("请输入学生的性别：");
	scanf("%s", stu->stu_sex);

	printf("请输入学生的家庭住址：");
	scanf("%s", stu->stu_address);


	printf("请输入学生的联系电话：");
	scanf("%s", stu->stu_phone_num);

}




//写学生信息的函数
void create_basic() {
	FILE* p_ini = fopen("basic.csv", "r");
	if (p_ini == 0) {
		p_ini = fopen("basic.csv", "w");
	}
	else {
		fclose(p_ini);
		p_ini=fopen("basic.csv", "a");
	}

	Student *new=(Student*)malloc(sizeof(Student));
	input(new);
	setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区,达到清除缓存区的目的；
	fputs(strcat(new->stu_num, ","), p_ini);

	fputs(strcat(new->stu_name, ","), p_ini);
	fputs(strcat(new->stu_sex, ","), p_ini);
	fputs(strcat(new->stu_address, ","), p_ini);
	fputs(strcat(new->stu_phone_num, "\n"), p_ini);
	fclose(p_ini);
}
 
void csv_to_link() {
	FILE* f = fopen("basic.csv", "r");
}





//
//void innitialize(){
//	Student* p = initialize_table;//p表示初始化完链表的头指针
//	FILE* f;//操纵文件的变量
//	f = fopen("Student.txt", "w");//读取文件，不存在则创建新的文件
//	for (int i = 0; i < table_capacity; i++) {
//		while (fgetc(f) != ",") {
//
//		}
//		
//	}
//}
//
////对文件进行初始化
//FILE* initialize_fire() {
//	FILE* p = fdopen(stu_path, "w");//p变量用于操控文件
//
//
//}

//
//

//
//
//
//
//
//
//
//
//
//
//




