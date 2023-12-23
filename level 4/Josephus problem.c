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
int Flag = 0; // 表示是否选出幸运儿 0未选出 1已选出 
//////////////////////////////////////////////////
 /*Function Prototype*/
 // 创建链表 
People* Stand_In_Circle(int Number)
{
	int i =0;
	
	People* head,*node,*end; // 头节点、普通节点、尾部节点	
	head = (People*)malloc(sizeof(People)); // 分配地址
	head->Code = 1; // 一号 
	end = head; // 若为空链表则头尾节点一样 
	 // 创建链表 
	for(i = 2;i <= Number;i++)
	{
		node = (People*)malloc(sizeof(People)); // 分配地址
		node->Code = i;
		end->next = node;
		end = node;
	}
	end->next = head; // 结束创建
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
			Flag = 1; // 已选出幸运儿
			break;	
		}
	}
	return head;
}
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	int Number = 0; // 总人数 
	int n = 0; // 间隔人数 
	scanf("%d",&Number);
	scanf("%d",&n);
	
	People* head = Stand_In_Circle(Number); // 排成圈，一个一个杀 

	head = People_Delete(head,n);
	
	if(Flag == 1)
	{
		printf("The lucky person is no:%d\n",head->Code);
	}
	
	return 0;
}

