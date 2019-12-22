#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define left_broad 19
#define right_broad 90
#define up_broad 7
#define down_broad 25

void Appearance();         //��Ϸ��ʼ���� 1


void regulation();         //��Ϸ����  3


void instruction();        //����˵��  4


void Game_Failure();       //��Ϸģʽ���� 5

void choose();             //��Ϸ����ѡ�� 6

void click1();             //��Ϸģʽ1 7

void click2();             //��Ϸģʽ2 8

void makejet();            //ģʽ2��ӡ�ɻ�  9



void cleanjet();           //ģʽ2����ɻ��ۼ�
void flower();             //��������
void click1_barrier();     //ģʽ1�ϰ���
void click2_barrier();     //ģʽ2�ϰ���
void gotoxy(int x, int y); //�ƶ����
void ifget();              //����ֵ�Ӽ�
void choosedif();          //ģʽ2�Ѷ�ѡ��
int color(int c);          //��ɫѡ��
int  forscore();           //��¼ģʽ2�ķ���
void preserve();			//����ģʽ2����Ϣ
int  forscore2();			//��¼ģʽ1�ķ���
void preserve2();			//���汦ʯ1����Ϣ
void Game_Failure2();		//ģʽ1�Ľ�������
void opendata1();
void opendata2();
void choosedata();

void Broad();


int n, d;
int count = 0;
int num = 0;
int i, j, Temp, Temp1, Temp2;
int b[4];
int T[2000][2000];
int a[100][100] = { 0 };
//0Ϊ�հ�
//1Ϊ�ɻ�
//2Ϊ�ӵ�
//3Ϊ�ϰ���


struct plane
{
    int x;
    int y;
    int flag;
    int speed;
    int score;
    int level;
} plane1;

struct jam
{
    int x;
    int y;
    int score;
    int life;
    int flag;
} jam1;

struct energy
{
    int x;
    int y;
} energy1;
HANDLE hOut;

struct date
{
    int idx;
    char name[20];
    int score;
} history[50];

void choosedata()
{
    system("cls");
    int i;
    int x;
    color(14);
    gotoxy(43, 3);
    printf("��ѡ����Ϸģʽ");

    for (i = 6; i <= 16; i++)
    {
        gotoxy(27, i);
        printf("��");
    }
    for (i = 6; i <= 16; i++)
    {
        gotoxy(70, i);
        printf("��");
    }
    gotoxy(27, 6);
    printf("�X");
    gotoxy(70, 6);
    printf("�[");
    for (i = 28; i <= 69; i++)
    {
        gotoxy(i, 6);
        printf("=");
    }
    gotoxy(27, 16);
    printf("�^");

    gotoxy(70, 16);
    printf("�a");

    for (i = 28; i <= 69; i++)
    {
        gotoxy(i, 16);
        printf("=");
    }
    color(6);
    gotoxy(30, 7);
    printf("1.�𹾹���ս��ð�յ���ʷ��¼ ");
    gotoxy(30, 9);
    printf("2.�𹾹�������ս����ʷ��¼");
    gotoxy(30, 11);
    printf("3.�� 3 �� ��");
    gotoxy(30, 13);
    printf("�� ѡ �� �� ��\b\b\b");
    scanf("%d", &x);
    if (x >= 1 && x <= 3)
    {
        switch (x)
        {
        case 1:
            system("cls");
            opendata1();
            break;
        case 2:
            system("cls");
            opendata2();
            break;
        case 3:
            system("cls");
            Appearance();
            Broad();
        }
    }
    else
    {
        choose();
    }
}

void opendata1()
{
    int x;
    system("cls");

    FILE* fp;
    int ch;
    if (!(fp = fopen("d://first.txt", "r")))
    {
        printf("error");
        exit(1);
    }
    color(11);

    ch = fgetc(fp);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp);

    }
    fclose(fp);
    gotoxy(30, 11);
    printf("�� 1 �� ��");
    gotoxy(30, 13);
    printf("�� ѡ �� �� ��\b\b\b");
    scanf("%d", &x);
    if (x >= 1 && x <= 3)
    {
        switch (x)
        {

        case 1:
            system("cls");
            Appearance();
            Broad();
        }
    }
}

void opendata2()
{
    int x;
    system("cls");

    FILE* fp;
    int ch;
    if (!(fp = fopen("d://second.txt", "r")))
    {
        printf("error");
        exit(1);
    }
    color(11);

    ch = fgetc(fp);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp);

    }
    fclose(fp);
    gotoxy(30, 11);
    printf("�� 1 �� ��");
    gotoxy(30, 13);
    printf("�� ѡ �� �� ��\b\b\b");
    scanf("%d", &x);
    if (x >= 1 && x <= 3)
    {
        switch (x)
        {

        case 1:
            system("cls");
            Appearance();
            Broad();
        }
    }
}

int color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 0;
}

void gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



void PrintPlane(struct plane* plane1)
{
    for (i = 8; i <= 24; i++)
    {
        for (j = 21; j <= 89; j++)
        {
            if (a[i][j] == 2)
            {
                color(9);
                gotoxy(j, i);
                printf("*");
            }
            else if (a[i][j] == 3)
            {
                color(12);
                gotoxy(j, i);
                printf("#");
            }
        }
    }
    color(5);
    gotoxy(plane1->x, plane1->y);
    printf("��");
    a[plane1->y][plane1->x] = a[plane1->y][plane1->x + 1] = 1;
    color(9);
    gotoxy(plane1->x, plane1->y + 1);
    printf("�|");
    a[plane1->y + 1][plane1->x] = a[plane1->y + 1][plane1->x + 1] = 1;
    color(11);
    gotoxy(plane1->x - 1, plane1->y + 2);
    printf("���");

    a[plane1->y + 1][plane1->x] = a[plane1->y + 1][plane1->x + 1] = a[plane1->y][plane1->x] = a[plane1->y][plane1->x + 1] = a[plane1->y + 2][plane1->x - 1] = a[plane1->y + 2][plane1->x] = a[plane1->y + 2][plane1->x + 1] = a[plane1->y + 2][plane1->x + 2] = 1;
    color(3);
    gotoxy(102, 9);
    printf("%-4d", plane1->score);
    gotoxy(102, 11);
    printf("%d", plane1->level);
    gotoxy(102, 13);
    printf("%d", plane1->speed);
}

void BlankPlane(struct plane* plane1)
{
    for (i = 8; i <= 24; i++)
    {
        for (j = 21; j <= 89; j++)
        {
            if (a[i][j] != 0)
            {
                gotoxy(j, i);
                printf(" ");
            }
        }
    }
}

void choosedif() //�Ѷ�ѡ��
{
    system("cls");
    gotoxy(55, 5);
    color(14);
    printf("�� �� ѡ ��");

    color(4);
    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 6);
        printf("=");
    }

    gotoxy(29, 6);
    printf("�X");

    for (i = 7; i <= 20; i++)
    {
        gotoxy(29, i);
        printf("��");
    }

    gotoxy(29, 20);
    printf("�^");

    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 20);
        printf("=");
    }

    gotoxy(90, 20);
    printf("�a");

    gotoxy(90, 6);
    printf("�[");

    for (i = 7; i < 20; i++)
    {
        gotoxy(90, i);
        printf("��");
    }
    color(11);
    gotoxy(34, 11);
    printf("1.���Ѷ�  2.��ͨ�Ѷ� 3.�����Ѷ� 4.��̬�Ѷ�");
    gotoxy(34, 14);
    printf("׼���ÿ�ʼð������\n");
    gotoxy(34, 15);
    printf("���¶�Ӧ����ѡ���Ѷȡ� ��\b\b\b");
    scanf("%d", &d);
    if (d >= 1 && d <= 4)
    {
        system("cls");
        click2(d);
    }
    else
    {
        choosedif();
    }
}

void click2_barrier()//�ϰ�������ɺ���������
{
    for (i = left_broad; i <= right_broad; i++) //������һ�е��ϰ���
    {
        if (a[i][down_broad + 6] == 3)
        {
            a[i][down_broad + 6] = 0;
            gotoxy(i, down_broad + 6);
            printf(" ");
        }
    }

    for (j = down_broad + 7; j >= up_broad + 1; j--) //ʹ�ϰ�������
    {
        for (i = left_broad; i <= right_broad; i++)
        {
            if (a[i][j] == 3)
            {
                a[i][j] = 0;
                a[i][j + 1] = 3;
                color(12);
                gotoxy(i, j + 1);
                if (a[i][j + 1] == 3)
                {
                    printf("#");
                }
                gotoxy(i, j);
                if (a[i][j] == 0)
                {
                    printf(" ");
                }
            }
        }
    }
    a[rand() % (right_broad - left_broad - 2) + (left_broad + 2)][up_broad + 2] = 3;
}

void ifget()//�ж����������
{

    energy1.x = rand() % (right_broad - left_broad - 2) + left_broad + 2;
    energy1.y = rand() % (down_broad - up_broad - 2) + up_broad + 2;
    a[energy1.x][energy1.y] = 2;
    a[energy1.x + 1][energy1.y] = 2;
    gotoxy(energy1.x, energy1.y);
    color(14);
    printf("*");
    if (a[jam1.x + 1][jam1.y] || a[jam1.x][jam1.y] + T[jam1.x][jam1.y] == 6 || a[jam1.x + 1][jam1.y] + T[jam1.x + 1][jam1.y] == 6 || a[jam1.x][jam1.y + 1] + T[jam1.x][jam1.y + 1] == 6 || a[jam1.x + 1][jam1.y + 1] + T[jam1.x + 1][jam1.y + 1] == 6 || a[jam1.x - 1][jam1.y + 2] + T[jam1.x - 1][jam1.y + 2] == 6 || a[jam1.x][jam1.y + 2] + T[jam1.x][jam1.y + 2] == 6 || a[jam1.x + 1][jam1.y + 2] + T[jam1.x + 1][jam1.y + 2] == 6 || a[jam1.x + 2][jam1.y + 2] + T[jam1.x + 2][jam1.y + 2] == 6)
    {
        count++;
        jam1.score += 100;
        gotoxy(right_broad + 7, up_broad + 7);
        printf("%d", jam1.score);
        forscore();
        if (count % 10 == 0)
        {
            jam1.life++;
            gotoxy(right_broad + 7, up_broad + 13);
            printf("%d", jam1.life);
        }
    }
}

void energy()//������Ĳ���
{
    energy1.x = rand() % (right_broad - left_broad - 1) + left_broad + 1;
    energy1.y = rand() % (down_broad - up_broad - 1) + up_broad + 1;
    a[energy1.x][energy1.y] = 2;
    a[energy1.x + 1][energy1.y] = 2;
    gotoxy(energy1.x, energy1.y);
    color(14);
    printf("*");
}

void iffail()//�ж�ģʽ2����
{
    if (a[jam1.x][jam1.y] + T[jam1.x][jam1.y] == 7 || a[jam1.x + 1][jam1.y] + T[jam1.x + 1][jam1.y] == 7 || a[jam1.x][jam1.y + 1] + T[jam1.x][jam1.y + 1] == 7 || a[jam1.x + 1][jam1.y + 1] + T[jam1.x + 1][jam1.y + 1] == 7 || a[jam1.x - 1][jam1.y + 2] + T[jam1.x - 1][jam1.y + 2] == 7 || a[jam1.x][jam1.y + 2] + T[jam1.x][jam1.y + 2] == 7 || a[jam1.x + 1][jam1.y + 2] + T[jam1.x + 1][jam1.y + 2] == 7 || a[jam1.x + 2][jam1.y + 2] + T[jam1.x + 2][jam1.y + 2] == 7)
    {
        jam1.life--;
        gotoxy(right_broad + 7, up_broad + 13);
        printf("%d", jam1.life);
    }
    if (jam1.life == 0)
    {
        forscore();
        Game_Failure();
    }
}

int  forscore()
{
    int x;
    x = jam1.score;
    return x;
}

int forscore2()
{
    int x;
    x = plane1.score;
    return x;
}

void Appearance() //��Ϸ��ʼ����
{
    gotoxy(40, 2);
    color(11);
    printf("��  ��  ��  ��  ��  ��  ��  ս  ");

    color(14);
    gotoxy(39, 4);
    printf("��");
    color(12);
    gotoxy(39, 5);
    printf("�|");
    color(3);
    gotoxy(38, 6);
    printf("���");

    color(5);
    gotoxy(55, 4);
    printf("��");
    color(9);
    gotoxy(55, 5);
    printf("�|");
    gotoxy(54, 6);
    color(11);
    printf("���");

    color(13);
    gotoxy(69, 4);
    printf("��");
    color(4);
    gotoxy(69, 5);
    printf("�|");
    color(6);
    gotoxy(68, 6);
    printf("���");
}

void Broad() //����߿�ѡ��
{
    int i;

    flower();
    color(14);
    gotoxy(left_broad, up_broad);
    printf("�X");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, up_broad);
        printf("=");
    }

    for (i = up_broad + 1; i < down_broad + 1; i++)
    {
        gotoxy(left_broad, i);
        printf("��");
    }

    gotoxy(right_broad, up_broad);
    printf("�[");

    for (i = up_broad + 1; i < down_broad + 1; i++)
    {
        gotoxy(right_broad, i);
        printf("��");
    }

    gotoxy(left_broad, down_broad);
    printf("�^");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, down_broad);
        printf("=");
    }

    gotoxy(right_broad, down_broad);
    printf("�a");

    color(12);
    gotoxy(left_broad + 10, up_broad + 3);
    printf("1.��ʼ��Ϸ");

    gotoxy(left_broad + 10, up_broad + 13);
    printf("3.��Ϸ����");

    gotoxy(right_broad - 22, up_broad + 3);
    printf("2.����˵��");

    gotoxy(right_broad - 38, up_broad + 13);
    printf("4.��ʷ��¼");

    gotoxy(right_broad - 22, up_broad + 13);
    printf("5.�˳�");

    color(11);
    gotoxy(left_broad + 15, up_broad + 7);
    printf("�����");

    color(14);
    gotoxy(left_broad + 40, up_broad + 7);
    printf("�ᣪ�⣪");

    color(15);
    gotoxy(left_broad + 18, down_broad - 7);
    printf("�⣪�ᣪ");

    color(6);
    gotoxy(left_broad + 43, down_broad - 7);
    printf("�����");

    color(9);
    gotoxy(left_broad + 27, down_broad + 1);
    printf("����ѡ��٢ڢۢܡ�:��   ��\b\b\b\b");
    scanf("%d", &n);
    if (n >= 1 && n <= 5)
    {
        switch (n)
        {
        case 1:
            system("cls"); //����
            choose();
            break;
        case 2:
            system("cls");
            instruction();
            break;
        case 3:
            system("cls");
            regulation();
            break;
        case 5:
            exit(0);
            break;
        case 4:
            choosedata();
            break;
        }
    }
    else
    {
        Broad();
    }
}

void close()//�˳���Ϸ
{
    exit(0);
}

void regulation() //��Ϸ����
{
    int i;

    system("cls");
    gotoxy(55, 5);
    color(14);
    printf("�� Ϸ �� ��");

    color(4);
    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 6);
        printf("=");
    }

    gotoxy(29, 6);
    printf("�X");

    for (i = 7; i <= 20; i++)
    {
        gotoxy(29, i);
        printf("��");
    }

    gotoxy(29, 20);
    printf("�^");

    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 20);
        printf("=");
    }

    gotoxy(90, 20);
    printf("�a");

    gotoxy(90, 6);
    printf("�[");

    for (i = 7; i < 20; i++)
    {
        gotoxy(90, i);
        printf("��");
    }
    color(11);
    gotoxy(31, 8);
    printf("1.����սģʽ��,����Ҫ���Ʒɻ�,ʹ�ɻ������ܵػ����ϰ���,ÿ��\n");
    gotoxy(31, 9);
    printf("�����һ���ϰ��ﶼ��Ϊ������100����,�ۼ�1500�ֺ��Ѷ�����\n");
    gotoxy(31, 13);
    printf("2.������ģʽ��,�㽫���Ʒɻ�����ϰ���,��ͨ����Դ��������ȡ\n");
    gotoxy(31, 14);
    printf("������,ÿ10�������鶼��Ϊ������һ�ζ��������,ÿ��������Ϊ\n");
    gotoxy(31, 15);
    printf("������100�����,ÿ�ۼ�1000���ֺ���Ļ�ϵ��ϰ������࣬�ٶȼ�\n");
    gotoxy(31, 16);
    printf("�죬�ϰ��ｫ�����������飬���ϰ����������ֵ��1��");
    gotoxy(35, 18);
    printf("���¡�1�������ز˵��� ��\b\b\b");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        system("cls");
        Appearance();
        Broad();
        printf("\b\b");
        break;
    }
}

void instruction() //����˵��
{
    int i;

    system("cls");
    gotoxy(55, 5);
    color(14);
    printf("�� �� ˵ ��");

    color(4);
    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 6);
        printf("=");
    }

    gotoxy(29, 6);
    printf("�X");

    for (i = 7; i <= 20; i++)
    {
        gotoxy(29, i);
        printf("��");
    }

    gotoxy(29, 20);
    printf("�^");

    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 20);
        printf("=");
    }

    gotoxy(90, 20);
    printf("�a");

    gotoxy(90, 6);
    printf("�[");

    for (i = 7; i < 20; i++)
    {
        gotoxy(90, i);
        printf("��");
    }
    color(11);
    gotoxy(31, 8);
    printf("1.�����ͨ�����Ƽ��������������Ʒɴ��ƶ�.");
    gotoxy(31, 13);
    printf("2.�ڲ�ͬģʽ�У�����Ҫ�����ɻ����в�ͬ�ƶ�����ȡ���ߵķ���.");
    gotoxy(35, 18);
    printf("���¡�1�������ز˵��� ��\b\b\b");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        system("cls");
        Appearance();
        Broad();
        printf("\b\b");
        break;
    }
}

void shot()
{
    if (plane1.x != 8)
    {
        for (i = 21; i <= 89; i++)
        {
            if (a[8][i] == 2)
            {
                a[8][i] = 0;
            }
        }
        for (i = 9; i <= 24; i++)
        {
            for (j = 21; j <= 89; j++)
            {
                if (a[i][j] == 2 && a[i - 1][j] != 3)
                {
                    a[i][j] = 0;
                    a[i - 1][j] = 2;
                }
                else if (a[i][j] == 2 && a[i - 1][j] == 3)
                {
                    a[i][j] = a[i - 1][j] = 0;
                    plane1.score += 100;
                    forscore2();
                }
            }
        }
        a[plane1.y - 1][plane1.x] = 2;
        while (plane1.score >= 1500)
        {
            plane1.score -= 1500;
            plane1.level++;
            forscore2();
            if (plane1.level <= 3)
            {
                plane1.speed++;
            }
        }
        color(3);
        gotoxy(102, 9);
        printf("%-4d", plane1.score);
        gotoxy(102, 11);
        printf("%d", plane1.level);
        gotoxy(102, 13);
        printf("%d", plane1.speed);
    }
}

void click1_barrier()
{
    for (i = 21; i <= 89; i++)
    {
        if (a[24][i] == 3)
        {
            a[24][i] = 0;
        }
    }
    for (i = 23; i >= 8; i--)
    {
        for (j = 21; j <= 89; j++)
        {
            if (a[i][j] == 3 && a[i + 1][j] == 2)
            {
                a[i][j] = a[i + 1][j] = 0;
                plane1.score += 100;
                forscore2();
            }
            else if (a[i][j] == 3 && a[i + 1][j] == 0)
            {
                a[i][j] = 0;
                a[i + 1][j] = 3;
            }
            else if (a[i][j] == 3 && a[i + 1][j] == 1)
            {
                Game_Failure2();
            }
        }
    }
    while (plane1.score >= 1500)
    {
        plane1.score -= 1500;
        forscore2();
        plane1.level++;

        if (plane1.level <= 3)
        {
            plane1.speed++;
        }
    }
    color(3);
    gotoxy(102, 9);
    printf("%-4d", plane1.score);
    gotoxy(102, 11);
    printf("%d", plane1.level);
    gotoxy(102, 13);
    printf("%d", plane1.speed);
    a[8][rand() % 68 + 21] = 3;
}

int judge(int x, int y)
{
    if (a[y][x] == 3 || a[y][x + 1] == 3 || a[y + 1][x] == 3 || a[y + 1][x + 1] == 3 || a[y + 2][x - 1] == 3 || a[y + 2][x] == 3 || a[y + 2][x + 1] == 3 || a[y + 2][x + 2] == 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void click1()
{
    memset(a, 0, sizeof(a));    //��ʼ����Ϸ����
    int i;
    char ch;
    int start, stop;
    plane1.flag = 1;     //��ʼ���ɻ�
    plane1.level = 1;
    plane1.score = 0;
    plane1.speed = 1;
    plane1.x = 55;
    plane1.y = 22;
    system("cls");

    color(14);
    gotoxy(left_broad, up_broad);
    printf("�X");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, up_broad);
        printf("=");
    }

    for (i = up_broad + 1; i < down_broad + 1; i++)
    {
        gotoxy(left_broad, i);
        printf("��");
    }

    gotoxy(right_broad, up_broad);
    printf("�[");

    for (i = up_broad + 1; i < down_broad + 1; i++)
    {
        gotoxy(right_broad, i);
        printf("��");
    }

    gotoxy(left_broad, down_broad);
    printf("�^");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, down_broad);
        printf("=");
    }

    gotoxy(right_broad, down_broad);
    printf("�a");

    Appearance();

    color(3);
    gotoxy(95, 17);
    printf("TIPS:");
    gotoxy(95, 19);
    printf("���������ƶ�");
    gotoxy(95, 21);
    printf("�ո����ͣ");
    gotoxy(95, 23);
    printf("ESC:�˳���Ϸ");

    color(3);
    gotoxy(95, 9);
    printf("���֣� %d", plane1.score);
    gotoxy(95, 11);
    printf("�ȼ��� %d", plane1.level);
    gotoxy(95, 13);
    printf("�Ѷȣ� %d", plane1.speed);

    color(5);
    gotoxy(55, 22);
    printf("��");
    color(9);
    gotoxy(55, 23);
    printf("�|");
    color(11);
    gotoxy(54, 24);
    printf("���");

    a[plane1.y + 1][plane1.x] = a[plane1.y + 1][plane1.x + 1] = a[plane1.y][plane1.x] = a[plane1.y][plane1.x + 1] = a[plane1.y + 2][plane1.x - 1] = a[plane1.y + 2][plane1.x] = a[plane1.y + 2][plane1.x + 1] = a[plane1.y + 2][plane1.x + 2] = 1;

    //��������
out1:
    start = clock();
    while (1)
    {
        if (kbhit())
        {
            getch();
            ch = getch();
            switch (ch)
            {
            case 72:   //��
                if (plane1.y > 8)
                {
                    BlankPlane(&plane1);
                    if (judge(plane1.x, plane1.y - 1))
                    {
                        Game_Failure2();
                    }
                    a[plane1.y + 1][plane1.x] = a[plane1.y + 1][plane1.x + 1] = a[plane1.y][plane1.x] = a[plane1.y][plane1.x + 1] = a[plane1.y + 2][plane1.x - 1] = a[plane1.y + 2][plane1.x] = a[plane1.y + 2][plane1.x + 1] = a[plane1.y + 2][plane1.x + 2] = 0;
                    plane1.y--;
                    PrintPlane(&plane1);
                }
                break;
            case 80: //��
                if (plane1.y < 22)
                {
                    BlankPlane(&plane1);
                    if (judge(plane1.x, plane1.y + 1))
                    {
                        Game_Failure2();
                    }
                    a[plane1.y + 1][plane1.x] = a[plane1.y + 1][plane1.x + 1] = a[plane1.y][plane1.x] = a[plane1.y][plane1.x + 1] = a[plane1.y + 2][plane1.x - 1] = a[plane1.y + 2][plane1.x] = a[plane1.y + 2][plane1.x + 1] = a[plane1.y + 2][plane1.x + 2] = 0;
                    plane1.y++;
                    PrintPlane(&plane1);
                }
                break;
            case 75:  //��
                if (plane1.x > 22)
                {
                    BlankPlane(&plane1);
                    if (judge(plane1.x - 1, plane1.y))
                    {
                        Game_Failure2();
                    }
                    a[plane1.y + 1][plane1.x] = a[plane1.y + 1][plane1.x + 1] = a[plane1.y][plane1.x] = a[plane1.y][plane1.x + 1] = a[plane1.y + 2][plane1.x - 1] = a[plane1.y + 2][plane1.x] = a[plane1.y + 2][plane1.x + 1] = a[plane1.y + 2][plane1.x + 2] = 0;
                    plane1.x--;
                    PrintPlane(&plane1);
                }
                break;
            case 77:  //��
                if (plane1.x < 87)
                {
                    BlankPlane(&plane1);
                    if (judge(plane1.x + 1, plane1.y))
                    {
                        Game_Failure2();
                    }
                    a[plane1.y + 1][plane1.x] = a[plane1.y + 1][plane1.x + 1] = a[plane1.y][plane1.x] = a[plane1.y][plane1.x + 1] = a[plane1.y + 2][plane1.x - 1] = a[plane1.y + 2][plane1.x] = a[plane1.y + 2][plane1.x + 1] = a[plane1.y + 2][plane1.x + 2] = 0;
                    plane1.x++;
                    PrintPlane(&plane1);
                }
                break;
            case 27:
            {
                system("cls");
                choose();
                break;
            }
            case 32:
                plane1.flag = 0;
            }
            if (plane1.flag == 0)
            {
                while (1)
                {
                    if (kbhit())
                    {
                        ch = getch();
                        if (ch == 32)
                        {
                            plane1.flag = 1;
                            goto out1;
                        }
                    }
                }
            }
        }
        stop = clock();
        if ((stop - start) > (CLK_TCK / plane1.speed))
        {
            BlankPlane(&plane1);
            shot();
            click1_barrier();
            start = stop;
            a[plane1.y + 1][plane1.x] = a[plane1.y + 1][plane1.x + 1] = a[plane1.y][plane1.x] = a[plane1.y][plane1.x + 1] = a[plane1.y + 2][plane1.x - 1] = a[plane1.y + 2][plane1.x] = a[plane1.y + 2][plane1.x + 1] = a[plane1.y + 2][plane1.x + 2] = 0;
            PrintPlane(&plane1);
        }
    }
}

void choose()
{
    int i;
    int x;
    color(14);
    gotoxy(43, 3);
    printf("��ѡ����Ϸģʽ");

    for (i = 6; i <= 16; i++)
    {
        gotoxy(27, i);
        printf("��");
    }
    for (i = 6; i <= 16; i++)
    {
        gotoxy(70, i);
        printf("��");
    }
    gotoxy(27, 6);
    printf("�X");
    gotoxy(70, 6);
    printf("�[");
    for (i = 28; i <= 69; i++)
    {
        gotoxy(i, 6);
        printf("=");
    }
    gotoxy(27, 16);
    printf("�^");

    gotoxy(70, 16);
    printf("�a");

    for (i = 28; i <= 69; i++)
    {
        gotoxy(i, 16);
        printf("=");
    }
    color(6);
    gotoxy(30, 7);
    printf("1.�� �� �� �� ս �� ð �� ");
    gotoxy(30, 9);
    printf("2.�� �� �� �� �� �� �� ս ");
    gotoxy(30, 11);
    printf("3.�� 3 �� ��");
    gotoxy(30, 13);
    printf("�� ѡ �� �� ��\b\b\b");
    scanf("%d", &x);
    if (x >= 1 && x <= 3)
    {
        switch (x)
        {
        case 1:
            system("cls");
            click1();
            break;
        case 2:
            system("cls");
            choosedif();
            break;
        case 3:
            system("cls");
            Appearance();
            Broad();
        }
    }
    else
    {
        choose();
    }
}

void start()
{
    int  i, j, q, k;

    int n = 118;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        for (q = 1; q <= 2 * i - 1; q++)
        {
            printf("�����");
        }
        printf("\n");
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf(" ");
        }
        k = n - i;
        for (q = 1; q <= 2 * k - 1; q++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void Game_Failure()
{
    memset(a, 0, sizeof(a));
    system("cls");
    color(12);
    printf("                 ********\n");
    printf("               ************\n");
    printf("               ####....#.\n");
    printf("             #..###.....##....\n");
    printf("             ###.......######             #####          ##     #        ####           \n");
    printf("                ...........               #              # #    #        #   #     		\n");
    printf("               ##*#######                 #####          #  #   #        #    #   		\n");
    printf("            ####*******######             #              #    # #        #    #			\n");
    printf("           ...#***.****.*###....          #...#          #     ##        #####	        \n");
    printf("           ....**********##.....                                       					\n");
    printf("           ....****    *****....\n ");
    printf("             ####        ####\n			");
    printf("           ######        ######\n");
    printf("##############################################################              ##################################\n");
    printf("#...#......#.##...#......#.##...#......#.##------------------#              #...#......#.##------------------#\n");
    printf("###########################################------------------#              ###############------------------#\n");
    printf("#..#....#....##..#....#....##..#....#....#####################              #..#....#....#####################\n");
    printf("##########################################    #----------#                  ##############    #----------#\n");
    printf("#.....#......##.....#......##.....#......#    #----------#                  #.....#......#    #----------#\n");
    printf("##########################################    #----------#                  ##############    #----------#\n");
    printf("#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#                  #.#..#....#..#    #----------#\n");
    printf("##########################################    ############                  ##############    ############\n");
    gotoxy(40, 10);
    color(3);
    printf("1.���¿�ʼ��Ϸ 2.������Ϸ 3.�浵����");
    gotoxy(40, 25);
    printf("�� ѡ �� �� ��\b\b\b");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        system("cls");
        choose();
        break;
    case 2:
        exit(0);
    case 3:
        system("cls");
        preserve(forscore());
        exit(0);
    }
}

void Game_Failure2()
{
    memset(a, 0, sizeof(a));
    system("cls");
    color(12);
    printf("                 ********\n");
    printf("               ************\n");
    printf("               ####....#.\n");
    printf("             #..###.....##....\n");
    printf("             ###.......######             #####          ##     #        ####           \n");
    printf("                ...........               #              # #    #        #   #     		\n");
    printf("               ##*#######                 #####          #  #   #        #    #   		\n");
    printf("            ####*******######             #              #    # #        #    #			\n");
    printf("           ...#***.****.*###....          #...#          #     ##        #####	        \n");
    printf("           ....**********##.....                                       					\n");
    printf("           ....****    *****....\n ");
    printf("             ####        ####\n			");
    printf("           ######        ######\n");
    printf("##############################################################              ##################################\n");
    printf("#...#......#.##...#......#.##...#......#.##------------------#              #...#......#.##------------------#\n");
    printf("###########################################------------------#              ###############------------------#\n");
    printf("#..#....#....##..#....#....##..#....#....#####################              #..#....#....#####################\n");
    printf("##########################################    #----------#                  ##############    #----------#\n");
    printf("#.....#......##.....#......##.....#......#    #----------#                  #.....#......#    #----------#\n");
    printf("##########################################    #----------#                  ##############    #----------#\n");
    printf("#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#                  #.#..#....#..#    #----------#\n");
    printf("##########################################    ############                  ##############    ############\n");
    gotoxy(40, 10);
    color(3);
    printf("1.���¿�ʼ��Ϸ 2.������Ϸ 3.�浵����");
    gotoxy(40, 25);
    printf("�� ѡ �� �� ��\b\b\b");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        system("cls");
        choose();
        break;
    case 2:
        exit(0);
    case 3:
        system("cls");
        preserve2(forscore2());
        exit(0);
    }
}

void click2(int p)
{

    int i, flag = 1, start, stop;
    jam1.score = 0;
    jam1.life = 1;
    jam1.x = left_broad + 36;
    jam1.y = down_broad - 10;
    gotoxy(left_broad + 27, up_broad - 1);
    color(14);
    printf("�� �� �� �� �� �� �� ս");

    color(14);
    gotoxy(left_broad, up_broad);
    printf("�X");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, up_broad);
        printf("=");
    }

    for (i = up_broad + 1; i < 7 + down_broad; i++)
    {
        gotoxy(left_broad, i);
        printf("��");
    }

    gotoxy(right_broad, up_broad);
    printf("�[");

    for (i = up_broad + 1; i < 7 + down_broad; i++)
    {
        gotoxy(right_broad, i);
        printf("��");
    }

    gotoxy(left_broad, 7 + down_broad);
    printf("�^");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, 7 + down_broad);
        printf("=");
    }

    gotoxy(right_broad, 7 + down_broad);
    printf("�a");

    color(6);
    gotoxy(right_broad + 10, up_broad + 2);
    printf("�� ʾ �� ��");
    color(7);
    gotoxy(right_broad + 4, up_broad + 4);
    printf("�����������");
    for (i = up_broad + 5; i < up_broad + 20; i++)
    {
        gotoxy(right_broad + 4, i);
        printf("��");
    }
    for (i = up_broad + 5; i < up_broad + 20; i++)
    {
        gotoxy(right_broad + 22, i);
        printf("��");
    }
    gotoxy(right_broad + 4, up_broad + 20);
    printf("�����������");

    for (i = down_broad + 14; i <= down_broad + 15; i++)
    {
        gotoxy(10, i);
        printf(" ");
    }
    color(4);
    gotoxy(right_broad + 6, up_broad + 5);
    printf("�� ��:");
    gotoxy(right_broad + 7, up_broad + 7);
    printf("%d", jam1.score);
    gotoxy(right_broad + 6, up_broad + 11);
    printf("�� �� �� ��:");
    gotoxy(right_broad + 7, up_broad + 13);
    printf("%d", jam1.life);
    gotoxy(right_broad + 6, up_broad + 17);
    printf(" �� Ϸ �� ��:\n");
    gotoxy(right_broad + 7, up_broad + 19);
    if (p == 1)
        printf("�� �� �� ��");
    if (p == 2)
        printf("�� ͨ �� ��");
    if (p == 3)
        printf("�� �� �� ��");
    if (p == 4)
        printf("�� ̬ �� ��");
    color(14);
    gotoxy(right_broad + 13, up_broad + 21);
    printf("Tips");
    gotoxy(right_broad + 4, up_broad + 22);
    printf("E S C:�� �� �� Ϸ ");

    gotoxy(right_broad + 4, up_broad + 23);
    printf("�� �� �� �� ͣ");

    gotoxy(right_broad + 4, up_broad + 24);
    printf("�� �� �� ���ƶ�");

    makejet();

outX:
    start = clock();
    while (flag)
    {

        char ch;
        if (kbhit())
        {
            ch = getch();
            switch (ch)
            {
            case 72:
                if (jam1.y > up_broad + 1)
                {
                    cleanjet();
                    jam1.y--;
                    makejet();
                }
                break;
            case 80:
                if (jam1.y < down_broad + 4)
                {
                    cleanjet();
                    jam1.y++;
                    makejet();
                }
                break;
            case 75:
                if (jam1.x > left_broad + 3)
                {
                    cleanjet();
                    jam1.x--;
                    makejet();
                }
                break;
            case 77:
                if (jam1.x < right_broad - 3)
                {
                    cleanjet(&jam1);
                    jam1.x++;
                    makejet(&jam1);
                }
                break;
            case 27:
            {
                system("cls");
                choose();
                break;
            }
            case 32:
            {
                flag = 0;
            }
            while (flag != 1)
            {
                if (kbhit())
                {
                    char ch;
                    ch = getch();
                    if ((int)ch == 32)
                    {
                        flag = 1;
                        goto outX;
                    }
                }
            }
            }
        }
        stop = clock();
        if ((stop - start) > (CLK_TCK / (3 * d)))
        {
            iffail();
            ifget();
            click2_barrier();
            start = stop;
        }
    }
}

void makejet()
{
    gotoxy(jam1.x - 1, jam1.y + 2);
    printf("���");
    T[jam1.x - 1][jam1.y + 2] = 4;
    T[jam1.x][jam1.y + 2] = 4;
    T[jam1.x + 1][jam1.y + 2] = 4;
    T[jam1.x + 2][jam1.y + 2] = 4;
    gotoxy(jam1.x, jam1.y + 1);
    printf("��");
    T[jam1.x][jam1.y + 1] = 4;
    T[jam1.x + 1][jam1.y + 1] = 4;
    gotoxy(jam1.x, jam1.y);
    printf("��");
    T[jam1.x][jam1.y] = 4;
    T[jam1.x + 1][jam1.y] = 4;
}

void cleanjet()
{
    gotoxy(jam1.x - 1, jam1.y + 2);
    printf("  ");
    T[jam1.x - 1][jam1.y + 2] = 0;

    gotoxy(jam1.x, jam1.y + 2);
    printf(" ");
    T[jam1.x][jam1.y + 2] = 0;

    gotoxy(jam1.x + 1, jam1.y + 2);
    printf(" ");
    T[jam1.x + 1][jam1.y + 2] = 0;

    gotoxy(jam1.x, jam1.y + 1);
    printf(" ");
    T[jam1.x][jam1.y + 1] = 0;

    gotoxy(jam1.x, jam1.y);
    printf(" ");
    T[jam1.x][jam1.y] = 0;
}

void flower()
{
    int i, j, n;
    gotoxy(right_broad + 8, up_broad);
    printf("�z_�{");
    gotoxy(right_broad + 5, up_broad + 1);
    printf("�z_�{��z_�{");
    gotoxy(right_broad + 8, up_broad + 2);
    printf("�z_�{");
    gotoxy(right_broad + 14, up_broad + 2);
    printf("�v");

    for (i = right_broad + 7, j = up_broad + 6, n = 1; n <= 3; n++, i += 2, j++)
    {
        gotoxy(i, j);
        printf("��");
    }

    color(13);
    for (i = right_broad + 16, j = up_broad + 5, n = 1; n <= 3; n++, i += 2, j--)
    {
        gotoxy(i, j);
        printf("��");
    }

    color(14);
    for (i = up_broad + 3; i <= up_broad + 9; i++)
    {
        gotoxy(right_broad + 14, i);
        printf("`|");
    }
    for (i = up_broad + 9; i <= up_broad + 18; i++)
    {
        gotoxy(right_broad + 15, i);
        printf("|�A");
    }
    color(10);
    gotoxy(right_broad + 9, up_broad + 19);
    printf("�ܣܩm�m����");

    color(10);
    gotoxy(right_broad + 7, up_broad + 11);
    printf("�z_�{");
    gotoxy(right_broad + 3, up_broad + 12);
    printf("�z_�{��z_�{");
    gotoxy(right_broad + 6, up_broad + 13);
    printf("�z_�{");

    color(14);
    gotoxy(right_broad + 21, up_broad + 7);
    printf("�z_�{");
    gotoxy(right_broad + 18, up_broad + 8);
    printf("�z_�{��z_�{");
    gotoxy(right_broad + 21, up_broad + 9);
    printf("�z_�{");

    color(12);
    for (j = up_broad + 14, i = right_broad + 17, n = 1; n <= 3; j--, i += 2, n++)
    {
        gotoxy(i, j);
        printf("��");
    }

    color(6);
    for (i = right_broad + 8, j = up_broad + 15, n = 1; n <= 3; n++, j++, i += 2)
    {
        gotoxy(i, j);
        printf("��");
    }

    color(12);
    gotoxy(right_broad + 21, up_broad + 15);
    printf("�z_�{");
    gotoxy(right_broad + 18, up_broad + 16);
    printf("�z_�{��z_�{");
    gotoxy(right_broad + 20, up_broad + 17);
    printf("�z_�{");
}

void preserve2(int t)
{

    gotoxy(40, 2);
    printf("�� �� �� �� �� �� ��\n");

    FILE* X;

    char a[20];

    X = fopen("d://first.txt", "a+");

    scanf("%s", a);

    fputs(a, X);
    fprintf(X, "%c", ':');
    fprintf(X, "%d", t);
    fputs("\n", X);
    fclose(X);
    exit(0);
}

void preserve(int t)
{

    gotoxy(40, 2);
    printf("�� �� �� �� �� �� ��\n");

    FILE* M;

    char a[20];

    M = fopen("d://second.txt", "a+");

    scanf("%s", a);

    fputs(a, M);
    fprintf(M, "%c", ':');
    fprintf(M, "%d", t);
    fputs("\n", M);
    fclose(M);
    exit(0);
}

int main()
{
    start();
    system("cls");
    Appearance();
    Broad();
}
///
