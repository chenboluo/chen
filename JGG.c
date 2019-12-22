#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define left_broad 19
#define right_broad 90
#define up_broad 7
#define down_broad 25

void Appearance();         //游戏开始界面 1


void regulation();         //游戏规则  3


void instruction();        //按键说明  4


void Game_Failure();       //游戏模式结束 5

void choose();             //游戏界面选择 6

void click1();             //游戏模式1 7

void click2();             //游戏模式2 8

void makejet();            //模式2打印飞机  9



void cleanjet();           //模式2清楚飞机痕迹
void flower();             //界面美化
void click1_barrier();     //模式1障碍物
void click2_barrier();     //模式2障碍物
void gotoxy(int x, int y); //移动光标
void ifget();              //生命值加减
void choosedif();          //模式2难度选择
int color(int c);          //颜色选择
int  forscore();           //记录模式2的分数
void preserve();			//保存模式2的信息
int  forscore2();			//记录模式1的分数
void preserve2();			//保存宝石1的信息
void Game_Failure2();		//模式1的结束界面
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
//0为空白
//1为飞机
//2为子弹
//3为障碍物


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
    printf("请选择游戏模式");

    for (i = 6; i <= 16; i++)
    {
        gotoxy(27, i);
        printf("‖");
    }
    for (i = 6; i <= 16; i++)
    {
        gotoxy(70, i);
        printf("‖");
    }
    gotoxy(27, 6);
    printf("╔");
    gotoxy(70, 6);
    printf("╗");
    for (i = 28; i <= 69; i++)
    {
        gotoxy(i, 6);
        printf("=");
    }
    gotoxy(27, 16);
    printf("╚");

    gotoxy(70, 16);
    printf("╝");

    for (i = 28; i <= 69; i++)
    {
        gotoxy(i, 16);
        printf("=");
    }
    color(6);
    gotoxy(30, 7);
    printf("1.金咕咕的战斗冒险的历史纪录 ");
    gotoxy(30, 9);
    printf("2.金咕咕生存挑战的历史纪录");
    gotoxy(30, 11);
    printf("3.按 3 返 回");
    gotoxy(30, 13);
    printf("请 选 择 【 】\b\b\b");
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
    printf("按 1 返 回");
    gotoxy(30, 13);
    printf("请 选 择 【 】\b\b\b");
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
    printf("按 1 返 回");
    gotoxy(30, 13);
    printf("请 选 择 【 】\b\b\b");
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
    printf("▲");
    a[plane1->y][plane1->x] = a[plane1->y][plane1->x + 1] = 1;
    color(9);
    gotoxy(plane1->x, plane1->y + 1);
    printf("▅");
    a[plane1->y + 1][plane1->x] = a[plane1->y + 1][plane1->x + 1] = 1;
    color(11);
    gotoxy(plane1->x - 1, plane1->y + 2);
    printf("★★");

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

void choosedif() //难度选择
{
    system("cls");
    gotoxy(55, 5);
    color(14);
    printf("难 度 选 择");

    color(4);
    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 6);
        printf("=");
    }

    gotoxy(29, 6);
    printf("╔");

    for (i = 7; i <= 20; i++)
    {
        gotoxy(29, i);
        printf("‖");
    }

    gotoxy(29, 20);
    printf("╚");

    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 20);
        printf("=");
    }

    gotoxy(90, 20);
    printf("╝");

    gotoxy(90, 6);
    printf("╗");

    for (i = 7; i < 20; i++)
    {
        gotoxy(90, i);
        printf("‖");
    }
    color(11);
    gotoxy(34, 11);
    printf("1.简单难度  2.普通难度 3.困难难度 4.变态难度");
    gotoxy(34, 14);
    printf("准备好开始冒险了吗？\n");
    gotoxy(34, 15);
    printf("按下对应按键选择难度【 】\b\b\b");
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

void click2_barrier()//障碍物的生成和其他操作
{
    for (i = left_broad; i <= right_broad; i++) //清除最后一行的障碍物
    {
        if (a[i][down_broad + 6] == 3)
        {
            a[i][down_broad + 6] = 0;
            gotoxy(i, down_broad + 6);
            printf(" ");
        }
    }

    for (j = down_broad + 7; j >= up_broad + 1; j--) //使障碍物下落
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

void ifget()//判定获得能量块
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

void energy()//能量块的产生
{
    energy1.x = rand() % (right_broad - left_broad - 1) + left_broad + 1;
    energy1.y = rand() % (down_broad - up_broad - 1) + up_broad + 1;
    a[energy1.x][energy1.y] = 2;
    a[energy1.x + 1][energy1.y] = 2;
    gotoxy(energy1.x, energy1.y);
    color(14);
    printf("*");
}

void iffail()//判定模式2结束
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

void Appearance() //游戏开始界面
{
    gotoxy(40, 2);
    color(11);
    printf("金  咕  咕  的  飞  机  大  战  ");

    color(14);
    gotoxy(39, 4);
    printf("▲");
    color(12);
    gotoxy(39, 5);
    printf("▅");
    color(3);
    gotoxy(38, 6);
    printf("★★");

    color(5);
    gotoxy(55, 4);
    printf("▲");
    color(9);
    gotoxy(55, 5);
    printf("▅");
    gotoxy(54, 6);
    color(11);
    printf("★★");

    color(13);
    gotoxy(69, 4);
    printf("▲");
    color(4);
    gotoxy(69, 5);
    printf("▅");
    color(6);
    gotoxy(68, 6);
    printf("★★");
}

void Broad() //界面边框选项
{
    int i;

    flower();
    color(14);
    gotoxy(left_broad, up_broad);
    printf("╔");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, up_broad);
        printf("=");
    }

    for (i = up_broad + 1; i < down_broad + 1; i++)
    {
        gotoxy(left_broad, i);
        printf("‖");
    }

    gotoxy(right_broad, up_broad);
    printf("╗");

    for (i = up_broad + 1; i < down_broad + 1; i++)
    {
        gotoxy(right_broad, i);
        printf("‖");
    }

    gotoxy(left_broad, down_broad);
    printf("╚");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, down_broad);
        printf("=");
    }

    gotoxy(right_broad, down_broad);
    printf("╝");

    color(12);
    gotoxy(left_broad + 10, up_broad + 3);
    printf("1.开始游戏");

    gotoxy(left_broad + 10, up_broad + 13);
    printf("3.游戏规则");

    gotoxy(right_broad - 22, up_broad + 3);
    printf("2.按键说明");

    gotoxy(right_broad - 38, up_broad + 13);
    printf("4.历史纪录");

    gotoxy(right_broad - 22, up_broad + 13);
    printf("5.退出");

    color(11);
    gotoxy(left_broad + 15, up_broad + 7);
    printf("★☆★☆");

    color(14);
    gotoxy(left_broad + 40, up_broad + 7);
    printf("♂＊♀＊");

    color(15);
    gotoxy(left_broad + 18, down_broad - 7);
    printf("♀＊♂＊");

    color(6);
    gotoxy(left_broad + 43, down_broad - 7);
    printf("★☆★☆");

    color(9);
    gotoxy(left_broad + 27, down_broad + 1);
    printf("【请选择①②③④】:【   】\b\b\b\b");
    scanf("%d", &n);
    if (n >= 1 && n <= 5)
    {
        switch (n)
        {
        case 1:
            system("cls"); //清屏
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

void close()//退出游戏
{
    exit(0);
}

void regulation() //游戏规则
{
    int i;

    system("cls");
    gotoxy(55, 5);
    color(14);
    printf("游 戏 规 则");

    color(4);
    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 6);
        printf("=");
    }

    gotoxy(29, 6);
    printf("╔");

    for (i = 7; i <= 20; i++)
    {
        gotoxy(29, i);
        printf("‖");
    }

    gotoxy(29, 20);
    printf("╚");

    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 20);
        printf("=");
    }

    gotoxy(90, 20);
    printf("╝");

    gotoxy(90, 6);
    printf("╗");

    for (i = 7; i < 20; i++)
    {
        gotoxy(90, i);
        printf("‖");
    }
    color(11);
    gotoxy(31, 8);
    printf("1.在挑战模式中,你需要控制飞机,使飞机尽可能地击中障碍物,每当\n");
    gotoxy(31, 9);
    printf("你击中一个障碍物都会为你增加100积分,累计1500分后难度升级\n");
    gotoxy(31, 13);
    printf("2.在生存模式中,你将控制飞机躲避障碍物,并通过能源核心来获取\n");
    gotoxy(31, 14);
    printf("能量块,每10个能量块都会为你增加一次额外的生命,每个能量块为\n");
    gotoxy(31, 15);
    printf("你增加100点积分,每累计1000积分后屏幕上的障碍物增多，速度加\n");
    gotoxy(31, 16);
    printf("快，障碍物将会吞噬能量块，被障碍物击中生命值减1。");
    gotoxy(35, 18);
    printf("按下【1】键返回菜单【 】\b\b\b");
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

void instruction() //按键说明
{
    int i;

    system("cls");
    gotoxy(55, 5);
    color(14);
    printf("按 键 说 明");

    color(4);
    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 6);
        printf("=");
    }

    gotoxy(29, 6);
    printf("╔");

    for (i = 7; i <= 20; i++)
    {
        gotoxy(29, i);
        printf("‖");
    }

    gotoxy(29, 20);
    printf("╚");

    for (i = 30; i <= 90; i++)
    {
        gotoxy(i, 20);
        printf("=");
    }

    gotoxy(90, 20);
    printf("╝");

    gotoxy(90, 6);
    printf("╗");

    for (i = 7; i < 20; i++)
    {
        gotoxy(90, i);
        printf("‖");
    }
    color(11);
    gotoxy(31, 8);
    printf("1.你可以通过控制键↑↓→←来控制飞船移动.");
    gotoxy(31, 13);
    printf("2.在不同模式中，你需要操作飞机进行不同移动来获取更高的分数.");
    gotoxy(35, 18);
    printf("按下【1】键返回菜单【 】\b\b\b");
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
    memset(a, 0, sizeof(a));    //初始化游戏区域
    int i;
    char ch;
    int start, stop;
    plane1.flag = 1;     //初始化飞机
    plane1.level = 1;
    plane1.score = 0;
    plane1.speed = 1;
    plane1.x = 55;
    plane1.y = 22;
    system("cls");

    color(14);
    gotoxy(left_broad, up_broad);
    printf("╔");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, up_broad);
        printf("=");
    }

    for (i = up_broad + 1; i < down_broad + 1; i++)
    {
        gotoxy(left_broad, i);
        printf("‖");
    }

    gotoxy(right_broad, up_broad);
    printf("╗");

    for (i = up_broad + 1; i < down_broad + 1; i++)
    {
        gotoxy(right_broad, i);
        printf("‖");
    }

    gotoxy(left_broad, down_broad);
    printf("╚");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, down_broad);
        printf("=");
    }

    gotoxy(right_broad, down_broad);
    printf("╝");

    Appearance();

    color(3);
    gotoxy(95, 17);
    printf("TIPS:");
    gotoxy(95, 19);
    printf("↑↓←→移动");
    gotoxy(95, 21);
    printf("空格键暂停");
    gotoxy(95, 23);
    printf("ESC:退出游戏");

    color(3);
    gotoxy(95, 9);
    printf("积分： %d", plane1.score);
    gotoxy(95, 11);
    printf("等级： %d", plane1.level);
    gotoxy(95, 13);
    printf("难度： %d", plane1.speed);

    color(5);
    gotoxy(55, 22);
    printf("▲");
    color(9);
    gotoxy(55, 23);
    printf("▅");
    color(11);
    gotoxy(54, 24);
    printf("★★");

    a[plane1.y + 1][plane1.x] = a[plane1.y + 1][plane1.x + 1] = a[plane1.y][plane1.x] = a[plane1.y][plane1.x + 1] = a[plane1.y + 2][plane1.x - 1] = a[plane1.y + 2][plane1.x] = a[plane1.y + 2][plane1.x + 1] = a[plane1.y + 2][plane1.x + 2] = 1;

    //按键操作
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
            case 72:   //上
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
            case 80: //下
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
            case 75:  //左
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
            case 77:  //右
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
    printf("请选择游戏模式");

    for (i = 6; i <= 16; i++)
    {
        gotoxy(27, i);
        printf("‖");
    }
    for (i = 6; i <= 16; i++)
    {
        gotoxy(70, i);
        printf("‖");
    }
    gotoxy(27, 6);
    printf("╔");
    gotoxy(70, 6);
    printf("╗");
    for (i = 28; i <= 69; i++)
    {
        gotoxy(i, 6);
        printf("=");
    }
    gotoxy(27, 16);
    printf("╚");

    gotoxy(70, 16);
    printf("╝");

    for (i = 28; i <= 69; i++)
    {
        gotoxy(i, 16);
        printf("=");
    }
    color(6);
    gotoxy(30, 7);
    printf("1.金 咕 咕 的 战 斗 冒 险 ");
    gotoxy(30, 9);
    printf("2.金 咕 咕 的 生 存 挑 战 ");
    gotoxy(30, 11);
    printf("3.按 3 返 回");
    gotoxy(30, 13);
    printf("请 选 择 【 】\b\b\b");
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
            printf("☆※★");
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
    printf("1.重新开始游戏 2.结束游戏 3.存档结束");
    gotoxy(40, 25);
    printf("请 选 择 【 】\b\b\b");
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
    printf("1.重新开始游戏 2.结束游戏 3.存档结束");
    gotoxy(40, 25);
    printf("请 选 择 【 】\b\b\b");
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
    printf("金 咕 咕 的 生 存 挑 战");

    color(14);
    gotoxy(left_broad, up_broad);
    printf("╔");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, up_broad);
        printf("=");
    }

    for (i = up_broad + 1; i < 7 + down_broad; i++)
    {
        gotoxy(left_broad, i);
        printf("‖");
    }

    gotoxy(right_broad, up_broad);
    printf("╗");

    for (i = up_broad + 1; i < 7 + down_broad; i++)
    {
        gotoxy(right_broad, i);
        printf("‖");
    }

    gotoxy(left_broad, 7 + down_broad);
    printf("╚");

    for (i = left_broad + 1; i < right_broad + 1; i++)
    {
        gotoxy(i, 7 + down_broad);
        printf("=");
    }

    gotoxy(right_broad, 7 + down_broad);
    printf("╝");

    color(6);
    gotoxy(right_broad + 10, up_broad + 2);
    printf("提 示 面 板");
    color(7);
    gotoxy(right_broad + 4, up_broad + 4);
    printf("☆☆☆☆☆☆☆☆☆☆");
    for (i = up_broad + 5; i < up_broad + 20; i++)
    {
        gotoxy(right_broad + 4, i);
        printf("☆");
    }
    for (i = up_broad + 5; i < up_broad + 20; i++)
    {
        gotoxy(right_broad + 22, i);
        printf("☆");
    }
    gotoxy(right_broad + 4, up_broad + 20);
    printf("☆☆☆☆☆☆☆☆☆☆");

    for (i = down_broad + 14; i <= down_broad + 15; i++)
    {
        gotoxy(10, i);
        printf(" ");
    }
    color(4);
    gotoxy(right_broad + 6, up_broad + 5);
    printf("得 分:");
    gotoxy(right_broad + 7, up_broad + 7);
    printf("%d", jam1.score);
    gotoxy(right_broad + 6, up_broad + 11);
    printf("您 的 生 命:");
    gotoxy(right_broad + 7, up_broad + 13);
    printf("%d", jam1.life);
    gotoxy(right_broad + 6, up_broad + 17);
    printf(" 游 戏 难 度:\n");
    gotoxy(right_broad + 7, up_broad + 19);
    if (p == 1)
        printf("简 单 难 度");
    if (p == 2)
        printf("普 通 难 度");
    if (p == 3)
        printf("困 难 难 度");
    if (p == 4)
        printf("变 态 难 度");
    color(14);
    gotoxy(right_broad + 13, up_broad + 21);
    printf("Tips");
    gotoxy(right_broad + 4, up_broad + 22);
    printf("E S C:退 出 游 戏 ");

    gotoxy(right_broad + 4, up_broad + 23);
    printf("空 格 键 暂 停");

    gotoxy(right_broad + 4, up_broad + 24);
    printf("↑ ↓ ← →移动");

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
    printf("★★");
    T[jam1.x - 1][jam1.y + 2] = 4;
    T[jam1.x][jam1.y + 2] = 4;
    T[jam1.x + 1][jam1.y + 2] = 4;
    T[jam1.x + 2][jam1.y + 2] = 4;
    gotoxy(jam1.x, jam1.y + 1);
    printf("▉");
    T[jam1.x][jam1.y + 1] = 4;
    T[jam1.x + 1][jam1.y + 1] = 4;
    gotoxy(jam1.x, jam1.y);
    printf("▲");
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
    printf("﹝_﹞");
    gotoxy(right_broad + 5, up_broad + 1);
    printf("﹝_﹞★﹝_﹞");
    gotoxy(right_broad + 8, up_broad + 2);
    printf("﹝_﹞");
    gotoxy(right_broad + 14, up_broad + 2);
    printf("╲");

    for (i = right_broad + 7, j = up_broad + 6, n = 1; n <= 3; n++, i += 2, j++)
    {
        gotoxy(i, j);
        printf("☆");
    }

    color(13);
    for (i = right_broad + 16, j = up_broad + 5, n = 1; n <= 3; n++, i += 2, j--)
    {
        gotoxy(i, j);
        printf("☆");
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
        printf("|ˋ");
    }
    color(10);
    gotoxy(right_broad + 9, up_broad + 19);
    printf("＼＼﹎﹎／／");

    color(10);
    gotoxy(right_broad + 7, up_broad + 11);
    printf("﹝_﹞");
    gotoxy(right_broad + 3, up_broad + 12);
    printf("﹝_﹞★﹝_﹞");
    gotoxy(right_broad + 6, up_broad + 13);
    printf("﹝_﹞");

    color(14);
    gotoxy(right_broad + 21, up_broad + 7);
    printf("﹝_﹞");
    gotoxy(right_broad + 18, up_broad + 8);
    printf("﹝_﹞★﹝_﹞");
    gotoxy(right_broad + 21, up_broad + 9);
    printf("﹝_﹞");

    color(12);
    for (j = up_broad + 14, i = right_broad + 17, n = 1; n <= 3; j--, i += 2, n++)
    {
        gotoxy(i, j);
        printf("★");
    }

    color(6);
    for (i = right_broad + 8, j = up_broad + 15, n = 1; n <= 3; n++, j++, i += 2)
    {
        gotoxy(i, j);
        printf("★");
    }

    color(12);
    gotoxy(right_broad + 21, up_broad + 15);
    printf("﹝_﹞");
    gotoxy(right_broad + 18, up_broad + 16);
    printf("﹝_﹞★﹝_﹞");
    gotoxy(right_broad + 20, up_broad + 17);
    printf("﹝_﹞");
}

void preserve2(int t)
{

    gotoxy(40, 2);
    printf("请 输 入 玩 家 姓 名\n");

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
    printf("请 输 入 玩 家 姓 名\n");

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
