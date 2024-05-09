#include <stdio.h>
#include <easyx.h>

#pragma comment(lib,"winmm.lib")

#define WIDTH 1280
#define HEIGHT 720

int main()
{
	IMAGE img1,img2;
	int w, h;
	loadimage(&img1, _T("./1.jpg"));
	w = img1.getwidth();
	h = img1.getheight();

	loadimage(&img2, _T("./1.jpg"), w / 1.5, h / 1.5);

	ExMessage m;
	RECT r = { WIDTH/2-w/2, HEIGHT / 2-h/2-50, WIDTH/2 +w / 2, HEIGHT/2 - h / 2 };

	int score=0;
	char s[10];
	initgraph(WIDTH, HEIGHT);
	BeginBatchDraw();
	mciSendString("open ./����.mp3",NULL,0,NULL);
	mciSendString("play ./����.mp3 repeat", NULL, 0, NULL);
	while (1)
	{
		//ľ��ͼ
		putimage(WIDTH / 2 - w/2, HEIGHT / 2-h/2, &img1);
		sprintf_s(s, 10, "���£�%d", score);
		settextstyle(40, 0, _T("����"));
		outtextxy(WIDTH / 2 - 70, HEIGHT / 2 + 120, s);
		settextstyle(50, 0, _T("����"));
		outtextxy(WIDTH / 2 - 100, 100, "����ľ��");

		FlushBatchDraw();


		//�û�һ��
		if (peekmessage(&m)&& m.message == WM_LBUTTONDOWN)
		{
			if(m.x> WIDTH / 2 -w / 2&&m.x< WIDTH / 2 + w / 2&&m.y>HEIGHT / 2 - h / 2&&m.y< HEIGHT / 2 + h / 2)
			{
				clearrectangle(0, 200, WIDTH, HEIGHT);
				putimage(WIDTH / 2-w/3, HEIGHT / 2 -h/3, &img2);
				settextstyle(30,0, _T("����"));
				drawtext(_T("����+1"),&r, DT_CENTER| DT_VCENTER | DT_SINGLELINE);
				score++;
				sprintf_s(s, 10, "���£�%d", score);
				settextstyle(40, 0, _T("����"));
				outtextxy(WIDTH / 2 - 70, HEIGHT / 2 + 120, s);
				mciSendString("play ./ľ��.wav", NULL, 0, NULL);
				FlushBatchDraw();
				Sleep(200);
				cleardevice();
			}
		}
	}
	return 0;
}