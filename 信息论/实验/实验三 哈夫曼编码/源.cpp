#include <stdio.h>
#include<iostream>
#define MAXBIT 10 /*����������������󳤶�*/
#define MAXVALUE 10000 /*�������Ȩֵ*/
#define MAXLEAF 30 /*����������������Ҷ�ӽڵ����*/
#define MAXNODE MAXLEAF*2-1 /*���������������*/
typedef struct { /*������������Ϣ�Ľṹ*/
int bit[MAXBIT];
int start;}Hcodetype;
typedef struct { /*�����������Ľṹ*/
float weight;
float parent;
float lchild;
float rchild;
}Hnodetype;

void huffmantree(Hnodetype huffnode[MAXNODE],int n) /*������������ĺ���*/   {
	int i,j,m1,m2,x1,x2;
	for(i=0;i<2*n-1;i++) /*��Ź���������������huffnode[]��ʼ��*/   {
		huffnode[i].weight=0;
		huffnode[i].parent=-1;
		huffnode[i].lchild=-1; 
		huffnode[i].rchild=-1; 
	} 
	for(i=0;i<n;i++) /*������N��Ҷ�ӽڵ��Ȩֵ*/  { 
		printf("������������Դ����",i); 
		scanf_s("%f",&huffnode[i].weight);   
	}
	for(i=0;i<n-1;i++) /*��ʼѭ�������������*/   {
		m1=m2=MAXVALUE;
		x1=x2=0; 
		for(j=0;j<n+i;j++)   {
			if(huffnode[j].weight<m1&&huffnode[j].parent==-1)   {
				m2=m1;x2=x1;m1=huffnode[j].weight;x1=j;   
			}   
			else if (huffnode[j].weight < m2&&huffnode[j].parent == -1) {
				m2 = huffnode[j].weight; x2 = j; 
			}
		}
		huffnode[x1].parent = n + i; 
		huffnode[x2].parent = n + i;
		huffnode[n + i].weight = huffnode[x1].weight + huffnode[x2].weight;
		huffnode[n + i].lchild = x1; 
		huffnode[n + i].rchild = x2;
	} 
}

void main() {
	Hnodetype huffnode[MAXNODE];
	Hcodetype huffcode[MAXLEAF], cd;
	int i, j, c, p, n;
	printf("������n\n");
	scanf_s("%d", &n); /*����Ҷ�ӽڵ����*/   
	huffmantree(huffnode, n); /*������������*/  
	for (i = 0; i < n; i++) /*��ѭ����ÿ��Ҷ�ӽڵ��Ӧ�ַ��Ĺ���������*/ {
		cd.start = n - 1; c = i; 
		p = huffnode[c].parent;
		while (p != -1) {
			if (huffnode[p].lchild == c) cd.bit[cd.start] = 0; 
			else cd.bit[cd.start] = 1;  
			cd.start--; c = p;  
			p = huffnode[c].parent; 
		} 
		for (j = cd.start + 1; j < n; j++) /*���������ÿ��Ҷ�ڵ�Ĺ���������ͱ������ʼλ*/   
			huffcode[i].bit[j] = cd.bit[j]; 
		huffcode[i].start = cd.start; }  
	for (i = 0; i < n; i++) /*���ÿ��Ҷ�ӽڵ�Ĺ���������*/ {
		printf("%d character is:", i);
		for (j = huffcode[i].start + 1; j < n; j++) 
			printf("%d", huffcode[i].bit[j]);   printf("\n"); 
	}
	system("pause");
}