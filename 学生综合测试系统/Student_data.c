#include "config.h"
#define table_capacity 50
#define stu_path "Student.txt"

//建立链表
Student* initialize_table() {
	static Student* head;//存放链表的头节点
	Student* local = (Student*)malloc(sizeof(Student));//local为链表的中间节点，此行生成的指针为链表的头节点
	head = local;
	for (int i = 0; i < table_capacity - 1; i++) {
		local->next = (Student*)malloc(sizeof(Student));//建立中间节点，并把他们都连起来，形成链表
		local = local->next;
	}
	local->next = head;//让链表的尾节点与头节点连接起来，形成循环链表
	return head;//返回链表的头节点
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

//读取文件内容
void get_data(Student*head) {
	FILE* p_ini = fopen("basic.csv", "r");//读方式打开文件
	Student* p = head;//记录下头指针
	int cell=0;//所在的列
	char temp[5][30] = {NULL};//读取的格子内容
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
		fseek(p_ini, -1, SEEK_CUR);//将文件光标从当前位置向前移动一格
	}
	head->next = p;//将head再置为链表头结点
}

//写学生信息的函数
void create_basic() {
	FILE* p_ini = fopen("basic.csv", "r");
	if (p_ini == 0) {//判断该文件是否存在
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
 
//对文件内容按照学号从小到大排序
Student* sort_data(Student* head) {
	Student* p = head;//p为当前节点
	Student* p_later = p->next;//当前节点的下一个节点
	Student* p_front = p;//当前节点的上一个节点
	Student* temp;//temp中间变量，用于交换指针
	Student* tail = p;//存放尾节点
	int count = 0;//用于存放节点数
	do {
		count++;
		p = p->next;
	} while (p != head); //查看链表里有几个节点

	for (int i = 0; i < count - 1; i++) {//外层循环的次数为总节点数-1
		while(p->next != head){
			if (strcmp(p->stu_num, p_later->stu_num) > 0) {//若当前节点的学号大于下一个节点的学号时
				if (p == head) {//当前节点为头节点时

					while (tail->next != head) {//寻找尾节点
						tail = tail->next;
					}

					p->next = p_later->next;
					p_later->next = p;//此时p_later为头节点
					head = p_later;//更新头节点
					tail->next = head;//让尾节点指向新的头节点
				}
				else {//当前节点为中间节点时
					p->next = p_later->next;
					p_later->next = p;
					p_front->next = p_later;
				}
		/*此时p_later在head的前面，下面把p和p_later位置互换，保证p在p_later前面，方便后面判断*/
				temp = p_later;
				p_later = p;
				p = temp;
			}
			p_front = p;//让p_front始终在p的前面
			p = p->next;
			p_later = p_later->next;
		}
		/*外层循环结束，让p重新回到头节点，p_later回到p的下一个节点*/
		p = head;
		p_later = p->next;
	}
	return head;//返回头节点
}

//对文件进行初始化
void initialize_fire() {
	FILE* p = fdopen("basic_测试.csv", "w");//p变量用于操控文件


}




//浏览学生信息
// 睡前思路：
// 通过操控光标的位置，比如先在控制台的第二行画一行的 "-"
// 然后返回到上一行，输出文件第一行的内容(除了逗号以外的)，除了地址外其他属性（列）的宽度固定
// （需要把地址放在最后一列）
// 重复以上操作
//void browse() {
//	char s;//存放从文件中获取的字符
//	FILE* p = fopen("basic.csv", "r");
//	if (p == 0) {
//		printf("未写入学生信息！请先写入！");
//	}
//
//	for (int i = 0; s = fgetc(p) != -1; i++) {
//		if (s == ',') {
//			printf("%c", '|');
//		}
//		else if (s == '\n') {
//			printf("%c", '\n');
//			for (int i = 0; i < 101; i++) {
//				printf("%c", '-');
//			}
//			
//		}
//		else {
//			printf("%c", s);
//		}
//		
//	}
//}



//void csv_to_link() {
//	FILE* f = fopen("basic.csv", "r");
//}





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




