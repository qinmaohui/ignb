#include <graphics.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <windows.h>
#include<ege.h>
int menu11();
void menu22();
void xuanguan();
void dakai(char lujing[]);
void yidong(char *p, int max);
int menu33(char *p, int max);
int menu44(char *p, int max);
struct guan
{
	int guanshu;
}guan;//�ṹ��
struct chehui
{
	char map[50][50];
	int x;
	int y;
}zhan[1000];
int menu11()
{
	PIMAGE pimg_logo = newimage();
	getimage(pimg_logo, "resources\\image\\logo.jpg", 0, 0);

	//����
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//���ֱ���ɫ��ע��setbkcolor����Ҳ��ͬʱ�ı����ֱ���ɫ��
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	setbkmode(TRANSPARENT);
	putimage(280, 50, pimg_logo);
	setfont(48, 0, "����");
	outtextxy(400, 300, "��ʼ(S)");
	outtextxy(380, 400, "�˳�(ESC)");

	delimage(pimg_logo);
	char option;
	while (1)
	{
		fflush(stdin);
		option = getch();
		option = tolower(option);



		if (option == 's')
		{
			menu22();
			break;

		}
		else if (option == 27)
		{
			return 0;
		}
	}
}
void menu22()
{
	char option2;
	PIMAGE pimg_logo = newimage();
	getimage(pimg_logo, "resources\\image\\logo.jpg", 0, 0);
	//����
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//���ֱ���ɫ��ע��setbkcolor����Ҳ��ͬʱ�ı����ֱ���ɫ��
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
	setfont(80, 0, "����");

	//Ҫʹ�������ʽ���ַ�����outtextrect
	//�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
	setbkmode(TRANSPARENT);
	putimage(280, 50, pimg_logo);

	setfont(48, 0, "����");
	outtextxy(360, 300, "��ͷ��ʼ(A)");
	outtextxy(400, 350, "ѡ��(X)");
	outtextxy(400, 400, "����(R)");

	delimage(pimg_logo);

	while (1)
	{
		fflush(stdin);
		option2 = getch();
		option2 = tolower(option2);
		if (option2 == 'r')
		{
			menu11();
			break;
		}
		if (option2 == 'x')
		{
			xuanguan();
			break;
		}
		if (option2 == 'a')
		{
			char lujing[50] = { "E:\\visual2017\\ignb\\map\\1.txt" };
			guan.guanshu = 1;
			dakai(lujing);
			break;
		}


	}
}
void xuanguan()
{
	char level[10] = { 0 };
	int g;
	PIMAGE pimg_logo = newimage();
	getimage(pimg_logo, "resources\\image\\logo.jpg", 0, 0);
	//����
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//���ֱ���ɫ��ע��setbkcolor����Ҳ��ͬʱ�ı����ֱ���ɫ��
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
	setfont(50, 0, "����");

	//Ҫʹ�������ʽ���ַ�����outtextrect
	//�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
	setbkmode(TRANSPARENT);
	putimage(280, 40, pimg_logo);
	outtextxy(325, 300, "��ѡ��ؿ�");
	level[0] = getch();//ѡ��ؿ�������һ�����֣�

	g = level[0] - '0';
	guan.guanshu = g;
	strcat(level, ".txt");
	char lujing[50] = { "E:\\visual2017\\ignb\\map\\" };
	strcat(lujing, level);//��strcat����һ�¼���·���ͺ�׺������Ӧ���ļ���
	
	dakai(lujing);

}
void dakai(char lujing[])
{
	char map[50][50] = { 0 };
	int max = 0;
	char *p;
	p = &map[0][0];
	FILE *lv = fopen(lujing, "r");//���ļ�

	fscanf(lv, "%d", &max);//���ļ��ж�ȡһ��������Ϊmax��maxΪ���������

	for (int i = 0; i <= max; i++)
	{

		fgets(map[i], 25, lv);
	}
	fclose(lv);
	yidong(p, max);
}
void yidong(char *p, int max)//pָ���ͼ����ĵ�һ��λ�ã�maxΪ��ͼ�����������
{
	char map[51][51] = { 0 };
	int m = 0;
	int x, y;
	int step = 0;
	int X[100] = { 0 }, Y[100] = { 0 };
	int num = 0;
	int goal = 0;
	int mmm = 0, nnn = 0;
	int wide = strlen(map[0]);
	int high = max;
	int count = 0;
	char option=' ';
	mciSendString(TEXT("open Boxmove.wav alias Boxmove"), NULL, 0, NULL);

	PIMAGE pimg_wall = newimage();
	PIMAGE pimg_land = newimage();
	PIMAGE pimg_BoxYellow = newimage();
	PIMAGE pimg_BoxRed = newimage();
	PIMAGE pimg_aim = newimage();
	PIMAGE pimg_ManUP1 = newimage();
	PIMAGE pimg_ManUP2 = newimage();
	PIMAGE pimg_ManDOWN1 = newimage();
	PIMAGE pimg_ManDOWN2 = newimage();
	PIMAGE pimg_ManRIGHT1 = newimage();
	PIMAGE pimg_ManRIGHT2 = newimage();
	PIMAGE pimg_ManLEFT1 = newimage();
	PIMAGE pimg_ManLEFT2 = newimage();
	PIMAGE pimg_black = newimage();

	getimage(pimg_wall, "resources\\image\\wall.jpg", 0, 0);
	getimage(pimg_land, "resources\\image\\land.jpg", 0, 0);
	getimage(pimg_BoxYellow, "resources\\image\\BoxYellow.jpg", 0, 0);
	getimage(pimg_BoxRed, "resources\\image\\BoxRed.jpg", 0, 0);
	getimage(pimg_aim, "resources\\image\\aim.jpg", 0, 0);
	getimage(pimg_ManUP1, "resources\\image\\ManUP1.jpg", 0, 0);
	getimage(pimg_ManUP2, "resources\\image\\ManUP2.jpg", 0, 0);
	getimage(pimg_ManDOWN1, "resources\\image\\ManDOWN1.jpg", 0, 0);
	getimage(pimg_ManDOWN2, "resources\\image\\ManDOWN2.jpg", 0, 0);
	getimage(pimg_ManRIGHT1, "resources\\image\\ManRIGHT1.jpg", 0, 0);
	getimage(pimg_ManRIGHT2, "resources\\image\\ManRIGHT2.jpg", 0, 0);
	getimage(pimg_ManLEFT1, "resources\\image\\ManLEFT1.jpg", 0, 0);
	getimage(pimg_ManLEFT2, "resources\\image\\ManLEFT2.jpg", 0, 0);
	getimage(pimg_black, "resources\\image\\black.jpg", 0, 0);
	high = (7 - high) / 2;
	wide = (1 - strlen(map[0])) / 2;



		for (int i = 0; i < 50; i++)//�ҵ�@�����꼴��ʼλ�ò����ҵ�Ŀ���X�ĸ���
		{

			for (int j = 0; j < 50; j++)
			{

				map[i][j] = *(p + m);

				m++;
				
				if (map[i][j] == '@')
				{
					x = i;
					y = j;
				}
				if (map[i][j] == 'X')
				{
					goal++;
					X[num] = i;
					Y[num] = j;
					num++;
				}
			}
		}
	

	while (1)
	{
		if (is_run())
		{
			delay_fps(60);
			if (count > 60)
				count = 0;
			count += 2;
		}
		if (step >= 0)
		{
			zhan[step].x = x;
			zhan[step].y = y;
			for (int o = 0; o < 50; o++)
			{
				for (int p = 0; p < 50; p++)
				{
					zhan[step].map[o][p] = map[o][p];

				}
			}
		}
		step++;
		char option = getch();
		option = tolower(option);
		switch (option)
		{
		case 's':
			if ((map[x + 1][y] == ' ') || (map[x + 1][y] == 'X'))
			{
				if (map[x + 1][y] == 'X')
				{
					X[num] = x + 1;
					Y[num] = y;
					num++;
				}

				map[x + 1][y] = '@';
				map[x][y] = ' ';
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				x++;

				break;
			}
			if ((map[x + 1][y] == 'O') && (map[x + 2][y] == ' '))
			{
				map[x][y] = ' ';
				map[x + 1][y] = '@';
				map[x + 2][y] = 'O';
				x++;
				break;
			}
			if ((map[x + 1][y] == 'O') && (map[x + 2][y] == 'X'))
			{
				map[x][y] = ' ';
				map[x + 1][y] = '@';
				map[x + 2][y] = 'O';
				X[num] = x + 2;
				Y[num] = y;
				num++;
				x++;
				break;
			}break;




		case 'w':
			if ((map[x - 1][y] == ' ') || (map[x - 1][y] == 'X'))
			{
				if (map[x - 1][y] == 'X')
				{
					X[num] = x - 1;
					Y[num] = y;
					num++;
				}

				map[x - 1][y] = '@';
				map[x][y] = ' ';
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				x--;
				break;


			}
			if ((map[x - 1][y] == 'O') && (map[x - 2][y] == ' '))
			{
				map[x][y] = ' ';
				map[x - 1][y] = '@';
				map[x - 2][y] = 'O';
				x--;
				break;
			}
			if ((map[x - 1][y] == 'O') && (map[x - 2][y] == 'X'))
			{
				map[x][y] = ' ';
				map[x - 1][y] = '@';
				map[x - 2][y] = 'O';
				X[num] = x - 2;
				Y[num] = y;
				num++;
				x--;
				break;
			}break;
		case 'd':
			if ((map[x][y + 1] == ' ') || (map[x][y + 1] == 'X'))
			{
				if (map[x][y + 1] == 'X')
				{
					X[num] = x;
					Y[num] = y + 1;
					num++;
				}

				map[x][y + 1] = '@';
				map[x][y] = ' ';
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				y++;

				break;
			}
			if ((map[x][y + 1] == 'O') && (map[x][y + 2] == ' '))
			{
				map[x][y] = ' ';
				map[x][y + 1] = '@';
				map[x][y + 2] = 'O';
				y++;
				break;
			}
			if ((map[x][y + 1] == 'O') && (map[x][y + 2] == 'X'))
			{
				map[x][y] = ' ';
				map[x][y + 1] = '@';
				map[x][y + 2] = 'O';
				X[num] = x;
				Y[num] = y + 2;
				num++;
				y++;
				break;
			}break;
		case 'a':
			if ((map[x][y - 1] == ' ') || (map[x][y - 1] == 'X'))
			{
				if (map[x][y - 1] == 'X')
				{
					X[num] = x;
					Y[num] = y - 1;
					num++;
				}

				map[x][y - 1] = '@';
				map[x][y] = ' ';
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				y--;

				break;
			}
			if ((map[x][y - 1] == 'O') && (map[x][y - 2] == ' '))
			{
				map[x][y] = ' ';
				map[x][y - 1] = '@';
				map[x][y - 2] = 'O';
				y--;
				break;
			}
			if ((map[x][y - 1] == 'O') && (map[x][y - 2] == 'X'))
			{
				map[x][y] = ' ';
				map[x][y - 1] = '@';
				map[x][y - 2] = 'O';
				X[num] = x;
				Y[num] = y - 2;
				num++;
				y--;
				break;
			}break;
		case 27:
		{
			menu33(p, max);
			break;
		}
		case 'z'://���ع���
		{
			if (step == 1 || step <= 0)
			{
				cleardevice();
				setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
				setfont(48, 0, "����");
				outtextxy(360, 300, "�Ƿ���������");
				getch();
				menu33(p, max);
				break;
			}
			else if (step > 0)
			{
				for (int ii = 0; ii < 50; ii++)
				{
					for (int jj = 0; jj < 50; jj++)
					{
						map[ii][jj] = zhan[step - 2].map[ii][jj];
					}
				}
				x = zhan[step - 2].x;
				y = zhan[step - 2].y;
				step--;
				step--;
				break;
			}
			break;
		}
		break;






		}

		cleardevice();

		setcolor(EGERGB(0x40, 0xE0, 0xD0));
		setfillcolor(WHITE);
		bar(750, 0, 755, 700);

		bar(0, 595, 1000, 600);
		bar(0, 0, 5, 600);
		bar(995, 0, 1000, 600);

		setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
		setfont(48, 0, "����");
		setbkmode(TRANSPARENT);
		char str[20];
		setfont(24, 0, "����");
		sprintf(str, "������%d", step);
		outtextxy(780, 250, str);
		outtextxy(780, 400, "����(Z)");
		outtextxy(780, 450, "��ͣ(ESC)");
		for (int ii = 0; ii < 50; ii++)
		{
			for (int jj = 0; jj < 50; jj++)
			{
				if (map[ii][jj] == '|' || map[ii][jj] == '=')
					putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_black);
				if (map[ii][jj] == ' ')
					putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_land);
				if (map[ii][jj] == 'O')
					putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_BoxYellow);
				for (int ll = 0; ll < 20; ll++)
				{
					if (map[ii][jj] == 'O'&&ii == X[ll] && jj == Y[ll])
					{
						putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_BoxRed);
					}
				}
				if (map[ii][jj] == '#')
					putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_wall);
				if (map[ii][jj] == 'X')
					putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_aim);
				if (map[ii][jj] == '@')
					if (option == 'd')
					{
						if (count > 30)
							putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_ManRIGHT1);
						else
							putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_ManRIGHT2);
					}
					else if (option == 'a')
					{
						if (count > 30)
							putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_ManLEFT1);
						else
							putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_ManLEFT2);
					}
					else if (option == 'w')
					{
						if (count > 30)
							putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_ManUP1);
						else
							putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_ManUP2);
					}
					else
					{
						if (count > 30)
							putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_ManDOWN1);
						else
							putimage(50 + jj * 50 + wide * 50, 20 + ii * 50 + high * 50, pimg_ManDOWN2);
					}
			}
		}

		for (int k = 0; k < goal; k++)
		{
			if (map[X[k]][Y[k]] == 'O')
			{

				mmm++;
				nnn = mmm;
			}
		}
		if (nnn == goal)
		{
			num = 0;//��ʼ��num��goal
			goal = 0;
			cleardevice();
			menu44(p, max);
			break;

		}
		mmm = 0;

	}





}
int menu33(char *p, int max)
{
	cleardevice();

	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(48, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(400, 200, "����(R)");
	setfont(40, 0, "����");
	outtextxy(140, 300, "ѡ��(X)");
	outtextxy(320, 300, "����(Q)");
	outtextxy(480, 300, "��һ��(N)");
	outtextxy(700, 300, "���˵�(M)");
	while (1)
	{
		char option = getch();
		option = tolower(option);
		if (option == 'r')
		{
			break;
		}

		switch (option)
		{
		case 'x':
		{
			xuanguan();
			break;
		}
		case 'q':
		{
			cleardevice();
			setcolor(EGERGB(0x40, 0xE0, 0xD0));
			setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
			setfont(48, 0, "����");
			setbkmode(TRANSPARENT);
			outtextxy(400, 200, "ȷ�����¿�ʼ��");
			setfont(40, 0, "����");
			outtextxy(140, 300, "����(ESC)");
			outtextxy(320, 300, "ȷ��(Q)");
			while (1)
			{
				char option1 = getch();
				if (option1 == 'q')
				{
					yidong(p, max);
				}
				else if (option1 == 27)
				{
					menu33(p, max);
				}
				break;
			}
		}
		case 'm':
		{
			menu11();
			break;

		}
		case 'n':
		{
			char level[10] = { 0 };

			level[0] = guan.guanshu + '0' + 1;
			guan.guanshu = guan.guanshu + 1;
			strcat(level, ".txt");
			char lujing[50] = { "E:\\visual2017\\ignb\\map\\" };
			strcat(lujing, level);//��strcat����һ�¼���·���ͺ�׺������Ӧ���ļ���
			dakai(lujing);
			break;


		}



		}
	}
	return max;

}
int menu44(char *p, int max)
{
	cleardevice();

	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(60, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(420, 150, "���أ�");


	setfont(40, 0, "����");
	outtextxy(140, 350, "ѡ��(X)");
	outtextxy(320, 350, "����(Q)");
	outtextxy(480, 350, "��һ��(N)");
	outtextxy(700, 350, "�˵�(M)");
	while (1)
	{
		char option = getch();
		option = tolower(option);
		switch (option)
		{
		case 'x':
		{
			xuanguan();
			break;
		}
		case 'q':
		{
			cleardevice();
			setcolor(EGERGB(0x40, 0xE0, 0xD0));
			setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
			setfont(48, 0, "����");
			setbkmode(TRANSPARENT);
			outtextxy(400, 200, "ȷ�����¿�ʼ��");
			setfont(40, 0, "����");
			outtextxy(140, 300, "����(ESC)");
			outtextxy(320, 300, "ȷ��(Q)");
			while (1)
			{
				char option1 = getch();
				if (option1 == 'q')
				{
					yidong(p, max);
				}
				else if (option1 == 27)
				{
					menu33(p, max);
				}
				break;
			}
		}
		case 'm':
		{
			menu11();
			break;

		}
		case 'n':
		{
			char level[10] = { 0 };
			level[0] = guan.guanshu + '0' + 1;
			guan.guanshu = guan.guanshu + 1;
			strcat(level, ".txt");
			char lujing[50] = { "E:\\visual2017\\ignb\\map\\" };
			strcat(lujing, level);//��strcat����һ�¼���·���ͺ�׺������Ӧ���ļ���
			dakai(lujing);
			break;


		}



		}
	}
}

void start()
{
	cleardevice();
	menu11();





}
int main()
{
	//��ʼ��Ϊ640*480��С
	ege::setinitmode(ege::INIT_ANIMATION);
	initgraph(1000, 600);
	setcaption("������2.0        By����ï��");
	ege::randomize();

	//�ȴ��û�����
	start();
	getch();


	//�ر�ͼ�ν���
	closegraph();
	return 0;
}