#include <easyx.h>
#include<stdio.h>
#include<math.h>

#define PI 3.14
int main()
{
	 // ��ʼ��
	initgraph(800, 800); 
	setorigin(400, 300);
	setaspectratio(1, -1);
	setlinecolor(WHITE);
	 // ͬ��Բ(�۾�)
	for (int radius = 10; radius <= 160; radius+=30)
	{
		circle(0, 0, radius);
	}
	 //  �����
	//putpixel(0, 0, RED);
	//putpixel(200, 200, YELLOW);
	//putpixel(200, -200, CYAN);
	//putpixel(-200, -200, GREEN);
	//putpixel(-200, 200, WHITE);

	 // �ǿ�
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
	// ��Բ(����)
	ellipse(-300, 200, 300, -200);
	ellipse(-299, 199, 299, -199);
	ellipse(-298, 198, 298, -198);
	// �ޱ߿����Բ��ͫ�ף�
	setfillcolor(RED);
	solidcircle(0, 0, 10);
	// ���Σ��߹⣩
	setfillcolor(BLACK);
	solidpie(-10, 10, 10, -10, -PI*4 / 9, -PI / 10); // ˳ʱ����ת
	// ���������ɫ���۰ף�
	setfillcolor(WHITE);
	floodfill(0, 190, WHITE, 0);
	// ħ����
	setlinecolor(MAGENTA);
	 // ����
	rectangle(-300, 200, 300, -200);
	 // �����
	POINT pts[] = { {0,290},{350,0},{0,-290},{ - 350,0}}; // ע����Щ���˳��Ϊ��ͼ˳��
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
	 // Բ����Ц��
	setlinecolor(WHITE);
	arc(-400, -100, 400, -400, PI / 8, PI*7/8);

	getchar();
	closegraph();

	return 0;
}
