/***********************************
*
*��Ŀ��������
*�����ˣ���ï��
*ʱ�䣺11.11
*
*
*
*
************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <windows.h>
int menu11();
void menu22();
void xuanguan();
void dakai(char lujing[]);
void yidong(char *p, int max);
int menu33(char *p, int max);
int menu44(char *p, int max);
void ditu();
void init();
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
	system("cls");
	char option;
	char menu1[50][50] = {
"\n\n\n\n\n\n\n",
"\t\t\t\t\t\t\t ������",
"\t\t\t\t\t\t   |===============|",
"\t\t\t\t\t\t   |               |",
"\t\t\t\t\t\t   |               |",
"\t\t\t\t\t\t   |    ��ʼ(S)    |",
"\t\t\t\t\t\t   |  ��ͼ�༭��M��|",
"\t\t\t\t\t\t   |   �˳�(ESC)   |",
"\t\t\t\t\t\t   |               |",
"\t\t\t\t\t\t   |               |",
"\t\t\t\t\t\t   |===============|",
	};
	for (int i = 0; i < 11; i++)
	{
		puts(menu1[i]);
	}
	while (1)
	{

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
		else if (option == 'm')
		{
			ditu();
			break;
		}
	}
}
void menu22()
{
	char option2;
	char menu2[50][50] = {
		"\n\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t ������\n",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   ��ͷ��ʼ(A) |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ѡ��(X)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ����(R)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|"
	};
	system("cls");
	for (int i1 = 0; i1 < 11; i1++)
	{
		puts(menu2[i1]);

	}
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
			char lujing[50] = { "resources\\map\\1.txt" };
			guan.guanshu = 1;
			dakai(lujing);
			break;
		}


	}
}
void xuanguan()
{
	char level[10];
	int g;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t");
	printf("��ѡ��ؿ�:");
	gets(level);//ѡ��ؿ�������һ�����֣�
	g = level[0] - '0';
	guan.guanshu = g;
	strcat(level, ".txt"); 
	char lujing[50] = { "resources\\map\\" };
	strcat(lujing, level);//��strcat����һ�¼���·���ͺ�׺������Ӧ���ļ���
	dakai(lujing);

	

}
void dakai(char lujing[])
{
	char map[50][50] = { 0 };
	int max=0;
	char *p;
	p = &map[0][0];
	FILE *lv = fopen(lujing, "r");//���ļ�
	if (lv == NULL)//�ж��ܷ���ļ�
		printf("Դ�����޷��򿪣�\n");
	system("cls");
	fscanf(lv, "%d", &max);//���ļ��ж�ȡһ��������Ϊmax��maxΪ���������
	if (max==0||max>50||max<0)
	{
		ungetc(max, lv);
		max = 30;
	}
	for (int i = 0; i <= max; i++)
	{

		fgets(map[i], 25, lv);
	}

	fclose(lv);
	yidong(p,max);
}
void yidong(char *p,int max)//pָ���ͼ����ĵ�һ��λ�ã�maxΪ��ͼ�����������
{
	char map[50][50] = { 0 };
	int m = 0;
	int x, y;
	int step = 0;
	int X[150] = { 0 }, Y[150] = { 0 };
	int num = 0;
	int goal = 0;
	int mmm = 0, nnn = 0;
	for (int i = 0; i < 50; i++)//�ҵ�@�����꼴��ʼλ�ò����ҵ�Ŀ���X�ĸ���
	{
		for(int j=0;j<50;j++)//�ӽ���һ������ȡ���ĵ�ͼ��ȡ��map�У���ָ�봫�ݣ�
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
	system("cls");
	for (int j = 0; j <= max; j++)
	{
		printf("\t\t\t\t\t\t    ");//����ͼ�Ƶ��м�ȥ
		printf("%s", map[j]);
	}
	
	while (1)
	{
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
		
		char option = getch();
		option = tolower(option);
		printf("%c", option);
		switch (option)
		{
		case 's':
			if ((map[x + 1][y] == ' ') ||( map[x + 1][y] == 'X'))
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
				step++;
				break;
			}
			if ((map[x + 1][y] == 'O') && (map[x + 2][y] == ' '))
			{
				map[x][y] = ' ';                                                       
				map[x + 1][y] = '@';
				map[x + 2][y] = 'O';
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				x++;
				step++;
				
				break;
			}
			if ((map[x + 1][y] == 'O') && (map[x + 2][y] == 'X'))
			{
				map[x][y] = ' ';
				map[x + 1][y] = '@';
				map[x + 2][y] = 'O';
				X[num] = x + 2;
				Y[num] = y;
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				num++;
				x++;
				step++;
				
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
				step++;
				break;


			}
			if ((map[x - 1][y] == 'O') && (map[x - 2][y] == ' '))
			{
				map[x][y] = ' ';
				map[x - 1][y] = '@';
				map[x - 2][y] = 'O';
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				x--;
				step++;
				
				break;
			}
			if ((map[x - 1][y] == 'O') && (map[x - 2][y] == 'X'))
			{
				map[x][y] = ' ';
				map[x - 1][y] = '@';
				map[x - 2][y] = 'O';
				X[num] = x - 2;
				Y[num] = y;
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				num++;
				x--;
				step++;
				
				break;
			}break;
		case 'd':
			if ((map[x][y + 1] == ' ') || (map[x ][y + 1] == 'X'))
			{
				if (map[x ][y + 1] == 'X')
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
				step++;
				break;
			}
			if ((map[x][y + 1] == 'O') && (map[x][y + 2] == ' '))
			{
				map[x][y] = ' ';
				map[x][y + 1] = '@';
				map[x][y + 2] = 'O';
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				y++;
				step++;
				
				break;
			}
			if ((map[x][y + 1] == 'O') && (map[x][y + 2] == 'X'))
			{
				map[x][y] = ' ';
				map[x][y + 1] = '@';
				map[x][y + 2] = 'O';
				X[num] = x;
				Y[num] = y + 2;
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				num++;
				y++;
				step++;
				
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
				step++;
				break;
			}
			if ((map[x][y - 1] == 'O') && (map[x][y - 2] == ' '))
			{
				map[x][y] = ' ';
				map[x][y - 1] = '@';
				map[x][y - 2] = 'O';
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				y--;
				step++;
				
				break;
			}
			if ((map[x][y - 1] == 'O') && (map[x][y - 2] == 'X'))
			{
				map[x][y] = ' ';
				map[x][y - 1] = '@';
				map[x][y - 2] = 'O';
				X[num] = x;
				Y[num] = y - 2;
				for (int i1 = 0; i1 < num; i1++)
				{
					if (x == X[i1] && y == Y[i1])
					{
						map[x][y] = 'X';
					}
				}
				num++;
				y--;
				step++;
				
				break;
			}break;
		case 27:
		{
			menu33(p,max);
			break;
		}
		case 'z'://���ع���
		{
			if (step<=0)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t�Ƿ�����!!\n\n\n\n\n\n\n\n\n\n\n\n\n");
				system("pause");
				menu33(p, max);
				break;
			}
			else if(step>0)
			{
				for (int ii = 0; ii < 50; ii++)
				{
					for (int jj = 0; jj < 50; jj++)
					{
						map[ii][jj] = zhan[step - 1].map[ii][jj];
					}
				}
				x = zhan[step - 1].x;
				y = zhan[step - 1].y;
				step=step-1;
				break;
			}
			break;
		}
		break;






		}

		system("cls");
		for (int j = 0; j <= max; j++)
		{
			printf("\t\t\t\t\t\t    ");//���ؿ��Ƶ��м�ȥ
			printf("%s", map[j]);
		}
		printf("\n\n\t\t\t\t\t\t\t������%d", step);
		printf("\n\t\t\t\t\t\t\tZ:����  ESC:��ͣ");
		for (int k = 0; k < goal; k++)
		{
			if (map[X[k]][Y[k]]=='O')
			{
				
				mmm++;
				nnn = mmm;
			}
		}
		if (nnn == goal)
		{
			num = 0;//��ʼ��num��goal
			goal = 0;
			system("cls");
			menu44(p, max);
			break;

		}
		mmm = 0;

	}


	


}
int menu33(char *p, int max)
{
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t\t\t        ����(R)\n");
	printf("\n\n\t\t\t\t         ѡ��(X)  ����(Q)  ��һ��(N)  ���˵�(M)  \n");
	printf("\n\n\n\t\t\t\t\t\t      ����˵��");
	printf("\n\n\t\t\t\t\t        W:��  S:��  A:��  D:��");
	printf("\n\n\t\t\t\t\t         @:��  O:����  X:�յ� ");
	while (1)
	{
		char option = getch();
		option = tolower(option);
		if (option == 'r')
		{
			system("cls");
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
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tȷ�����¿�ʼ��\n\t\t\t\t\t\tQ:ȷ��\n\t\t\t\t\t\tESC:����");
			while (1)
			{
				fflush(stdin);
				
				char option1 = getch();
				option1 = getch();
				option = tolower(option);
				if (option1 == 'q')
				{
					yidong(p, max);
					break;
				}
				else if (option1 == 27)
				{
					menu33(p, max);
					break;
				}
				break;
			}
			break;
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
int menu44(char *p, int max)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t��ϲͨ�����أ�");
	printf("\n\n\t\t\t\t\t  ѡ��(X)  ���汾��(Q)  ��һ��(N)  ���˵�(M)  \n");
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
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tȷ�����¿�ʼ��\n\t\t\t\t\t\tQ:ȷ��\n\t\t\t\t\t\tESC:����");
			while (1)
			{
				char option1 = getch();
				getch();
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
void init() {

	//�öδ��빦�������ع�꣬������win32��̽ӿڣ�����Ҫ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���ھ��
	CONSOLE_CURSOR_INFO cci;//ʵ�л�һ������̨�����Ϣ��
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ

	system("title ������1.0");//�趨��������
	system("mode con cols=120 lines=30");//�趨���ڴ�С
}
void ditu()
{
	char map[50][50] = {0};
	char filename[15] = { 0 };
	char lujing[50] = { "resources\\map\\" };
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t������ؿ���ţ���ѡ�ؽ���������Ӧ��Ž���ؿ���");
	gets(filename);
	strcat(filename, ".txt");
	strcat(lujing, filename);
	int x=0, y=0;
	system("cls");
	char max = {0};
	int mm = 0;
	FILE *tfp = fopen(lujing, "r");//���ļ�
	
	system("cls");
	if (tfp != NULL)//�ж��Ƿ�Ϊ�գ���Ϊ�ղŶ�ȡ
	{
		fscanf(tfp, "%d", &mm);
	}//���ļ��ж�ȡһ��������Ϊmax��maxΪ���������
	
	if (mm<'0' || mm>'9')
	{
		mm = 15;
	}
	if (tfp != NULL)
	{
		for (int j = 0; j < mm; j++)
		{
			fgets(map[j], 25, tfp);

		}
	}
	else if(tfp==NULL)
	{
		for (int jj = 0; jj < mm; jj++)
		{
			for (int kk = 0; kk < 20; kk++)
			{
				map[jj][kk] = ' ';
				map[jj][20] = '\n';
			}
		}
	}
	if (tfp != NULL)
	{
		fclose(tfp);
	}
	for (int k = 0; k < mm; k++)
	{

		printf("%s", map[k]);
	}
	
	while (1)
	{
		char option = getch();
		switch (option)
		{
			case '1':
			
				map[x][y] = '@'; break;
				
			
			case '2':
			
				map[x][y] = 'O'; break;
			
			case '3':
			

				map[x][y] = 'X'; break;
			
			case '4':
			
				map[x][y] = '#'; break;
			
			case '5':
			
				map[x][y] = '|'; break;
			
			case '6':
			
				map[x][y] = '='; break;
			
			case 'w':
			
				if (x != 0)
				{
					x--;
				} break;
			
			case 's':
			
				if (x != 50)
				{
					x++;
				} break;
			
			case 'a':
			
				if (y != 0)
				{
					y--;
				} break;
			
			case 'd':
			
				if (y != 50)
				{
					y++;
				}break;
			case ' ':
			{
				map[x][y] = ' '; break;
			}
			case '9':
			{
				map[x][y] = '9';
				break;
			}
			
						
		}
		if (option == 'p')
		{
			break;
		}
		system("cls");
		for (int i = 0; i < mm; i++)
		{
			
			printf("%s",map[i]);
		}
		printf("\t\t\t\t\t\t\t\n\n\n1:@\n2:O\n3:X\n4:#\n5:|\n6:=\n�ո�:�� ��\nWASD:�ƶ�����\nP:��ɱ༭");
	}
	FILE *fp = fopen(lujing, "wt+");
	{
		for (int j = 0; j < mm; j++)
		{
			fputs(map[j], fp);
			
		}
	}
	fclose(fp);
	menu11();

	

}


void start()
{

		init();
		system("cls");
		menu11();
		
		



}
int main()
{
	start();
	return 0;
}



