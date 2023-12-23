#include<stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////
 /*Private Define*/
typedef struct LinkList
{
	int Code;
	struct LinkList* next;
}People;
////////////////////////////////////////////////////
 /*Global Variables*/
int Flag = 0; // ��ʾ�Ƿ�ѡ�����˶� 0δѡ�� 1��ѡ�� 
//////////////////////////////////////////////////
 /*Function Prototype*/
 // �������� 
People* Stand_In_Circle(int Number)
{
	int i =0;
	
	People* head,*node,*end; // ͷ�ڵ㡢��ͨ�ڵ㡢β���ڵ�	
	head = (People*)malloc(sizeof(People)); // �����ַ
	head->Code = 1; // һ�� 
	end = head; // ��Ϊ��������ͷβ�ڵ�һ�� 
	 // �������� 
	for(i = 2;i <= Number;i++)
	{
		node = (People*)malloc(sizeof(People)); // �����ַ
		node->Code = i;
		end->next = node;
		end = node;
	}
	end->next = head; // ��������
	return head;
}
People* People_Delete(People* head,int n)
{
	People* in = head;
	while(Flag==0)
	{
		int i = 0;
		while(i<n)
		{
			in = head;
			head = head->next;
			i++;
		}
		if(head->next != NULL)
		{
			in->next = head->next;
			free(head);
			head = in->next;
		}
		if(head->next == head)
		{
			Flag = 1; // ��ѡ�����˶�
			break;	
		}
	}
	return head;
}
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	int Number = 0; // ������ 
	int n = 0; // ������� 
	scanf("%d",&Number);
	scanf("%d",&n);
	
	People* head = Stand_In_Circle(Number); // �ų�Ȧ��һ��һ��ɱ 

	head = People_Delete(head,n);
	
	if(Flag == 1)
	{
		printf("The lucky person is no:%d\n",head->Code);
	}
	
	return 0;
}

