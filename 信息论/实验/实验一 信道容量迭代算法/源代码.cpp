//运行环境：VS 2017
#include<iostream>
#include<cmath>
#include <conio.h>
using namespace std;

//定义全局变量
double channel[20][20] = { 0 };	//定义信道转移概率矩阵（如果r、s>20，则需修改此处）
int r = 0, s = 0;

/*
还需改进的：加上概率检测机制

*/

//输入信道转移概率矩阵
void input() {
	cout << "请输入信源符号个数r=";
	cin >> r;
	r = r - 1;
	cout << "请输入信宿符号个数s=";
	cin >> s;
	s = s - 1;
	system("cls");
	cout << endl;
	for (int i = 0; i <= r; i++) {	//输入信道概率矩阵
		for (int j = 0; j <= s; j++) {
			cout << "请键入信道转移概率p(y" << j + 1 << "|x" << i + 1 << "):";
			cin >> channel[i][j];
			cout << endl;
		}
	}
	system("cls");
	//输入后回显输入的信道转移概率矩阵
	cout << endl<<"你输入的信道转移概率矩阵为：";
	for (int i = 0; i <= r; i++) {
		cout << endl;	//矩阵换行
		for (int j = 0; j <= s; j++) {
			cout << "p(y" << j + 1 << "|x" << i + 1 << ")=" << channel[i][j] << '\t';
		}
	}
}

//查看当前信道转移概率矩阵
void look() {
	cout << "当前系统中的信道转移概率矩阵为：";
	for (int i = 0; i <= r; i++) {
		cout << endl;	//矩阵换行
		for (int j = 0; j <= s; j++) {
			cout << "p(y" << j + 1 << "|x" << i + 1 << ")=" << channel[i][j] << '\t';
		}
	}
}

//定义最佳信源分布及信道容量计算函数
void calculate() {

	//变量定义
	int k = 0;	//初始化循环变量
	double delta = 0;
	double p[20];	//定义信源分布矩阵（如果r>20，则需要修改）
	double phi[20][20];//定义phi矩阵（r、s>20需修改）
	double c = DBL_MIN;//定义信道容量
	double tmp;//比较c时候临时存储信道容量值

	//初始化信源分布
	for (int i = 0; i <= r; i++) {
		p[i] = (double)(1.0 / (double)r);
	}

	//计算最佳信源分布
	cout << "请输入门限值：";
	cin >> delta;
	do
	{
		k++;
		tmp = c;
		double sum1 = 0, a = 0;	//计算phi分母部分,sum为分母部分求和，a为每一项
		for (int i = 0; i <= r; i++) {
			for (int j = 0; j <= s; j++) {
				a = p[i] * channel[i][j];
				sum1 = sum1 + a;
			}
		}
		for (int i = 0; i <= r; i++) {	//计算phi
			for (int j = 0; j <= s; j++) {
				phi[j][i] = (p[i] * channel[i][j]) / sum1;
			}
		}

		//生成新的信道转移概率矩阵
		double sum2 = 0;
		a = 0;
		for (int i = 0; i <= r; i++) {	//计算新的信道转移概率矩阵中的求和项pji*log(phi)
			for (int j = 0; j <= s; j++) {
				a = channel[i][j] * log(phi[j][i]);
				sum2 = sum2 + a;
			}
		}
		double sum3 = 0;
		a = 0;
		for (int j = 0; j <= s; j++) {	//计算新的信道转移概率矩阵以及信道容量公式中的求和项
			for (int i = 0; i <= r; i++) {
				a = exp(channel[i][j] * phi[j][i]);
				sum3 = sum3 + a;
			}
		}
		for (int i = 0; i <= r; i++) {	//计算新的矩阵
			p[i] = exp(sum2) / sum3;
		}

		//计算信道容量
		c = log(sum3);
	} while (fabs(c - tmp) / c > delta);

	//输出最佳信源分布和信道容量
	cout << "信道容量为：C=" << c << endl;
	cout << "最佳信源分布为："<<endl;
	for (int i = 0; i <= r; i++) {
		cout << "p(" << i + 1 << ")="<< p[i] << '\t';
	}
}

//菜单函数
void menu(){
	cout << "                    " << endl << endl;
	cout << "                    " << "                            " << endl;
	cout << "                    " << "     信道容量的迭代算法     " << endl;
	cout << "                    " << "                            " << endl;
	cout << "                    " << "                            " << endl;
	cout << "                    " << "   ①输入信道转移概率矩阵   " << endl;
	cout << "                    " << "                            " << endl;
	cout << "                    " << " ②查看当前信道转移概率矩阵 " << endl;
	cout << "                    " << "                            " << endl;
	cout << "                    " << "  ③最佳信源分布及信道容量  " << endl;
	cout << "                    " << "                            " << endl;
	cout << "                    " << "         ④退出系统         " << endl;
	cout << "                    " << "                            " << endl;
	cout << "                    " << "                            " << endl<<endl<<endl;
	cout << "                    " << "        制作：彭重严        " << endl;
	cout << "                    " << "     学号：201817030115     " << endl;
}

//主函数
int main()
{
	system("mode con cols=72 lines=23");
	char choose = '0';
	do
	{
		menu();
		choose = _getch();
		system("cls");//读取按键后清除menu
		switch (choose)
		{
		case '1': input(); cout <<endl<< endl<< "请按任意键返回"; _getch(); break;
		case '2': look(); cout << endl << endl<< "请按任意键返回"; _getch(); break;
		case '3': calculate(); cout << endl << endl<< "请按任意键返回"; _getch(); break;
		default: break;
		}
		system("cls");//清除函数执行后的页面
	} while (choose != '4');
	return 0;
}