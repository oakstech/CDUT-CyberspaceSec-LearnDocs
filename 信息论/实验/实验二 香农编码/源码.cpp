//运行环境：VS 2017
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 20

//定义全局变量
int n, num[MAX];//信源符号个数，num数组为信源符号编号数组
double p[MAX];//信源概率
double sp[MAX] = { 0 };//累加概率
int len[MAX] = { 0 };//码长
int codes[MAX][MAX];//码字

//输入函数
void input() {
	cout << ">请输入信源符号个数：";
	cin >> n;
	int k = 1;
	for (int i = 0; i < n; i++) {//为信源符号编号
		num[i] = k;
		k++;
	}
	cout << "请依次输入这" << n << "个信源符号的概率："<<endl;
	for (int i = 0; i < n; i++) {
		cout << ">p(x" << i + 1 << ")=";
		cin >> p[i];
	}
	system("cls");
	cout << "你输入的信源符号概率为：" << endl;//回显输入
	for (int i = 0; i < n; i++) {
		cout << "p(x" << num[i] << ")=" << p[i]<<"\t";
	}
	system("cls");
}

//排序函数
void sort() {
	double tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (p[j] < p[j + 1]) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}
}

//累加概率
void sum() {
	for (int i = 1; i < n; i++) {
		sp[i] = sp[i-1] + p[i-1];
	}
}

//码长计算
void codelen() {
	for (int i = 0; i < n; i++) {
		len[i] = (log(1.0 / p[i])/log(2)) + 1;
	}
}

//二元码计算
void bcode() {
	int z = 0;//整数部分
	double q = 0;//小数部分
	for (int i = 0; i < n; i++) {
		int k = 0;
		q = p[i];
		do
		{
			z = q * 2;
			codes[i][k] = z;
			q = q * 2 - z;
			k++;//计数器
		} while (k != len[i]);//当长度取到len[i]时退出循环
	}
}


//输出
void output() {
	cout << "信源符号" << '\t' << "信源符号概率" << '\t' << "累计概率" << '\t' << "码长" << '\t' << "码字" << endl;
	for (int i = 0; i < n; i++) {
		cout << "s" << num[i] << '\t' << '\t' << p[i] << '\t' << '\t' << sp[i] << '\t' << '\t' << len[i] << '\t';
		for (int j = 0; j < len[i]; j++) {
			cout<<codes[i][j];
		}
		cout << endl;
	}
}

int main() {
	input();
	sort();
	sum();
	codelen();
	bcode();
	output();
	system("pause");
}
