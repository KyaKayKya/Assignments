// Jump Ball.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<easyx.h>
#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define width 1000
#define height 800
#define radius 30


int main()
{
	int x, y;
	int counter = 0; // 记录圆数
	clock_t Last_Tick, Now_Tick;
	ExMessage m; // 鼠标消息结构体
	Now_Tick = 0;
	Last_Tick = 0;
	x = 0;
	y = 0;

	// 初始化
	initgraph(width, height);
	setorigin(width / 2, height / 2);
	setaspectratio(1, -1);

	setbkcolor(RGB(164, 225, 202));
	cleardevice();

	setfillcolor(WHITE);
	solidcircle(0, 0, radius);

	setlinecolor(BLACK);
	rectangle(-width / 2, height / 2, width / 2, -height / 2);
	rectangle(-width / 2 + 2, height / 2 - 2, width / 2 - 2, -height / 2 + 2);
	rectangle(-width / 2 + 4, height / 2 - 4, width / 2 - 4, -height / 2 + 4);
	// 小球弹跳
	while (1)
	{
		if (counter >= 5 || Now_Tick - Last_Tick >= 50) // 允许同时存在5个圆，使帧率较低时动作更流畅;50ms鼠标无动作自动清屏
		{
			cleardevice(); // 清屏
			counter = 0;
			solidcircle(x, y, radius);
			rectangle(-width / 2, height / 2, width / 2, -height / 2);
			rectangle(-width / 2 + 2, height / 2 - 2, width / 2 - 2, -height / 2 + 2);
			rectangle(-width / 2 + 4, height / 2 - 4, width / 2 - 4, -height / 2 + 4);
		}

		Now_Tick = clock();
		if (Now_Tick - Last_Tick >= 5) // 刷新间隔为5ms
		{
			m = getmessage();
			if (m.message == WM_MOUSEMOVE) // 若移动
			{
				 // 鼠标移动则球跟随
				x = m.x-width/2;
				y = -(m.y-height/2);
				solidcircle(x, y, radius);
				counter++; // 记录画的圆数
			}
			Last_Tick = Now_Tick;
		}
		//// 延时
	   //Sleep(2);
	}

	getchar();
	closegraph;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
