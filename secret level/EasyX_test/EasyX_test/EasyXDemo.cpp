#include <easyx.h>
#include<stdio.h>
#include<math.h>

#define PI 3.14
int main()
{
	 // 初始化
	initgraph(800, 800); 
	setorigin(400, 300);
	setaspectratio(1, -1);
	setlinecolor(WHITE);
	 // 同心圆(眼睛)
	for (int radius = 10; radius <= 160; radius+=30)
	{
		circle(0, 0, radius);
	}
	 //  五个点
	//putpixel(0, 0, RED);
	//putpixel(200, 200, YELLOW);
	//putpixel(200, -200, CYAN);
	//putpixel(-200, -200, GREEN);
	//putpixel(-200, 200, WHITE);

	 // 星空
	for (int i = 0; i < 800; i++)
	{
		int x = rand() % (800 + 1) - 400;
		int y = rand() % (800 + 1) - 500;
		putpixel(x, y, WHITE);
	}
	for (int i = 0; i < 200; i++)
	{
		int x = rand() % (800 + 1) - 400;
		int y = rand() % (800 + 1) - 500;
		putpixel(x, y, YELLOW);
	}
	// 椭圆(眼珠)
	ellipse(-300, 200, 300, -200);
	ellipse(-299, 199, 299, -199);
	ellipse(-298, 198, 298, -198);
	// 无边框填充圆（瞳孔）
	setfillcolor(RED);
	solidcircle(0, 0, 10);
	// 扇形（高光）
	setfillcolor(BLACK);
	solidpie(-10, 10, 10, -10, -PI*4 / 9, -PI / 10); // 顺时针旋转
	// 大量填充颜色（眼白）
	setfillcolor(WHITE);
	floodfill(0, 190, WHITE, 0);
	// 魔法阵
	setlinecolor(MAGENTA);
	 // 矩形
	rectangle(-300, 200, 300, -200);
	 // 多边形
	POINT pts[] = { {0,290},{350,0},{0,-290},{ - 350,0}}; // 注意这些点的顺序为画图顺序
	polygon(pts, 4);
	double theta = PI / 2;
	double delta = PI * 2 / 5;
	int r = 160;
	POINT points[5];
	for (int i = 0; i < 5; i++)
	{
		points[i].x = r * cos(theta + delta * i);
		points[i].y = r * sin(theta + delta * i);
	}
	polygon(points, 5);
	for (int i = 0; i < 5; i++)
	{
		points[i].x = r * cos(-theta + delta * i);
		points[i].y = r * sin(-theta + delta * i);
	}
	polygon(points, 5);
	 // 圆弧（笑）
	setlinecolor(WHITE);
	arc(-400, -100, 400, -400, PI / 8, PI*7/8);

	getchar();
	closegraph();

	return 0;
}
