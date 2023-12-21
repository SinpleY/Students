#include "config.h"
#include "UI.h"
#include <tchar.h>
#include <math.h>
int flag = 0;//UI界面的标志位


//开屏显示
void UI_first() {
	system("color 0C");//修改控制台内文字的颜色，浅红色
	gotoxy(38,25);//改变控制台的光标位置
	printf("欢迎来到学生综合测试系统！");
	gotoxy(0, 26);
	printf("系统启动中...");
	gotoxy(0, 27);
	for (int i = 0; i < 100; i++) {
		printf("=");
		Sleep(50);//让进程或程序进入休眠，类似于延迟函数，参数的单位为ms
	}
}

void UI_main() {
	system("cls");//清屏指令
	printf("                                       学 生 综 合 测 试 系 统                                       ");
	printf("\n");
	printf("*--------------------------------------------------------------------------------------------------*");
	printf("*                                                                                                  *");
	printf("*                                       1 访 问 学 生 信 息 库                                     *");
	printf("*                                                                                                  *");
	printf("*--------------------------------------------------------------------------------------------------*");
	printf("*--------------------------------------------------------------------------------------------------*");
	printf("*                                                                                                  *");
	printf("*                                       2 访 问 学 生 成 绩 库                                     *");
	printf("*                                                                                                  *");
	printf("*--------------------------------------------------------------------------------------------------*");
	printf("*--------------------------------------------------------------------------------------------------*");
	printf("*                                                                                                  *");
	printf("*                                      -1 退 出 系 统                                              *");
	printf("*                                                                                                  *");
	printf("*--------------------------------------------------------------------------------------------------*");
	printf("请输入对应的数字，执行功能：");
	scanf("%d", &flag);
	getchar();//吸收scanf结束时的回车符
}

void UI_students() {
	system("cls");//清屏指令
	printf("*--------------------------------------------------------------------------------------------------*");
	printf("*                                  1 创 建 学 生 数 据                                             *");
	printf("*                                  2 修 改 学 生 数 据                                             *");
	printf("*                                  3 删 除 学 生 数 据                                             *");
	printf("*                                  4 浏 览 学 生 数 据                                             *");
	printf("*                                  5 查 询 学 生 数 据                                             *");
	printf("*                                  0 返 回 主 界 面                                                *");
	printf("*                                 -1 退 出 系 统                                                   *");
	printf("*--------------------------------------------------------------------------------------------------*");
	printf("请输入对应的数字，执行功能：");
	scanf("%d", &flag);
	getchar();//吸收scanf结束时的回车符
	switch (flag) {
	case 1://创建学生数据
		system("cls");//清屏指令
		while (1) {
			create_basic();
			printf("写入成功！是否继续输入? (y or n)");
			char temp;//中间变量，接收上面的y和n
			while (1) {
				temp = getchar();
				char c;//清除缓存区用的中间变量
				while ((c = getchar()) != '\n');//清除缓存区，直到c为\n时才结束
				if (temp == 'y' || temp == 'Y' || temp == 'n' || temp == 'N') {
					break;
				}
				printf("请输入 y or n:");
			}
			if (temp == 'n' || temp == 'N') {//退出while循环，返回到学生信息库界面
				break;
			}
			else if (temp == 'y' || temp == 'Y') {//继续循环，继续输入学生信息
				continue;
			}
		}
		break;
	case 2://修改学生数据
		system("cls");//清屏指令
		while (1) {
			/*     函数    */
			printf("修改成功！是否继续修改? (y or n)");
			char temp;//中间变量，接收上面的y和n
			while (1) {
				temp = getchar();
				char c;//清除缓存区用的中间变量
				while ((c = getchar()) != '\n');//清除缓存区，直到c为\n时才结束
				if (temp == 'y' || temp == 'Y' || temp == 'n' || temp == 'N') {
					break;
				}
				printf("请输入 y or n:");
			}
			if (temp == 'n' || temp == 'N') {//退出while循环，返回到学生信息库界面
				break;
			}
			else if (temp == 'y' || temp == 'Y') {//继续循环，继续输入学生信息
				continue;
			}
		}
		break;
	case 3://删除学生数据
		system("cls");//清屏指令
		while (1) {
			/*     函数    */
			printf("删除成功！是否继续删除? (y or n)");
			char temp;//中间变量，接收上面的y和n
			while (1) {
				temp = getchar();
				char c;//清除缓存区用的中间变量
				while ((c = getchar()) != '\n');//清除缓存区，直到c为\n时才结束
				if (temp == 'y' || temp == 'Y' || temp == 'n' || temp == 'N') {
					break;
				}
				printf("请输入 y or n:");
			}
			if (temp == 'n' || temp == 'N') {//退出while循环，返回到学生信息库界面
				break;
			}
			else if (temp == 'y' || temp == 'Y') {//继续循环，继续输入学生信息
				continue;
			}
		}
		break;
	case 4://浏览学生信息
		system("cls");//清屏指令
		/*   函数   */
		break;
	case 5://查询学生信息
		system("cls");//清屏指令
		while (1) {
			/*     函数    */
			printf("查询成功！是否继续查询? (y or n)");
			char temp;//中间变量，接收上面的y和n
			while (1) {
				temp = getchar();
				char c;//清除缓存区用的中间变量
				while ((c = getchar()) != '\n');//清除缓存区，直到c为\n时才结束
				if (temp == 'y' || temp == 'Y' || temp == 'n' || temp == 'N') {
					break;
				}
				printf("请输入 y or n:");
			}
			if (temp == 'n' || temp == 'N') {//退出while循环，返回到学生信息库界面
				break;
			}
			else if (temp == 'y' || temp == 'Y') {//继续循环，继续输入学生信息
				continue;
			}
		}
		break;
	}
}

void UI_grade() {
	system("cls");//清屏指令
	printf("*--------------------------------------------------------------------------------------------------*");
	printf("*                               1 输 入 学 生 科 目 成 绩                                          *");
	printf("*                               2 输 入 学 生 测 评 成 绩                                          *");
	printf("*                               0 返 回 主 界 面                                                   *");
	printf("*                              -1 退 出 系 统                                                      *");
	printf("*--------------------------------------------------------------------------------------------------*");
	printf("请输入对应的数字，执行功能：");
	scanf("%d", &flag);
	getchar();//吸收scanf结束时的回车符
	switch (flag) {
	case 1:
		while (1) {
			/*    函数    */
			printf("写入成功！是否继续写入? (y or n)");
			char temp;//中间变量，接收上面的y和n
			while (1) {
				temp = getchar();
				char c;//清除缓存区用的中间变量
				while ((c = getchar()) != '\n');//清除缓存区，直到c为\n时才结束
				if (temp == 'y' || temp == 'Y' || temp == 'n' || temp == 'N') {
					break;
				}
				printf("请输入 y or n:");
			}
			if (temp == 'n' || temp == 'N') {//退出while循环，返回到学生信息库界面
				break;
			}
			else if (temp == 'y' || temp == 'Y') {//继续循环，继续输入学生信息
				continue;
			}
		}
		break;
	case 2:
		while (1) {
			/*    函数    */
			printf("写入成功！是否继续输入? (y or n)");
			char temp;//中间变量，接收上面的y和n
			while (1) {
				temp = getchar();
				char c;//清除缓存区用的中间变量
				while ((c = getchar()) != '\n');//清除缓存区，直到c为\n时才结束
				if (temp == 'y' || temp == 'Y' || temp == 'n' || temp == 'N') {
					break;
				}
				printf("请输入 y or n:");
			}
			if (temp == 'n' || temp == 'N') {//退出while循环，返回到学生信息库界面
				break;
			}
			else if (temp == 'y' || temp == 'Y') {//继续循环，继续输入学生信息
				continue;
			}
		}
		break;
	}
}

//设置控制台的位置
void gotoxy(short x, short y) {
	COORD coord = { x, y };//COORD是Windows API中定义的一种结构体类型，表示控制台屏幕上的坐标。以形参x和y进行初始化。
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置控制台光标位置
	//GetStdHandle(STD_OUTPUT_HANDLE); 获取控制台输出句柄
}

void UI() {
	SetConsoleTitle(_T("学生综合测试系统OVO"));//更改窗口的标题
	system("mode con: cols=100 lines=50");//更改窗口的大小为50行，100列
	UI_first();
	system("color 0A");//修改控制台内文字的颜色，浅绿色
	while (flag != -1) {
		if (flag == 0) {
			UI_main();
		}
		else if (flag == 1) {
			UI_students();
		}
		else if (flag == 2) {
			UI_grade();
		}
		else if (flag == -1) {
			system("exit");//关闭Dos窗口，退出程序
		}
	}
}

//color命令在控制台的用法
//COLOR[attr]
//
//attr        指定控制台输出的颜色属性。
//
//颜色属性由两个十六进制数字指定 -- 第一个
//对应于背景，第二个对应于前景。每个数字
//可以为以下任何值 :
//
//0 = 黑色       8 = 灰色
//1 = 蓝色       9 = 淡蓝色
//2 = 绿色       A = 淡绿色
//3 = 浅绿色     B = 淡浅绿色
//4 = 红色       C = 淡红色
//5 = 紫色       D = 淡紫色
//6 = 黄色       E = 淡黄色
//7 = 白色       F = 亮白色